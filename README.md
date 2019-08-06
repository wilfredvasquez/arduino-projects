Projects with Arduino
===================================

This app contain a list to various projects to do with Arduino. The app is build using Django 2 and work with Python 3

First time
===================================

Create a Python virtual environment
-----------------------------------

Here you can see how do it -> https://docs.python.org/3/library/venv.html


Clone de Project
-----------------------------------
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
git init
git clone git@github.com:wilfredvasquez/arduino-projects.git
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Install system's requirements
-----------------------------------

With the virtualenv active run

pip install -r requeriments.txt


Usage
===================================

Run the app
-----------------------------------
* Step 1: Migrate the user table:
~~~~~~~~~~~~~~~~~~~~~~~~~
python manage.py migrate
~~~~~~~~~~~~~~~~~~~~~~~~~

* Step 2: Run the django local server
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
python manage.py runserver 0.0.0.0:8000
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~