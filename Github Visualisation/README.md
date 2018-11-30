# Github Access Visualisation

This program program first asks a user to log in then a user can enter a username to see its repositories. Then a program visualises how many commits has each contributor commited in that repository. This project uses d3 library to visualize that data.

* visualization.py
  The program that containts github access, it extracts the data into a json file.

* server.py
  The program that runs the local server

* index.html
  The html file where the bar chart is created.

# How to run the code:

Firstly, a user needs to execute visulazation.py:
```
python visualization.py
```
After that, a user needs to run the local server:
```
python server.py
```
