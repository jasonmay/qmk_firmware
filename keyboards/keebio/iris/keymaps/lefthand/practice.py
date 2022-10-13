import json
import random
from collections import defaultdict, Counter
from datetime import date, datetime
from pathlib import Path

from english_words import english_words_set

from prompt_toolkit.shortcuts import ProgressBar
from prompt_toolkit import prompt
import click


@click.command()
@click.option('--quadrigrams', default=0)
@click.option('--trigrams', default=0)
@click.option('--settings', default="0,1")
@click.option('--num-words', default=5)
@click.option('--max-word-len', default=15)
@click.option('--has-letters', default="")
def main(quadrigrams, trigrams, settings, num_words, max_word_len, has_letters):
    print("total english words:", len(english_words_set))

    frogkeys = [
        [
            "fdnig",
            "stheo",
            "cwrau",
        ],
        [
            "jkm'-",
            "ypl.q",
            "xbv,z",
        ],
    ]

    rows_to_practice = set()
    level_accum = [
        (0,1),
        (0,2),
        (0,0),  
        (1,1),
        (1,2),
        (1,0),
        "punctuation",  # 6
        "markdown",
        "python_structures",
        "python_operators",
        "python_snake_case",
        "python_obscure",
    ]
    extras = set()
    for raw_setting in settings.split(","):
        setting = int(raw_setting)
        if type(level_accum[setting]) is tuple:
            rows_to_practice.add(level_accum[setting])
        elif level_accum[setting] == "punctuation":
            extras.add("punct")
        elif level_accum[setting] == "markdown":
            extras.add("md")
        elif level_accum[setting] == "python_structures":
            extras.add("pystruc")
        elif level_accum[setting] == "python_operators":
            extras.add("pyops")
        elif level_accum[setting] == "python_snake_case":
            extras.add("pysnake")
        elif level_accum[setting] == "python_obscure":
            extras.add("pyobscure")
    if extras:
        print(extras)

    exclude = set()

    all_letters = set("abcdefghijklmnopqrstuvwxyz")
    letter_set = set()
    for outer, inner in rows_to_practice:
        letter_set.update(set(frogkeys[outer][inner]) & all_letters)

    print("using letters", letter_set)
    all_practice_words = set()
    practice_words = set()
    letter_lookup = defaultdict(list)

    tris = Counter()
    quads = Counter()
    
    for w in english_words_set:
        if len(set(w.lower()) - letter_set) == 0:
            all_practice_words.add(w.lower())

    wordlist = list(all_practice_words)
    gramwords = list()

    must_letters = set(has_letters.split(","))
    with ProgressBar() as pb:
        for nw in pb(range(len(wordlist))):
            w = wordlist[nw]
            if len(w) > max_word_len:
                continue

            if w in exclude:
                continue
            if len(must_letters - {""}):
                if set(w) & must_letters != must_letters:
                    continue

            practice_words.add(w)

    for w in practice_words:
        if trigrams > 0:
            for n in range(len(w) - 3):
                tris.update([w[n:n+3].lower()])
        if quadrigrams > 0:
            for n in range(len(w) - 4):
                quads.update([w[n:n+4].lower()])

    trihead = [e[0] for e in tris.most_common()[0:trigrams]]
    quadhead = [e[0] for e in quads.most_common()[0:quadrigrams]]

    if trihead:
        print("trigrams:", trihead)
    if quadhead:
        print("quadrigrams:", quadhead)

    for w in practice_words:
        if trigrams or quadrigrams:
            for s in trihead + quadhead:
                if s in w:
                    gramwords.append(w)

    # make 4 out of 5 words tri/quad grams
    gram_ratio = len(practice_words) / len(gramwords)
    word_pool = list(practice_words) + list(gramwords) * int(gram_ratio * 4)

    for w in word_pool:
        for letter in letter_set:
            if set(w.lower()) & {letter}:
                letter_lookup[letter].append(w)

    print("Welcome!")
    letters = list(letter_lookup.keys())
    from math import log as ln
    for l, ws in sorted(letter_lookup.items()):
        print(l * int(ln(len(ws)) // ln(2)))
    wrong = False
    benchmark = None
    while True:
        letter_selection = random.choices(letters, k=num_words)
        words = [
            modify_word(
                random.choice(
                    list(letter_lookup[letter])
                ), extras
            )
            for letter in letter_selection
        ]

        if "pyops" in extras:
            owords = []
            start = True
            for w in words:
                if not start:
                    if random.random() < 0.3:
                        owords.append(random.choice(list("+-=/?:|&*%#<>") * 10 + ["//", "!=", ">=", "<=", "{}", "[]"] * 5 + ["^", "//", "and", "or", "not", "while", "if", "for", "in", "is", "collections", "defaultdict", "list", "dict", "set", "tuple"]))
                start = False
                owords.append(w)
            words = owords
                
        expected = " ".join(words)
        input("READY?")
        print("\n         " + expected)
        wrong = False
        start_ts = datetime.now()
        got = prompt("Type it: ")
        end_ts = datetime.now()
        seconds_precise = (end_ts - start_ts).total_seconds()
        with open("times.txt", "a") as f:    
            f.write(json.dumps(
                {
                    "q": quadrigrams,
                    "t": trigrams,
                    "s": seconds_precise,
                    "r": list(sorted((letter_set))),
                    "n": num_words, 
                    "e": list(sorted(extras)),
                    "l": list(sorted(must_letters)),
                    "m": max_word_len, 
                    "msg": expected,
                    "got": got,
                    "ts": end_ts.isoformat(),
                }
            ) + "\n")
        seconds = int(seconds_precise)

        if got.strip() != expected:
            print("NOPE.", got.strip(), "[VS]", expected)
            wrong = True
        else:
            print("🎉🎉🎉🎉🎉")

        if seconds >= num_words * 100:
            print(f"Time too long!")
        else:
            wpm = 60 * num_words / seconds_precise
            cpm = 60 * len(expected) / seconds_precise
            print(f"[TIME]: {seconds} seconds.")
            print(f"[SPEED]: {wpm:.1f} WPM ({cpm:.1f} CPM).")
        print()
  
def maybe_punct_word(word):
    if random.random() < 0.3:
        word = word[0].upper() + word[1:]
    if random.random() < 0.2:
        word += random.choice("?:;!.")
    return word


def maybe_pystruc_word(word):
    structify_order = list(range(6))
    random.shuffle(structify_order)

    if random.random() < 0.1:
        return f"__{word}__"

    if random.random() < 0.2:
        if random.random() < 0.2:
            word = '"' + word + '\\n"'
        elif random.random() < 0.4:
            word = '"' + word + '"'
        elif random.random() < 0.7:
            word = "'" + word + "'"
        else:
            word = "`" + word + "`"

    if random.random() < 0.1:
        word = f"{word}.sort()"

    for i in structify_order:
        if i == 0:
            if random.random() < 0.1:
                word = f"[{word}]"
        if i == 1:
            if random.random() < 0.1:
                n = random.choice(range(100))
                word = f"{word}[{n}]"
        if i == 2:
            if random.random() < 0.1:
                word = f"({word})"
        if i == 3:
            if random.random() < 0.1:
                word = f"{word}()"
        if i == 4:
            if random.random() < 0.1:
                word = "{" + word + "}"

    
    if random.random() < 0.15:
        word += ","

    if random.random() < 0.1:
        word = "~" + word

    return word


def modify_word(word, extras):
    if "punct" in extras:  # todo: random switch if both used
        word = maybe_punct_word(word)
    else:
        if "pystruc" in extras:
            word = maybe_pystruc_word(word)
    return word


if __name__ == '__main__':
    main()