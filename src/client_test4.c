#include "client_config_default.h"
#include "client_highlevel.h"
#include "client_subscriptions.h"
#include "plugin/log_stdout.h"

#include <stdlib.h>
#include <signal.h>




UA_Boolean running = true;

static void stopHandler(int sign) {
    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_CLIENT, "Received Ctrl-C");
    running = 0;
}




static UA_StatusCode
nodeIter(UA_NodeId childId, UA_Boolean isInverse, UA_NodeId referenceTypeId, void *handle) {
    if(isInverse)
        return UA_STATUSCODE_GOOD;
    UA_NodeId *parent = (UA_NodeId *)handle;
    printf("%d, %d --- %d ---> NodeId %d, %d\n",
           parent->namespaceIndex, parent->identifier.numeric,
           referenceTypeId.identifier.numeric, childId.namespaceIndex,
           childId.identifier.numeric);
    return UA_STATUSCODE_GOOD;
}




int main(void) {
    signal(SIGINT, stopHandler); /* catches ctrl-c */

    UA_Client *client = UA_Client_new();
    UA_ClientConfig *cc = UA_Client_getConfig(client);
    UA_ClientConfig_setDefault(cc);

    /* default timeout is 5 seconds. Set it to 1 second here for demo */
    cc->timeout = 1000;

    /* 连接到服务器 */
    /* 若需要匿名连接时，改为: retval = UA_Client_connect(client, "opc.tcp://localhost:4840"); */
    UA_StatusCode retval = UA_Client_connect(client, "opc.tcp://localhost:4840");
    if(retval != UA_STATUSCODE_GOOD) {
        UA_Client_delete(client);
        return EXIT_FAILURE;
    }


    UA_Variant value; 
    UA_Variant_init(&value);


    while(running) {
        /* if already connected, this will return GOOD and do nothing */
        /* if the connection is closed/errored, the connection will be reset and then reconnected */
        /* Alternatively you can also use UA_Client_getState to get the current state */
        UA_StatusCode retval = UA_Client_connect(client, "opc.tcp://localhost:4840");
        if(retval != UA_STATUSCODE_GOOD) {
            UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_CLIENT, "Not connected. Retrying to connect in 1 second");
            /* The connect may timeout after 1 second (see above) or it may fail immediately on network errors */
            /* E.g. name resolution errors or unreachable network. Thus there should be a small sleep here */
            UA_sleep_ms(1000);
            continue;
        }





        /* NodeId of the variable holding the current time */
        const UA_NodeId nodeId =
                UA_NODEID_NUMERIC(0, UA_NS0ID_SERVER_SERVERSTATUS_CURRENTTIME);

        retval = UA_Client_readValueAttribute(client, nodeId, &value);
        if(retval == UA_STATUSCODE_BADCONNECTIONCLOSED) {
            UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_CLIENT,
                         "Connection was closed. Reconnecting ...");
            continue;
        }
        if(retval == UA_STATUSCODE_GOOD &&
           UA_Variant_hasScalarType(&value, &UA_TYPES[UA_TYPES_DATETIME])) {
            UA_DateTime raw_date = *(UA_DateTime *) value.data;
            UA_DateTimeStruct dts = UA_DateTime_toStruct(raw_date);
            UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                        "date is: %02u-%02u-%04u %02u:%02u:%02u.%03u",
                        dts.day, dts.month, dts.year, dts.hour, dts.min, dts.sec, dts.milliSec);
        }
        UA_Variant_clear(&value);
        UA_sleep_ms(1000);
    };

    /* Clean up */
    UA_Variant_clear(&value);
    UA_Client_delete(client); /* Disconnects the client internally */
    return EXIT_SUCCESS;
}


















































