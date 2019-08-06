from django.conf import settings
from django.urls import include, path
from . import views

urlpatterns = [
    path(
        '',
        views.IndexView.as_view(),
        name='arduino_index'
    ),

    # ##############################################
    # URLs to Project List of Projects with Arduino
    # ##############################################
    path(
        'control/wifi/led/motor', 
        views.ControlWIFILedMotorView.as_view(), 
        name='arduino_control_wifi_led_motor'
    ),
    path(
        'send/control/led/motor/<str:status>/<str:ip>', 
        views.sendParameterLedMotorView.as_view(), 
        name='arduino_send_control_led_motor'
    ),  
]