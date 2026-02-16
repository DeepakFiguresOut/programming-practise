from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
import time


s= Service("C:/Users/Admin/Downloads/chromedriver-win64/chromedriver-win64/chromedriver.exe")
driver= webdriver.Chrome(service=s)


with open("webpage.html",'w',encoding="utf-8") as f:
    f.write("")
# collect all the html for web scraping
for page in range(1,20):
    driver.get(f"https://www.ambitionbox.com/list-of-companies?page={page}")
    time.sleep(1)
    driver.execute_script('window.scrollTo(0,document.body.scrollHeight)')
    time.sleep(1)
    html= driver.page_source
    with open("webpage.html",'a',encoding="utf-8") as f:
        f.write(f"{html}\n")

        
# parsing and converting html into useful data (csv using pandas dataframe)
from bs4 import BeautifulSoup
import pandas as pd
import numpy as np

df= pd.DataFrame(columns=["Company_Name","rating_count","interLinking","Highly Rated For","Critically Rated For","reviews_count","jobs_count"])

with open("webpage.html",'r',encoding="utf-8") as f:
    html= f.read()
soup= BeautifulSoup(html,"html.parser")

companyCardcontainer=soup.find_all("div",class_="companyCardWrapper")
container_count= len(companyCardcontainer)
print(container_count)
def parseToInt(text):
    text = text.strip().lower()
    if text.endswith("l"):  # lakh
        return int(float(text[:-1]) * 100000)
    elif text.endswith("k"):  # thousand
        return int(float(text[:-1]) * 1000)
    elif text=="--":
        return np.nan
    else:
        return int(text)

def rating_separator(ratingText):
    if "Critically Rated For" in ratingText:
        organisedRating= ratingText.replace("Highly Rated For","").strip()
        organisedRating= [i.strip() if i else np.nan for i in organisedRating.split("Critically Rated For")]
        return organisedRating
    else:
        organisedRating=ratingText.replace("Highly Rated For","").strip()
        organisedRating=[organisedRating,np.nan]
        return organisedRating

for i in range(container_count):
    print(i)
    name= companyCardcontainer[i].h2.text.strip()
    rating_count= companyCardcontainer[i].find_all('div',class_="rating_text rating_text--md")[0].text.strip()
    interLinking= companyCardcontainer[i].find_all('span',class_="companyCardWrapper__interLinking")[0].text.strip()
    try:
        ratings = companyCardcontainer[i].find_all('div', class_="companyCardWrapper__ratingComparisonWrapper")[0].text
    except Exception:
        ratings = ""
    positiveRating, negativeRating = rating_separator(ratings)

    tertiaryInformation= companyCardcontainer[i].find_all('span',class_="companyCardWrapper__ActionCount")
    reviews_count= parseToInt(tertiaryInformation[0].text)
    jobs_count=parseToInt(tertiaryInformation[3].text)

    df.loc[i]=[name,rating_count,interLinking,positiveRating,negativeRating,reviews_count,jobs_count]

df.to_csv('companydata2.csv')
print(container_count,container_count)