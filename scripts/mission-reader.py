import os
from struct import unpack

files = [
    r'C:\applications\Impressions Games\Caesar3\Caesarea.map',
    r'C:\applications\Impressions Games\Caesar3\Carthago.map',
    r'C:\applications\Impressions Games\Caesar3\Corinthus.map',
    r'C:\applications\Impressions Games\Caesar3\Cyrene.map',
    r'C:\applications\Impressions Games\Caesar3\Hierosolyma.map',
    r'C:\applications\Impressions Games\Caesar3\Lindum.map',
    r'C:\applications\Impressions Games\Caesar3\Londinium.map',
    r'C:\applications\Impressions Games\Caesar3\Lugdunum.map',
    r'C:\applications\Impressions Games\Caesar3\Mediolanum.map',
    r'C:\applications\Impressions Games\Caesar3\Tarraco.map',
    r'C:\applications\Impressions Games\Caesar3\Toletum.map',
    r'C:\applications\Impressions Games\Caesar3\Valentia.map'
]

for f in files:
    buffer = open(f, 'rb').read()
    values = unpack('hh', buffer[211688:211692])
    print('{} {}'.format(os.path.basename(f), values))
          
    
