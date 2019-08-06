import json
import requests
from django.shortcuts import render, redirect
from django.views.generic import TemplateView, View
from django.http import JsonResponse
# Create your views here.


class IndexView(TemplateView):
    template_name = 'home/index.html' 


# ###########################################################################
# Views to Project List of Projects with Arduino
class ControlWIFILedMotorView(TemplateView):
    template_name = 'home/control_wifi_led_motor.html' 


class sendParameterLedMotorView(View):

    def get(self, request, *args, **kwargs):
        status = kwargs['status']
        ip = kwargs['ip']
        if not status in ['ON', 'OFF', 'FON', 'FOFF', 'SETIP']:
            response = { 
                'status': 'error',
                'message': 'Bad requests' 
            }
        if status in ['ON', 'OFF']:
            try:
                requests.get('http://'+ip+'/?LED='+status)
                response = { 'status': 'success' }
            except:
                response = { 
                    'status': 'error',
                    'message': 'An error has occurred' 
                }

        elif status in ['FON', 'FOFF']:
            try:
                requests.get('http://'+ip+'/?FAN='+status)
                response = { 'status': 'success' }
            except:
                response = { 
                    'status': 'error',
                    'message': 'An error has occurred' 
                }

        elif status == 'SETIP':
            try:
                set_ip = requests.get('http://'+ip+'/?setIP')
                response = { 'status': 'success' }
            except:
                response = { 
                    'status': 'error',
                    'message': 'Endpoint does not respond' 
                }
        else:
            response = { 'status': 'error', 'message': 'An error has occurred' }

        return JsonResponse(response)
# ###############################################################################