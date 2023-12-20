#include "mqtt.h"  //include this for mqtt  __
#include "ota.h"        //include this for ota __

-------------------------------
ota.h
-------------------------------
change the ssid and password in file to id and password

run otaSetup() on setup to connect and start ota
run otaloop() in loop to keep connection


-------------------------------
mqtt.h
-------------------------------
change the ssid and password in file to id and password
set mqtt details in the mqtt section
 --make sure each device has a diffent mqtt id


mqttSetup("log",{"testtopic1,"testtopic2"}) 
    --run on setup to connect and start mqtt

    --the fist attribute is for the mqtt log topic
        --when connected a status message will be posted here
    --the second attribute is a array for topics to subscribe

run mqttloop() in loop to keep connection

void MsgReceived(String topic, String payload)
    --this function is to recieve any mqtt messages that arrive