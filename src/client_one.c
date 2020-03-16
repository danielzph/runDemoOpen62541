// client.c
#include <stdlib.h>
#include "open62541.h"

int main(void) 
{
    UA_Client *client = UA_Client_new();
    UA_ClientConfig_setDefault(UA_Client_getConfig(client));
    UA_StatusCode retval = UA_Client_connect(client, "opc.tcp://localhost:4840");
    if(retval != UA_STATUSCODE_GOOD) {
        UA_Client_delete(client);
        return (int)retval;
    }
    
    // Variants可以存储scalar values和任何类型的arrays 
    UA_Variant value; 
    UA_Variant_init(&value);
    
    // 变量的Node Id是string类型
    const UA_NodeId nodeId = UA_NODEID_STRING(1, "the.answer");
    
	//使用UA_Client_readValueAttribute()去读取变量值
    retval = UA_Client_readValueAttribute(client, nodeId, &value);

	// 变量的数据类型是UA_Int32，第二个是判断UA_Variant里是否有UA_Int32类型的数据
    if(retval == UA_STATUSCODE_GOOD && UA_Variant_hasScalarType(&value, &UA_TYPES[UA_TYPES_INT32])) 
    {
        UA_Int32 variableValue = *(UA_Int32 *) value.data;
        UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "Variable Value is: %d\n", variableValue);
    }

	// 对server里的变量写入一个新值
    UA_Int32 change = 100;
    UA_Variant newValue;
    UA_Variant_init(&newValue);
	UA_Variant_setScalar(&newValue, &change, &UA_TYPES[UA_TYPES_INT32]);
    retval = UA_Client_writeValueAttribute(client, nodeId, &newValue);
	
	// 重新读取变量值来验证是否写成功
    if (retval == UA_STATUSCODE_GOOD)
    {	
    	retval = UA_Client_readValueAttribute(client, nodeId, &value);
    	if(retval == UA_STATUSCODE_GOOD && UA_Variant_hasScalarType(&value, &UA_TYPES[UA_TYPES_INT32])) 
    	{
        	UA_Int32 variableValue = *(UA_Int32 *) value.data;
        	UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "New Variable Value is: %d\n", variableValue);
    	}
    }	

    // Clean up
    UA_Variant_clear(&value);
    UA_Client_delete(client); // Disconnects the client internally
    
    return EXIT_SUCCESS;
}


