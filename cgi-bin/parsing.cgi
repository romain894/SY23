#!/bin/bash

# cat << EOF
# Content−type: text/html
#
# <html><head><title>Bienvenue</title>
# <body>
# EOF
# echo "<h1>Welcome, ${REMOTE_ADDR}</h1>"

# Path to the csv file
FILE="/home/uvs/Public/data/data.csv"
if [ "$REQUEST_METHOD" == "GET" ]
 then
   CHAINE=$QUERY_STRING
   echo -e "\nRequest received.\n"
else
   read CHAINE
fi
# Substitute all ampersands by spaces to prepare for data extraction
LISTE=${CHAINE//&/ }
# Write the header by appending all the fields, separated by comma.
if [[ ! -f $FILE ]]
  then
    echo "No data found. Creating new file" >> output.txt	#Creating a log file
    cat > "$FILE"	#Itinializing the .csv file
    for param in $LISTE
      do
        champ=${param%=*}
        echo -n "$champ," >> "$FILE"	#Extract all the fields from the GET request to make the .csv header.
      done
      echo -e "\n" >> "$FILE"	#Newline 
else
  echo "FILE FOUND." >> output.txt	#Each time a request is received, the log file will register 1 file found.
fi
for param in $LISTE
  do
    # Extracting the part before the equal sign in param
    champ=${param%=*}
    # Extracting the part after the equal sign in param
    valeur=${param#*=}
    # Substitute all plus signs in values by space
    valeur=${valeur//+/ }
    # echo "<p>champ = $champ</br>"
    # echo "valeur = ${valeur}</br></p>"

    # Write the values parsed from GET request into the data.csv file 
    echo -n "$valeur, " >> "$FILE"
  done
  echo -e "\n" >> "$FILE"
# cat << EOF2
# </body></html>
# EOF2
