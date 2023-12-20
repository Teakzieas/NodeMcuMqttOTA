#include "mqtt.h"  //include this for mqtt  <br />
#include "ota.h"        //include this for ota <br />

-------------------------------
ota.h
-------------------------------
change the ssid and password in file to id and password<br />
<br />
otaSetup() on setup to connect and start ota<br />
otaloop() in loop to keep connection<br />


-------------------------------
mqtt.h
-------------------------------
change the ssid and password in file to id and password<br />
set mqtt details in the mqtt section<br />
 --make sure each device has a diffent mqtt id<br />
<br />
mqttSetup("log",{"testtopic1,"testtopic2"}) <br />
    --run on setup to connect and start mqtt

    --the fist attribute is for the mqtt log topic
        --when connected a status message will be posted here
    --the second attribute is a array for topics to subscribe

mqttloop() in loop to keep connection<br />
<br />
void MsgReceived(String topic, String payload)

    --this function is to recieve any mqtt messages that arrive