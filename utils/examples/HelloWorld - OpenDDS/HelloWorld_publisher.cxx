/* HelloWorld_publisher.cxx

   A publication of data of type HelloWorld

   This file is derived from code automatically generated by the rtiddsgen 
   command:

   rtiddsgen -language C++ -example <arch> HelloWorld.idl

   Example publication of type HelloWorld automatically generated by 
   'rtiddsgen'. To test them follow these steps:

   (1) Compile this file and the example subscription.

   (2) Start the subscription with the command
       objs/<arch>/HelloWorld_subscriber <domain_id> <sample_count>
                
   (3) Start the publication with the command
       objs/<arch>/HelloWorld_publisher <domain_id> <sample_count>

   (4) [Optional] Specify the list of discovery initial peers and 
       multicast receive addresses via an environment variable or a file 
       (in the current working directory) called NDDS_DISCOVERY_PEERS. 
       
   You can run any number of publishers and subscribers programs, and can 
   add and remove them dynamically from the domain.

                                   
   Example:
        
       To run the example application on domain <domain_id>:
                          
       On Unix: 
       
       objs/<arch>/HelloWorld_publisher <domain_id> o
       objs/<arch>/HelloWorld_subscriber <domain_id> 
                            
       On Windows:
       
       objs\<arch>\HelloWorld_publisher <domain_id>  
       objs\<arch>\HelloWorld_subscriber <domain_id>    

       
modification history
------------ -------       
*/

#include <stdio.h>
#include <stdlib.h>
#ifdef RTI_VX653
#include <vThreadsData.h>
#endif
#include "dds/DdsDcpsC.h"
#include "dds/DdsDcpsInfrastructureC.h"
#include "dds/DCPS/Service_Participant.h"
#include "HelloWorldTypeSupportImpl.h"

using namespace OpenDDS::DCPS;

/* Delete all entities */
static int publisher_shutdown(
    DDS::DomainParticipant *participant)
{
    DDS::ReturnCode_t retcode;
    int status = 0;

    if (participant != NULL) {
        retcode = participant->delete_contained_entities();
        if (retcode != DDS::RETCODE_OK) {
            printf("delete_contained_entities error %d\n", retcode);
            status = -1;
        }

        retcode = TheParticipantFactory->delete_participant(participant);
        if (retcode != DDS::RETCODE_OK) {
            printf("delete_participant error %d\n", retcode);
            status = -1;
        }
    }

    /* RTI Connext provides finalize_instance() method on
       domain participant factory for people who want to release memory used
       by the participant factory. Uncomment the following block of code for
       clean destruction of the singleton. */
/*
    retcode = DDSDomainParticipantFactory::finalize_instance();
    if (retcode != DDS_RETCODE_OK) {
        printf("finalize_instance error %d\n", retcode);
        status = -1;
    }
*/

    return status;
}

