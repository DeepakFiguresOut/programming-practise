# fast_beautifulsoup_parser_no_lxml.py
from bs4 import BeautifulSoup
import pandas as pd
import numpy as np
import re
from tqdm import tqdm
import sys

INPUT_HTML = "webpage.html"   # change path if needed
OUT_CSV = "companydata.csv"

# ---------- helpers ----------
def parse_to_int(txt):
    """Return integer or np.nan. Handles '1.2k','3l','1,234+','--','n/a'."""
    if txt is None:
        return np.nan
    s = str(txt).strip().lower()
    if s in ("", "--", "n/a", "na"):
        return np.nan
    s = s.replace(",", "").replace("+", "").strip()
    m = re.match(r"^([0-9]*\.?[0-9]+)\s*([kl])?$", s)
    if m:
        num = float(m.group(1))
        suf = m.group(2)
        if suf == "k":
            return int(num * 1000)
        if suf == "l":
            return int(num * 100000)
        return int(num)
    digits = re.findall(r"\d+", s)
    return int("".join(digits)) if digits else np.nan

def rating_separator(rating_text):
    """Return (positive, negative) strings (empty string if missing)."""
    if not rating_text:
        return "", ""
    t = " ".join(rating_text.split())
    if "Highly Rated For" in t and "Critically Rated For" in t:
        parts = re.split(r"Highly Rated For|Critically Rated For", t)
        parts = [p.strip() for p in parts if p.strip()]
        if len(parts) >= 2:
            return parts[0], parts[1]
        if len(parts) == 1:
            return parts[0], ""
    elif "Highly Rated For" in t:
        return t.split("Highly Rated For", 1)[1].strip(), ""
    elif "Critically Rated For" in t:
        return "", t.split("Critically Rated For", 1)[1].strip()
    return t, ""

# ---------- load HTML using built-in parser (no lxml) ----------
with open(INPUT_HTML, "r", encoding="utf-8") as f:
    raw = f.read()

soup = BeautifulSoup(raw, "html.parser")   # <-- explicitly using html.parser

cards = soup.select("div.companyCardWrapper")
print(f"Found {len(cards)} companyCardWrapper entries.", file=sys.stderr)

# ---------- parse each card ----------
rows = []
# tqdm is optional; you can replace `tqdm(cards)` with `cards` if you don't want progress bar
for card in tqdm(cards, desc="parsing cards", unit="card"):
    # company name
    name_el = card.select_one("h2")
    name = name_el.get_text(strip=True) if name_el else ""

    # rating_count
    rating_el = card.select_one("div.rating_text.rating_text--md") or card.find("div", class_="rating_text rating_text--md")
    rating_count = rating_el.get_text(strip=True) if rating_el else ""

    # interLinking
    inter_el = card.select_one("span.companyCardWrapper__interLinking")
    interLinking = inter_el.get_text(strip=True) if inter_el else ""

    # rating comparisons
    cmp_el = card.select_one("div.companyCardWrapper__ratingComparisonWrapper")
    cmp_text = cmp_el.get_text(" ", strip=True) if cmp_el else ""
    pos, neg = rating_separator(cmp_text)

    # tertiary counts - robust approach
    tertiary = card.select("span.companyCardWrapper__ActionCount")
    reviews = np.nan
    jobs = np.nan
    if len(tertiary) >= 1:
        reviews = parse_to_int(tertiary[0].get_text(strip=True))
    if tertiary:
        # look for 'job' in text, else fallback to index 3
        found_jobs = False
        for sp in tertiary:
            txt = sp.get_text(" ", strip=True).lower()
            if "job" in txt:
                jobs = parse_to_int(txt)
                found_jobs = True
                break
        if not found_jobs and len(tertiary) > 3:
            jobs = parse_to_int(tertiary[3].get_text(strip=True))

    rows.append({
        "Company_Name": name,
        "rating_count": rating_count,
        "interLinking": interLinking,
        "Highly Rated For": pos,
        "Critically Rated For": neg,
        "reviews_count": reviews,
        "jobs_count": jobs
    })

# ---------- final DataFrame & CSV ----------
df = pd.DataFrame(rows, columns=["Company_Name","rating_count","interLinking",
                                 "Highly Rated For","Critically Rated For",
                                 "reviews_count","jobs_count"])
df.to_csv(OUT_CSV, index=False, encoding="utf-8-sig")
print(f"Wrote {len(df)} rows to {OUT_CSV}", file=sys.stderr)
