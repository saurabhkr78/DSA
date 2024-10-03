import urllib.request, urllib.parse, urllib.error
import json

# Ask for the location input
address = input('Enter location: ')

# Prepare the base URL for the API
serviceurl = 'http://py4e-data.dr-chuck.net/opengeo?'

# Encode the address into the URL parameters
url = serviceurl + urllib.parse.urlencode({'q': address})

# Retrieve the data from the API
print('Retrieving', url)
uh = urllib.request.urlopen(url)
data = uh.read().decode()

# Display the length of the retrieved data
print('Retrieved', len(data), 'characters')

# Load the JSON data
try:
    json_data = json.loads(data)
except:
    json_data = None

# Print the entire JSON structure to understand its format
print(json.dumps(json_data, indent=4))

# Check if the 'results' field is present in the JSON data
if 'results' in json_data and len(json_data['results']) > 0:
    # Try to extract the first 'plus_code'
    plus_code = json_data['results'][0].get('plus_code', {}).get('global_code', None)
    if plus_code:
        print('Plus code:', plus_code)
    else:
        print("Plus code not found in the response.")
else:
    print("No results found in the response.")
