from pathlib import Path
from jinja2 import Template


combos = [
    (
        "ctl",
        "KC_1",
        "S(KC_1)",
    ),
    (
        "ogui",
        "OSYM",
        "OGUI",
    ),
    (
        "oext",
        "KC_BSPC",
        "OEXT",
    ),
    *(
        (
            f"xw_{r}{c}",
            f"XW{r}{c}",
            f"XXW{r}{c}",
        ) for r in range(4) for c in range(6) if r != 3 or c != 0
    )
]

c_content = Path("jason_keys.h.in").read_text()
Path("jason_keys.gen.h").write_text((Template(c_content).render(dict(combos=combos))))
h_content = Path("jason_config.h.in").read_text()
Path("jason_config.gen.h").write_text((Template(h_content).render(dict(combos=combos))))
