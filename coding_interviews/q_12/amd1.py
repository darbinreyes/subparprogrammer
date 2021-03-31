"""
Interviewer: Uma

/*

python - https://docs.python.org/3/c-api/dict.html

2 dictionaries / key value

check for keys in common. // Pretty sure python has nice easy way to do this - set like notation - set intersection type of operation

dups = []

// otherwise - resort to the obvious method - iterate of keys of dict1 and for each key in dict2, if there is a match, dups.append(key)

// python makes to iterate everything

for k, v in dict1
    for

return count of matching keys

*/

/*

In python, import http,

How do send the REST body.
json.dumps()

*/

"""

import sys
from restobject import RestObject

# When running remotely connect using the iLO address, iLO account name,
# and password to send https requests
iLO_host = "https://{iLO}"
iLO_account = "admin"
iLO_password = "password"

#Create a REST object
REST_OBJ = RestObject(iLO_host, iLO_account, iLO_password)
instances = REST_OBJ.search_for_type("HpBios.")

for instance in instances:
    response = REST_OBJ.rest_get(instance["href"])
    print response


"""

dict -> JSON -> HTTP

import json

// json.dumps() // I ported a sim // Jansson API.

// Ruby //

"""