extern "C" int publisher_main(int domainId, int sample_count, int argc, char *argv[])
{
    DDS::DomainParticipant *participant = NULL;
    DDS::Publisher *publisher = NULL;
    DDS::Topic *topic = NULL;
    DDS::DataWriter *writer = NULL;
    HelloWorldDataWriter * HelloWorld_writer = NULL;
    HelloWorld *instance = NULL;
    DDS::ReturnCode_t retcode;
    DDS::InstanceHandle_t instance_handle = DDS::HANDLE_NIL;
    const char *type_name = NULL;
    int count = 0;  
    int send_period = 4000;

    TheParticipantFactoryWithArgs(argc, argv);

    /* To customize participant QoS, use 
       the configuration file USER_QOS_PROFILES.xml */
    DDS::DomainParticipantQos pQos;
    TheParticipantFactory->get_default_participant_qos(pQos);
    participant = TheParticipantFactory->create_participant(
        domainId, pQos, 
        NULL /* listener */, NO_STATUS_MASK);
    if (participant == NULL) {
        printf("create_participant error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* To customize publisher QoS, use 
       the configuration file USER_QOS_PROFILES.xml */
    DDS::PublisherQos puQos;
    participant->get_default_publisher_qos(puQos);
    publisher = participant->create_publisher(
        puQos, NULL /* listener */, NO_STATUS_MASK);
    if (publisher == NULL) {
        printf("create_publisher error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* Register type before creating topic */
    HelloWorldTypeSupportImpl *typesupport = new HelloWorldTypeSupportImpl();
    type_name = strdup("HelloWorld");
    retcode = typesupport->register_type(
        participant, type_name);
    if (retcode != DDS::RETCODE_OK) {
        printf("register_type error %d\n", retcode);
        publisher_shutdown(participant);
        return -1;
    }

    /* To customize topic QoS, use 
       the configuration file USER_QOS_PROFILES.xml */
    DDS::TopicQos tQos;
    participant->get_default_topic_qos(tQos);
    topic = participant->create_topic(
        "Example HelloWorld",
        type_name, tQos, NULL /* listener */,
        NO_STATUS_MASK);
    if (topic == NULL) {
        printf("create_topic error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* To customize data writer QoS, use 
       the configuration file USER_QOS_PROFILES.xml */
    DDS::DataWriterQos wQos;
    publisher->get_default_datawriter_qos(wQos);
    writer = publisher->create_datawriter(
        topic, wQos, NULL /* listener */,
        NO_STATUS_MASK);
    if (writer == NULL) {
        printf("create_datawriter error\n");
        publisher_shutdown(participant);
        return -1;
    }
    HelloWorld_writer = HelloWorldDataWriter::_narrow(writer);
    if (HelloWorld_writer == NULL) {
        printf("DataWriter narrow error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* Create data sample for writing */

    instance = new HelloWorld();
    
    if (instance == NULL) {
        printf("HelloWorldTypeSupport::create_data error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* For a data type that has a key, if the same instance is going to be
       written multiple times, initialize the key here
       and register the keyed instance prior to writing */
/*
    instance_handle = HelloWorld_writer->register_instance(*instance);
*/
    char buffer[50];

    /* Main loop */
    for (count=0; (sample_count == 0) || (count < sample_count); ++count) {

        printf("Writing HelloWorld, count %d\n", count);

        /* Modify the data to be sent here */
        instance->counter = count;
        _snprintf(buffer, 50, "HelloWorld %d", count);
        instance->message = CORBA::string_dup(buffer);
        

        retcode = HelloWorld_writer->write(*instance, instance_handle);
        if (retcode != DDS::RETCODE_OK) {
            printf("write error %d\n", retcode);
        }

        Sleep(send_period);
    }
/*
    retcode = HelloWorld_writer->unregister_instance(
        *instance, instance_handle);
    if (retcode != DDS_RETCODE_OK) {
        printf("unregister instance error %d\n", retcode);
    }
*/

    /* Delete all entities */
    return publisher_shutdown(participant);
}

#if defined(RTI_WINCE)
int wmain(int argc, wchar_t** argv)
{
    int domainId = 0;
    int sample_count = 0; /* infinite loop */ 
    
    if (argc >= 2) {
        domainId = _wtoi(argv[1]);
    }
    if (argc >= 3) {
        sample_count = _wtoi(argv[2]);
    }

     /* Uncomment this to turn on additional logging
    NDDSConfigLogger::get_instance()->
        set_verbosity_by_category(NDDS_CONFIG_LOG_CATEGORY_API, 
                                  NDDS_CONFIG_LOG_VERBOSITY_STATUS_ALL);
    */
    
    return publisher_main(domainId, sample_count);
}
 
#elif !(defined(RTI_VXWORKS) && !defined(__RTP__)) && !defined(RTI_PSOS)
int main(int argc, char *argv[])
{
    int domainId = 0;
    int sample_count = 0; /* infinite loop */

    /* Uncomment this to turn on additional logging
    NDDSConfigLogger::get_instance()->
        set_verbosity_by_category(NDDS_CONFIG_LOG_CATEGORY_API, 
                                  NDDS_CONFIG_LOG_VERBOSITY_STATUS_ALL);
    */
    
    return publisher_main(domainId, sample_count, argc, argv);
}
#endif

