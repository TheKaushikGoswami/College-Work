import requests
import json
import os
from dotenv import load_dotenv

load_dotenv()
city = input("Enter Location: ")
url = f"http://api.weatherapi.com/v1/current.json"

params = {
    "key": os.getenv("API_KEY"),
    "q": city
}

response = requests.get(url, params=params)
data = json.loads(response.text)
print(f"\nCity: {data['location']['name']}")
print(f"Region: {data['location']['region']}")
print(f"Country: {data['location']['country']}")
print(f"Temperature: {data['current']['temp_c']}°C")
print(f"Condition: {data['current']['condition']['text']}")
print(f"Wind Speed: {data['current']['wind_kph']} km/h")
print(f"Pressure: {data['current']['pressure_mb']} mb")
print(f"Humidity: {data['current']['humidity']}%")
print(f"Feels Like: {data['current']['feelslike_c']}°C")


