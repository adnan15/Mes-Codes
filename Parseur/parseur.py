from pprint import pprint

import json
import os
path="../Json/"
dico={}
for f in os.listdir(path):

	json_data=open(path+f)
	data = json.load(json_data)

	print '\n'
	#piece=data["room"]
	#print piece
	#print (json.dumps(data, indent=4))[5]
	L=[]
	L.append(data["datatype"])
	L.append(data["value"])
	if dico.has_key(data["room"]):
		dico[data["room"]].append(data["datatype"])
		dico[data["room"]].append(data["value"])
	else:
		dico[data["room"]]=L

	print dico
	json_data.close()



#json_data=open('JsonFileExample')        # ouvrir le fichier json
#print type(json_data), json_data

              # Charger le fichier json
#print type(data)
#print data["chimie"]
#print(data)

#typeData=data["typeData"]

#if typeData == "brightness":
#	lumiere=data["value"]

#if lumiere < seuil && presence == 1:
#	value=1
