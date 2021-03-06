
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from Sequences.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/


#include <string.h>

#ifdef __cplusplus
#ifndef ndds_cpp_h
  #include "ndds/ndds_cpp.h"
#endif
#else
#ifndef ndds_c_h
  #include "ndds/ndds_c.h"
#endif
#endif

#ifndef osapi_type_h
  #include "osapi/osapi_type.h"
#endif
#ifndef osapi_heap_h
  #include "osapi/osapi_heap.h"
#endif

#ifndef osapi_utility_h
  #include "osapi/osapi_utility.h"
#endif

#ifndef cdr_type_h
  #include "cdr/cdr_type.h"
#endif

#ifndef cdr_encapsulation_h
  #include "cdr/cdr_encapsulation.h"
#endif

#ifndef cdr_stream_h
  #include "cdr/cdr_stream.h"
#endif

#ifndef pres_typePlugin_h
  #include "pres/pres_typePlugin.h"
#endif



#ifndef SequencesPlugin_h
#include "SequencesPlugin.h"
#endif


/* --------------------------------------------------------------------------------------
 *  Type Inside
 * -------------------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */


Inside *
InsidePluginSupport_create_data_ex(RTIBool allocate_pointers){
    Inside *sample = NULL;

    RTIOsapiHeap_allocateStructure(
        &sample, Inside);

    if(sample != NULL) {
        if (!Inside_initialize_ex(sample,allocate_pointers)) {
            RTIOsapiHeap_freeStructure(&sample);
            return NULL;
        }
    }
    return sample; 
}


Inside *
InsidePluginSupport_create_data()
{
    return InsidePluginSupport_create_data_ex(RTI_TRUE);
}


void 
InsidePluginSupport_destroy_data_ex(
    Inside *sample,RTIBool deallocate_pointers) {

    Inside_finalize_ex(sample,deallocate_pointers);

    RTIOsapiHeap_freeStructure(sample);
}


void 
InsidePluginSupport_destroy_data(
    Inside *sample) {

    InsidePluginSupport_destroy_data_ex(sample,RTI_TRUE);

}


RTIBool 
InsidePluginSupport_copy_data(
    Inside *dst,
    const Inside *src)
{
    return Inside_copy(dst,src);
}


void 
InsidePluginSupport_print_data(
    const Inside *sample,
    const char *desc,
    unsigned int indent_level)
{


    RTICdrType_printIndent(indent_level);

    if (desc != NULL) {
      RTILog_debug("%s:\n", desc);
    } else {
      RTILog_debug("\n");
    }

    if (sample == NULL) {
      RTILog_debug("NULL\n");
      return;
    }


    RTICdrType_printShort(
        &sample->count, "count", indent_level + 1);
            
    if (&sample->seoc == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("seoc: NULL\n");    
    } else {
    
        if (DDS_OctetSeq_get_contiguous_bufferI(&sample->seoc) != NULL) {
            RTICdrType_printArray(
                DDS_OctetSeq_get_contiguous_bufferI(&sample->seoc),
                DDS_OctetSeq_get_length(&sample->seoc),
                RTI_CDR_OCTET_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printOctet,
                "seoc", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_OctetSeq_get_discontiguous_bufferI(&sample->seoc),
                DDS_OctetSeq_get_length(&sample->seoc),
               (RTICdrTypePrintFunction)RTICdrType_printOctet,
               "seoc", indent_level + 1);
        }
    
    }
            
    if (&sample->sesh == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("sesh: NULL\n");    
    } else {
    
        if (DDS_ShortSeq_get_contiguous_bufferI(&sample->sesh) != NULL) {
            RTICdrType_printArray(
                DDS_ShortSeq_get_contiguous_bufferI(&sample->sesh),
                DDS_ShortSeq_get_length(&sample->sesh),
                RTI_CDR_SHORT_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printShort,
                "sesh", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_ShortSeq_get_discontiguous_bufferI(&sample->sesh),
                DDS_ShortSeq_get_length(&sample->sesh),
               (RTICdrTypePrintFunction)RTICdrType_printShort,
               "sesh", indent_level + 1);
        }
    
    }
            
    if (&sample->seush == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("seush: NULL\n");    
    } else {
    
        if (DDS_UnsignedShortSeq_get_contiguous_bufferI(&sample->seush) != NULL) {
            RTICdrType_printArray(
                DDS_UnsignedShortSeq_get_contiguous_bufferI(&sample->seush),
                DDS_UnsignedShortSeq_get_length(&sample->seush),
                RTI_CDR_UNSIGNED_SHORT_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printUnsignedShort,
                "seush", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_UnsignedShortSeq_get_discontiguous_bufferI(&sample->seush),
                DDS_UnsignedShortSeq_get_length(&sample->seush),
               (RTICdrTypePrintFunction)RTICdrType_printUnsignedShort,
               "seush", indent_level + 1);
        }
    
    }
            
    if (&sample->selo == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("selo: NULL\n");    
    } else {
    
        if (DDS_LongSeq_get_contiguous_bufferI(&sample->selo) != NULL) {
            RTICdrType_printArray(
                DDS_LongSeq_get_contiguous_bufferI(&sample->selo),
                DDS_LongSeq_get_length(&sample->selo),
                RTI_CDR_LONG_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printLong,
                "selo", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_LongSeq_get_discontiguous_bufferI(&sample->selo),
                DDS_LongSeq_get_length(&sample->selo),
               (RTICdrTypePrintFunction)RTICdrType_printLong,
               "selo", indent_level + 1);
        }
    
    }
            
    if (&sample->seulo == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("seulo: NULL\n");    
    } else {
    
        if (DDS_UnsignedLongSeq_get_contiguous_bufferI(&sample->seulo) != NULL) {
            RTICdrType_printArray(
                DDS_UnsignedLongSeq_get_contiguous_bufferI(&sample->seulo),
                DDS_UnsignedLongSeq_get_length(&sample->seulo),
                RTI_CDR_UNSIGNED_LONG_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printUnsignedLong,
                "seulo", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_UnsignedLongSeq_get_discontiguous_bufferI(&sample->seulo),
                DDS_UnsignedLongSeq_get_length(&sample->seulo),
               (RTICdrTypePrintFunction)RTICdrType_printUnsignedLong,
               "seulo", indent_level + 1);
        }
    
    }
            
    if (&sample->selolo == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("selolo: NULL\n");    
    } else {
    
        if (DDS_LongLongSeq_get_contiguous_bufferI(&sample->selolo) != NULL) {
            RTICdrType_printArray(
                DDS_LongLongSeq_get_contiguous_bufferI(&sample->selolo),
                DDS_LongLongSeq_get_length(&sample->selolo),
                RTI_CDR_LONG_LONG_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printLongLong,
                "selolo", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_LongLongSeq_get_discontiguous_bufferI(&sample->selolo),
                DDS_LongLongSeq_get_length(&sample->selolo),
               (RTICdrTypePrintFunction)RTICdrType_printLongLong,
               "selolo", indent_level + 1);
        }
    
    }
            
    if (&sample->seulolo == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("seulolo: NULL\n");    
    } else {
    
        if (DDS_UnsignedLongLongSeq_get_contiguous_bufferI(&sample->seulolo) != NULL) {
            RTICdrType_printArray(
                DDS_UnsignedLongLongSeq_get_contiguous_bufferI(&sample->seulolo),
                DDS_UnsignedLongLongSeq_get_length(&sample->seulolo),
                RTI_CDR_UNSIGNED_LONG_LONG_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printUnsignedLongLong,
                "seulolo", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_UnsignedLongLongSeq_get_discontiguous_bufferI(&sample->seulolo),
                DDS_UnsignedLongLongSeq_get_length(&sample->seulolo),
               (RTICdrTypePrintFunction)RTICdrType_printUnsignedLongLong,
               "seulolo", indent_level + 1);
        }
    
    }
            
    if (&sample->sech == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("sech: NULL\n");    
    } else {
    
        if (DDS_CharSeq_get_contiguous_bufferI(&sample->sech) != NULL) {
            RTICdrType_printArray(
                DDS_CharSeq_get_contiguous_bufferI(&sample->sech),
                DDS_CharSeq_get_length(&sample->sech),
                RTI_CDR_CHAR_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printChar,
                "sech", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_CharSeq_get_discontiguous_bufferI(&sample->sech),
                DDS_CharSeq_get_length(&sample->sech),
               (RTICdrTypePrintFunction)RTICdrType_printChar,
               "sech", indent_level + 1);
        }
    
    }
            
    if (&sample->sefl == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("sefl: NULL\n");    
    } else {
    
        if (DDS_FloatSeq_get_contiguous_bufferI(&sample->sefl) != NULL) {
            RTICdrType_printArray(
                DDS_FloatSeq_get_contiguous_bufferI(&sample->sefl),
                DDS_FloatSeq_get_length(&sample->sefl),
                RTI_CDR_FLOAT_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printFloat,
                "sefl", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_FloatSeq_get_discontiguous_bufferI(&sample->sefl),
                DDS_FloatSeq_get_length(&sample->sefl),
               (RTICdrTypePrintFunction)RTICdrType_printFloat,
               "sefl", indent_level + 1);
        }
    
    }
            
    if (&sample->sedl == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("sedl: NULL\n");    
    } else {
    
        if (DDS_DoubleSeq_get_contiguous_bufferI(&sample->sedl) != NULL) {
            RTICdrType_printArray(
                DDS_DoubleSeq_get_contiguous_bufferI(&sample->sedl),
                DDS_DoubleSeq_get_length(&sample->sedl),
                RTI_CDR_DOUBLE_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printDouble,
                "sedl", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_DoubleSeq_get_discontiguous_bufferI(&sample->sedl),
                DDS_DoubleSeq_get_length(&sample->sedl),
               (RTICdrTypePrintFunction)RTICdrType_printDouble,
               "sedl", indent_level + 1);
        }
    
    }
            

}



/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */


PRESTypePluginParticipantData 
InsidePlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *type_code)
{
    return PRESTypePluginDefaultParticipantData_new(participant_info);
}


void 
InsidePlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data)
{
  PRESTypePluginDefaultParticipantData_delete(participant_data);
}


PRESTypePluginEndpointData
InsidePlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *containerPluginContext)
{
    PRESTypePluginEndpointData epd = NULL;

    epd = PRESTypePluginDefaultEndpointData_new(
            participant_data,
            endpoint_info,
            (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
            InsidePluginSupport_create_data,
            (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
            InsidePluginSupport_destroy_data,
            NULL, NULL);
    if (epd == NULL) {
        return NULL;
    }
    
    if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
        if (PRESTypePluginDefaultEndpointData_createWriterPool(
                epd,
                endpoint_info,
                InsidePlugin_get_serialized_sample_max_size(epd, RTI_TRUE, 0),
            (PRESTypePluginGetSerializedSampleSizeFunction)
            InsidePlugin_get_serialized_sample_size,
            epd) == RTI_FALSE) {
            PRESTypePluginDefaultEndpointData_delete(epd);
            return NULL;
        }
    }
    return epd;    
}


void 
InsidePlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{  
    PRESTypePluginDefaultEndpointData_delete(endpoint_data);
}


RTIBool 
InsidePlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    Inside *dst,
    const Inside *src)
{
    return InsidePluginSupport_copy_data(dst,src);
}

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */


RTIBool 
InsidePlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const Inside *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;


  if(serialize_encapsulation) {
    /* Encapsulate sample */
    if (!RTICdrStream_serializeCdrEncapsulationDefault(stream)) {
        return RTI_FALSE;
    }


    position = RTICdrStream_resetAlignment(stream);

  }

  if(serialize_sample) {

    if (!RTICdrStream_serializeShort(
        stream, &sample->count)) {
        return RTI_FALSE;
    }
            
    if (DDS_OctetSeq_get_contiguous_bufferI(&sample->seoc) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_OctetSeq_get_contiguous_bufferI(&sample->seoc),
            DDS_OctetSeq_get_length(&sample->seoc),
            (100),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_OctetSeq_get_discontiguous_bufferI(&sample->seoc),
            DDS_OctetSeq_get_length(&sample->seoc),
            (100),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    if (DDS_ShortSeq_get_contiguous_bufferI(&sample->sesh) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_ShortSeq_get_contiguous_bufferI(&sample->sesh),
            DDS_ShortSeq_get_length(&sample->sesh),
            (100),
            RTI_CDR_SHORT_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_ShortSeq_get_discontiguous_bufferI(&sample->sesh),
            DDS_ShortSeq_get_length(&sample->sesh),
            (100),
            RTI_CDR_SHORT_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    if (DDS_UnsignedShortSeq_get_contiguous_bufferI(&sample->seush) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_UnsignedShortSeq_get_contiguous_bufferI(&sample->seush),
            DDS_UnsignedShortSeq_get_length(&sample->seush),
            (100),
            RTI_CDR_UNSIGNED_SHORT_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_UnsignedShortSeq_get_discontiguous_bufferI(&sample->seush),
            DDS_UnsignedShortSeq_get_length(&sample->seush),
            (100),
            RTI_CDR_UNSIGNED_SHORT_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    if (DDS_LongSeq_get_contiguous_bufferI(&sample->selo) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_LongSeq_get_contiguous_bufferI(&sample->selo),
            DDS_LongSeq_get_length(&sample->selo),
            (100),
            RTI_CDR_LONG_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_LongSeq_get_discontiguous_bufferI(&sample->selo),
            DDS_LongSeq_get_length(&sample->selo),
            (100),
            RTI_CDR_LONG_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    if (DDS_UnsignedLongSeq_get_contiguous_bufferI(&sample->seulo) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_UnsignedLongSeq_get_contiguous_bufferI(&sample->seulo),
            DDS_UnsignedLongSeq_get_length(&sample->seulo),
            (100),
            RTI_CDR_UNSIGNED_LONG_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_UnsignedLongSeq_get_discontiguous_bufferI(&sample->seulo),
            DDS_UnsignedLongSeq_get_length(&sample->seulo),
            (100),
            RTI_CDR_UNSIGNED_LONG_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    if (DDS_LongLongSeq_get_contiguous_bufferI(&sample->selolo) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_LongLongSeq_get_contiguous_bufferI(&sample->selolo),
            DDS_LongLongSeq_get_length(&sample->selolo),
            (100),
            RTI_CDR_LONG_LONG_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_LongLongSeq_get_discontiguous_bufferI(&sample->selolo),
            DDS_LongLongSeq_get_length(&sample->selolo),
            (100),
            RTI_CDR_LONG_LONG_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    if (DDS_UnsignedLongLongSeq_get_contiguous_bufferI(&sample->seulolo) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_UnsignedLongLongSeq_get_contiguous_bufferI(&sample->seulolo),
            DDS_UnsignedLongLongSeq_get_length(&sample->seulolo),
            (100),
            RTI_CDR_UNSIGNED_LONG_LONG_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_UnsignedLongLongSeq_get_discontiguous_bufferI(&sample->seulolo),
            DDS_UnsignedLongLongSeq_get_length(&sample->seulolo),
            (100),
            RTI_CDR_UNSIGNED_LONG_LONG_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    if (DDS_CharSeq_get_contiguous_bufferI(&sample->sech) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_CharSeq_get_contiguous_bufferI(&sample->sech),
            DDS_CharSeq_get_length(&sample->sech),
            (100),
            RTI_CDR_CHAR_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_CharSeq_get_discontiguous_bufferI(&sample->sech),
            DDS_CharSeq_get_length(&sample->sech),
            (100),
            RTI_CDR_CHAR_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    if (DDS_FloatSeq_get_contiguous_bufferI(&sample->sefl) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_FloatSeq_get_contiguous_bufferI(&sample->sefl),
            DDS_FloatSeq_get_length(&sample->sefl),
            (100),
            RTI_CDR_FLOAT_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_FloatSeq_get_discontiguous_bufferI(&sample->sefl),
            DDS_FloatSeq_get_length(&sample->sefl),
            (100),
            RTI_CDR_FLOAT_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    if (DDS_DoubleSeq_get_contiguous_bufferI(&sample->sedl) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_DoubleSeq_get_contiguous_bufferI(&sample->sedl),
            DDS_DoubleSeq_get_length(&sample->sedl),
            (100),
            RTI_CDR_DOUBLE_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_DoubleSeq_get_discontiguous_bufferI(&sample->sedl),
            DDS_DoubleSeq_get_length(&sample->sedl),
            (100),
            RTI_CDR_DOUBLE_TYPE)) {
            return RTI_FALSE;
        }
    }
            
  }


  if(serialize_encapsulation) {
    RTICdrStream_restoreAlignment(stream,position);
  }


  return RTI_TRUE;
}


RTIBool 
InsidePlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    Inside *sample, 
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeCdrEncapsulationAndSetDefault(stream)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }
    
    if(deserialize_sample) {

    if (!RTICdrStream_deserializeShort(
        stream, &sample->count)) {
        return RTI_FALSE;
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (DDS_OctetSeq_get_contiguous_bufferI(&sample->seoc) != NULL) {
            if (!RTICdrStream_deserializePrimitiveSequence(
                stream,
                DDS_OctetSeq_get_contiguous_bufferI(&sample->seoc),
                &sequence_length,
                DDS_OctetSeq_get_maximum(&sample->seoc),
                RTI_CDR_OCTET_TYPE)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializePrimitivePointerSequence(
                stream,
                (void **)DDS_OctetSeq_get_discontiguous_bufferI(&sample->seoc),
                &sequence_length,
                DDS_OctetSeq_get_maximum(&sample->seoc),
                RTI_CDR_OCTET_TYPE)) {
                return RTI_FALSE;
            }
        }
        if (!DDS_OctetSeq_set_length(&sample->seoc, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (DDS_ShortSeq_get_contiguous_bufferI(&sample->sesh) != NULL) {
            if (!RTICdrStream_deserializePrimitiveSequence(
                stream,
                DDS_ShortSeq_get_contiguous_bufferI(&sample->sesh),
                &sequence_length,
                DDS_ShortSeq_get_maximum(&sample->sesh),
                RTI_CDR_SHORT_TYPE)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializePrimitivePointerSequence(
                stream,
                (void **)DDS_ShortSeq_get_discontiguous_bufferI(&sample->sesh),
                &sequence_length,
                DDS_ShortSeq_get_maximum(&sample->sesh),
                RTI_CDR_SHORT_TYPE)) {
                return RTI_FALSE;
            }
        }
        if (!DDS_ShortSeq_set_length(&sample->sesh, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (DDS_UnsignedShortSeq_get_contiguous_bufferI(&sample->seush) != NULL) {
            if (!RTICdrStream_deserializePrimitiveSequence(
                stream,
                DDS_UnsignedShortSeq_get_contiguous_bufferI(&sample->seush),
                &sequence_length,
                DDS_UnsignedShortSeq_get_maximum(&sample->seush),
                RTI_CDR_UNSIGNED_SHORT_TYPE)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializePrimitivePointerSequence(
                stream,
                (void **)DDS_UnsignedShortSeq_get_discontiguous_bufferI(&sample->seush),
                &sequence_length,
                DDS_UnsignedShortSeq_get_maximum(&sample->seush),
                RTI_CDR_UNSIGNED_SHORT_TYPE)) {
                return RTI_FALSE;
            }
        }
        if (!DDS_UnsignedShortSeq_set_length(&sample->seush, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (DDS_LongSeq_get_contiguous_bufferI(&sample->selo) != NULL) {
            if (!RTICdrStream_deserializePrimitiveSequence(
                stream,
                DDS_LongSeq_get_contiguous_bufferI(&sample->selo),
                &sequence_length,
                DDS_LongSeq_get_maximum(&sample->selo),
                RTI_CDR_LONG_TYPE)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializePrimitivePointerSequence(
                stream,
                (void **)DDS_LongSeq_get_discontiguous_bufferI(&sample->selo),
                &sequence_length,
                DDS_LongSeq_get_maximum(&sample->selo),
                RTI_CDR_LONG_TYPE)) {
                return RTI_FALSE;
            }
        }
        if (!DDS_LongSeq_set_length(&sample->selo, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (DDS_UnsignedLongSeq_get_contiguous_bufferI(&sample->seulo) != NULL) {
            if (!RTICdrStream_deserializePrimitiveSequence(
                stream,
                DDS_UnsignedLongSeq_get_contiguous_bufferI(&sample->seulo),
                &sequence_length,
                DDS_UnsignedLongSeq_get_maximum(&sample->seulo),
                RTI_CDR_UNSIGNED_LONG_TYPE)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializePrimitivePointerSequence(
                stream,
                (void **)DDS_UnsignedLongSeq_get_discontiguous_bufferI(&sample->seulo),
                &sequence_length,
                DDS_UnsignedLongSeq_get_maximum(&sample->seulo),
                RTI_CDR_UNSIGNED_LONG_TYPE)) {
                return RTI_FALSE;
            }
        }
        if (!DDS_UnsignedLongSeq_set_length(&sample->seulo, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (DDS_LongLongSeq_get_contiguous_bufferI(&sample->selolo) != NULL) {
            if (!RTICdrStream_deserializePrimitiveSequence(
                stream,
                DDS_LongLongSeq_get_contiguous_bufferI(&sample->selolo),
                &sequence_length,
                DDS_LongLongSeq_get_maximum(&sample->selolo),
                RTI_CDR_LONG_LONG_TYPE)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializePrimitivePointerSequence(
                stream,
                (void **)DDS_LongLongSeq_get_discontiguous_bufferI(&sample->selolo),
                &sequence_length,
                DDS_LongLongSeq_get_maximum(&sample->selolo),
                RTI_CDR_LONG_LONG_TYPE)) {
                return RTI_FALSE;
            }
        }
        if (!DDS_LongLongSeq_set_length(&sample->selolo, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (DDS_UnsignedLongLongSeq_get_contiguous_bufferI(&sample->seulolo) != NULL) {
            if (!RTICdrStream_deserializePrimitiveSequence(
                stream,
                DDS_UnsignedLongLongSeq_get_contiguous_bufferI(&sample->seulolo),
                &sequence_length,
                DDS_UnsignedLongLongSeq_get_maximum(&sample->seulolo),
                RTI_CDR_UNSIGNED_LONG_LONG_TYPE)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializePrimitivePointerSequence(
                stream,
                (void **)DDS_UnsignedLongLongSeq_get_discontiguous_bufferI(&sample->seulolo),
                &sequence_length,
                DDS_UnsignedLongLongSeq_get_maximum(&sample->seulolo),
                RTI_CDR_UNSIGNED_LONG_LONG_TYPE)) {
                return RTI_FALSE;
            }
        }
        if (!DDS_UnsignedLongLongSeq_set_length(&sample->seulolo, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (DDS_CharSeq_get_contiguous_bufferI(&sample->sech) != NULL) {
            if (!RTICdrStream_deserializePrimitiveSequence(
                stream,
                DDS_CharSeq_get_contiguous_bufferI(&sample->sech),
                &sequence_length,
                DDS_CharSeq_get_maximum(&sample->sech),
                RTI_CDR_CHAR_TYPE)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializePrimitivePointerSequence(
                stream,
                (void **)DDS_CharSeq_get_discontiguous_bufferI(&sample->sech),
                &sequence_length,
                DDS_CharSeq_get_maximum(&sample->sech),
                RTI_CDR_CHAR_TYPE)) {
                return RTI_FALSE;
            }
        }
        if (!DDS_CharSeq_set_length(&sample->sech, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (DDS_FloatSeq_get_contiguous_bufferI(&sample->sefl) != NULL) {
            if (!RTICdrStream_deserializePrimitiveSequence(
                stream,
                DDS_FloatSeq_get_contiguous_bufferI(&sample->sefl),
                &sequence_length,
                DDS_FloatSeq_get_maximum(&sample->sefl),
                RTI_CDR_FLOAT_TYPE)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializePrimitivePointerSequence(
                stream,
                (void **)DDS_FloatSeq_get_discontiguous_bufferI(&sample->sefl),
                &sequence_length,
                DDS_FloatSeq_get_maximum(&sample->sefl),
                RTI_CDR_FLOAT_TYPE)) {
                return RTI_FALSE;
            }
        }
        if (!DDS_FloatSeq_set_length(&sample->sefl, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (DDS_DoubleSeq_get_contiguous_bufferI(&sample->sedl) != NULL) {
            if (!RTICdrStream_deserializePrimitiveSequence(
                stream,
                DDS_DoubleSeq_get_contiguous_bufferI(&sample->sedl),
                &sequence_length,
                DDS_DoubleSeq_get_maximum(&sample->sedl),
                RTI_CDR_DOUBLE_TYPE)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializePrimitivePointerSequence(
                stream,
                (void **)DDS_DoubleSeq_get_discontiguous_bufferI(&sample->sedl),
                &sequence_length,
                DDS_DoubleSeq_get_maximum(&sample->sedl),
                RTI_CDR_DOUBLE_TYPE)) {
                return RTI_FALSE;
            }
        }
        if (!DDS_DoubleSeq_set_length(&sample->sedl, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


RTIBool InsidePlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;


    if(skip_encapsulation) {
        if (!RTICdrStream_skipEncapsulation(stream)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (skip_sample) {

    if (!RTICdrStream_skipShort(stream)) {
        return RTI_FALSE;
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (!RTICdrStream_skipPrimitiveSequence(
            stream,
            &sequence_length,
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (!RTICdrStream_skipPrimitiveSequence(
            stream,
            &sequence_length,
            RTI_CDR_SHORT_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (!RTICdrStream_skipPrimitiveSequence(
            stream,
            &sequence_length,
            RTI_CDR_UNSIGNED_SHORT_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (!RTICdrStream_skipPrimitiveSequence(
            stream,
            &sequence_length,
            RTI_CDR_LONG_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (!RTICdrStream_skipPrimitiveSequence(
            stream,
            &sequence_length,
            RTI_CDR_UNSIGNED_LONG_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (!RTICdrStream_skipPrimitiveSequence(
            stream,
            &sequence_length,
            RTI_CDR_LONG_LONG_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (!RTICdrStream_skipPrimitiveSequence(
            stream,
            &sequence_length,
            RTI_CDR_UNSIGNED_LONG_LONG_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (!RTICdrStream_skipPrimitiveSequence(
            stream,
            &sequence_length,
            RTI_CDR_CHAR_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (!RTICdrStream_skipPrimitiveSequence(
            stream,
            &sequence_length,
            RTI_CDR_FLOAT_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (!RTICdrStream_skipPrimitiveSequence(
            stream,
            &sequence_length,
            RTI_CDR_DOUBLE_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    }


    if(skip_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


unsigned int 
InsidePlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;


    if (include_encapsulation) {

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getShortMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, (100), RTI_CDR_OCTET_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, (100), RTI_CDR_SHORT_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, (100), RTI_CDR_UNSIGNED_SHORT_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, (100), RTI_CDR_LONG_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, (100), RTI_CDR_UNSIGNED_LONG_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, (100), RTI_CDR_LONG_LONG_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, (100), RTI_CDR_UNSIGNED_LONG_LONG_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, (100), RTI_CDR_CHAR_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, (100), RTI_CDR_FLOAT_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, (100), RTI_CDR_DOUBLE_TYPE);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


unsigned int 
InsidePlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;


    if (include_encapsulation) {

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getShortMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, 0, RTI_CDR_OCTET_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, 0, RTI_CDR_SHORT_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, 0, RTI_CDR_UNSIGNED_SHORT_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, 0, RTI_CDR_LONG_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, 0, RTI_CDR_UNSIGNED_LONG_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, 0, RTI_CDR_LONG_LONG_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, 0, RTI_CDR_UNSIGNED_LONG_LONG_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, 0, RTI_CDR_CHAR_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, 0, RTI_CDR_FLOAT_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, 0, RTI_CDR_DOUBLE_TYPE);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


/* Returns the size of the sample in its serialized form (in bytes).
 * It can also be an estimation in excess of the real buffer needed 
 * during a call to the serialize() function.
 * The value reported does not have to include the space for the
 * encapsulation flags.
 */
unsigned int
InsidePlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    unsigned int size,
    const void * sample) {
    /* In the default implementation, it consider each sample as big 
     * as the largest sample.
     */
    return InsidePlugin_get_serialized_sample_max_size(
        endpoint_data,
        include_encapsulation,
        size);
}


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */


PRESTypePluginKeyKind 
InsidePlugin_get_key_kind()
{

    return PRES_TYPEPLUGIN_NO_KEY;
     
}


RTIBool 
InsidePlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const Inside *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;


    if(serialize_encapsulation) {
        /* Encapsulate sample */
        if (!RTICdrStream_serializeCdrEncapsulationDefault(stream)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if(serialize_key) {

        if (!InsidePlugin_serialize(
                endpoint_data,
                sample,
                stream,
                RTI_FALSE,RTI_TRUE,
                endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    
    }


    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


RTIBool InsidePlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    Inside *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeCdrEncapsulationAndSetDefault(stream)) {
            return RTI_FALSE;  
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

        if (!InsidePlugin_deserialize(
                endpoint_data, sample, stream,
                RTI_FALSE, RTI_TRUE, 
                endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


unsigned int
InsidePlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    unsigned int current_alignment)
{

    unsigned int encapsulation_size = current_alignment;


    unsigned int initial_alignment = current_alignment;

    if (include_encapsulation) {

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }
        

    current_alignment += InsidePlugin_get_serialized_sample_max_size(
        endpoint_data,RTI_FALSE,current_alignment);
    
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


RTIBool 
InsidePlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    Inside *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;


    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeCdrEncapsulationAndSetDefault(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

        if (!InsidePlugin_deserialize(
            endpoint_data, sample, stream, RTI_FALSE, 
            RTI_TRUE, endpoint_plugin_qos)) {
            return RTI_FALSE;
        }

    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


 

/* ------------------------------------------------------------------------
 * Plug-in Installation Methods
 * ------------------------------------------------------------------------ */
 
struct PRESTypePlugin *InsidePlugin_new() 
{ 
    struct PRESTypePlugin *plugin = NULL;
    const struct PRESTypePluginVersion PLUGIN_VERSION = 
        PRES_TYPE_PLUGIN_VERSION_2_0;

    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);
    if (plugin == NULL) {
       return NULL;
    }

    plugin->version = PLUGIN_VERSION;

    /* set up parent's function pointers */
    plugin->onParticipantAttached =
        (PRESTypePluginOnParticipantAttachedCallback)
        InsidePlugin_on_participant_attached;
    plugin->onParticipantDetached =
        (PRESTypePluginOnParticipantDetachedCallback)
        InsidePlugin_on_participant_detached;
    plugin->onEndpointAttached =
        (PRESTypePluginOnEndpointAttachedCallback)
        InsidePlugin_on_endpoint_attached;
    plugin->onEndpointDetached =
        (PRESTypePluginOnEndpointDetachedCallback)
        InsidePlugin_on_endpoint_detached;

    plugin->copySampleFnc =
        (PRESTypePluginCopySampleFunction)
        InsidePlugin_copy_sample;
    plugin->createSampleFnc =
        (PRESTypePluginCreateSampleFunction)
        InsidePlugin_create_sample;
    plugin->destroySampleFnc =
        (PRESTypePluginDestroySampleFunction)
        InsidePlugin_destroy_sample;

    plugin->serializeFnc =
        (PRESTypePluginSerializeFunction)
        InsidePlugin_serialize;
    plugin->deserializeFnc =
        (PRESTypePluginDeserializeFunction)
        InsidePlugin_deserialize;
    plugin->getSerializedSampleMaxSizeFnc =
        (PRESTypePluginGetSerializedSampleMaxSizeFunction)
        InsidePlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =
        (PRESTypePluginGetSerializedSampleMinSizeFunction)
        InsidePlugin_get_serialized_sample_min_size;

    plugin->getSampleFnc =
        (PRESTypePluginGetSampleFunction)
        InsidePlugin_get_sample;
    plugin->returnSampleFnc =
        (PRESTypePluginReturnSampleFunction)
        InsidePlugin_return_sample;

    plugin->getKeyKindFnc =
        (PRESTypePluginGetKeyKindFunction)
        InsidePlugin_get_key_kind;

 
    /* These functions are only used for keyed types. As this is not a keyed
    type they are all set to NULL
    */
    plugin->serializeKeyFnc = NULL;
    plugin->deserializeKeyFnc = NULL;
    plugin->getKeyFnc = NULL;
    plugin->returnKeyFnc = NULL;
    plugin->instanceToKeyFnc = NULL;
    plugin->keyToInstanceFnc = NULL;
    plugin->getSerializedKeyMaxSizeFnc = NULL;
    plugin->instanceToKeyHashFnc = NULL;
    plugin->serializedSampleToKeyHashFnc = NULL;
    plugin->serializedKeyToKeyHashFnc = NULL;
    
    plugin->typeCode =  (struct RTICdrTypeCode *)Inside_get_typecode();
    
    plugin->languageKind = PRES_TYPEPLUGIN_DDS_TYPE; 

    /* Serialized buffer */
    plugin->getBuffer = 
        (PRESTypePluginGetBufferFunction)
        InsidePlugin_get_buffer;
    plugin->returnBuffer = 
        (PRESTypePluginReturnBufferFunction)
        InsidePlugin_return_buffer;
    plugin->getSerializedSampleSizeFnc =
        (PRESTypePluginGetSerializedSampleSizeFunction)
        InsidePlugin_get_serialized_sample_size;

    plugin->endpointTypeName = InsideTYPENAME;

    return plugin;
}

void
InsidePlugin_delete(struct PRESTypePlugin *plugin)
{
    RTIOsapiHeap_freeStructure(plugin);
} 

/* --------------------------------------------------------------------------------------
 *  Type Sequences
 * -------------------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */


Sequences *
SequencesPluginSupport_create_data_ex(RTIBool allocate_pointers){
    Sequences *sample = NULL;

    RTIOsapiHeap_allocateStructure(
        &sample, Sequences);

    if(sample != NULL) {
        if (!Sequences_initialize_ex(sample,allocate_pointers)) {
            RTIOsapiHeap_freeStructure(&sample);
            return NULL;
        }
    }
    return sample; 
}


Sequences *
SequencesPluginSupport_create_data()
{
    return SequencesPluginSupport_create_data_ex(RTI_TRUE);
}


void 
SequencesPluginSupport_destroy_data_ex(
    Sequences *sample,RTIBool deallocate_pointers) {

    Sequences_finalize_ex(sample,deallocate_pointers);

    RTIOsapiHeap_freeStructure(sample);
}


void 
SequencesPluginSupport_destroy_data(
    Sequences *sample) {

    SequencesPluginSupport_destroy_data_ex(sample,RTI_TRUE);

}


RTIBool 
SequencesPluginSupport_copy_data(
    Sequences *dst,
    const Sequences *src)
{
    return Sequences_copy(dst,src);
}


void 
SequencesPluginSupport_print_data(
    const Sequences *sample,
    const char *desc,
    unsigned int indent_level)
{


    RTICdrType_printIndent(indent_level);

    if (desc != NULL) {
      RTILog_debug("%s:\n", desc);
    } else {
      RTILog_debug("\n");
    }

    if (sample == NULL) {
      RTILog_debug("NULL\n");
      return;
    }


    if (&sample->message==NULL) {
        RTICdrType_printString(
            NULL, "message", indent_level + 1);                
    } else {
        RTICdrType_printString(
            sample->message, "message", indent_level + 1);                
    }
            
    if (&sample->seoc == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("seoc: NULL\n");    
    } else {
    
        if (DDS_OctetSeq_get_contiguous_bufferI(&sample->seoc) != NULL) {
            RTICdrType_printArray(
                DDS_OctetSeq_get_contiguous_bufferI(&sample->seoc),
                DDS_OctetSeq_get_length(&sample->seoc),
                RTI_CDR_OCTET_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printOctet,
                "seoc", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_OctetSeq_get_discontiguous_bufferI(&sample->seoc),
                DDS_OctetSeq_get_length(&sample->seoc),
               (RTICdrTypePrintFunction)RTICdrType_printOctet,
               "seoc", indent_level + 1);
        }
    
    }
            
    if (&sample->sesh == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("sesh: NULL\n");    
    } else {
    
        if (DDS_ShortSeq_get_contiguous_bufferI(&sample->sesh) != NULL) {
            RTICdrType_printArray(
                DDS_ShortSeq_get_contiguous_bufferI(&sample->sesh),
                DDS_ShortSeq_get_length(&sample->sesh),
                RTI_CDR_SHORT_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printShort,
                "sesh", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_ShortSeq_get_discontiguous_bufferI(&sample->sesh),
                DDS_ShortSeq_get_length(&sample->sesh),
               (RTICdrTypePrintFunction)RTICdrType_printShort,
               "sesh", indent_level + 1);
        }
    
    }
            
    if (&sample->seush == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("seush: NULL\n");    
    } else {
    
        if (DDS_UnsignedShortSeq_get_contiguous_bufferI(&sample->seush) != NULL) {
            RTICdrType_printArray(
                DDS_UnsignedShortSeq_get_contiguous_bufferI(&sample->seush),
                DDS_UnsignedShortSeq_get_length(&sample->seush),
                RTI_CDR_UNSIGNED_SHORT_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printUnsignedShort,
                "seush", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_UnsignedShortSeq_get_discontiguous_bufferI(&sample->seush),
                DDS_UnsignedShortSeq_get_length(&sample->seush),
               (RTICdrTypePrintFunction)RTICdrType_printUnsignedShort,
               "seush", indent_level + 1);
        }
    
    }
            
    if (&sample->selo == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("selo: NULL\n");    
    } else {
    
        if (DDS_LongSeq_get_contiguous_bufferI(&sample->selo) != NULL) {
            RTICdrType_printArray(
                DDS_LongSeq_get_contiguous_bufferI(&sample->selo),
                DDS_LongSeq_get_length(&sample->selo),
                RTI_CDR_LONG_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printLong,
                "selo", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_LongSeq_get_discontiguous_bufferI(&sample->selo),
                DDS_LongSeq_get_length(&sample->selo),
               (RTICdrTypePrintFunction)RTICdrType_printLong,
               "selo", indent_level + 1);
        }
    
    }
            
    if (&sample->seulo == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("seulo: NULL\n");    
    } else {
    
        if (DDS_UnsignedLongSeq_get_contiguous_bufferI(&sample->seulo) != NULL) {
            RTICdrType_printArray(
                DDS_UnsignedLongSeq_get_contiguous_bufferI(&sample->seulo),
                DDS_UnsignedLongSeq_get_length(&sample->seulo),
                RTI_CDR_UNSIGNED_LONG_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printUnsignedLong,
                "seulo", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_UnsignedLongSeq_get_discontiguous_bufferI(&sample->seulo),
                DDS_UnsignedLongSeq_get_length(&sample->seulo),
               (RTICdrTypePrintFunction)RTICdrType_printUnsignedLong,
               "seulo", indent_level + 1);
        }
    
    }
            
    if (&sample->selolo == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("selolo: NULL\n");    
    } else {
    
        if (DDS_LongLongSeq_get_contiguous_bufferI(&sample->selolo) != NULL) {
            RTICdrType_printArray(
                DDS_LongLongSeq_get_contiguous_bufferI(&sample->selolo),
                DDS_LongLongSeq_get_length(&sample->selolo),
                RTI_CDR_LONG_LONG_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printLongLong,
                "selolo", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_LongLongSeq_get_discontiguous_bufferI(&sample->selolo),
                DDS_LongLongSeq_get_length(&sample->selolo),
               (RTICdrTypePrintFunction)RTICdrType_printLongLong,
               "selolo", indent_level + 1);
        }
    
    }
            
    if (&sample->seulolo == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("seulolo: NULL\n");    
    } else {
    
        if (DDS_UnsignedLongLongSeq_get_contiguous_bufferI(&sample->seulolo) != NULL) {
            RTICdrType_printArray(
                DDS_UnsignedLongLongSeq_get_contiguous_bufferI(&sample->seulolo),
                DDS_UnsignedLongLongSeq_get_length(&sample->seulolo),
                RTI_CDR_UNSIGNED_LONG_LONG_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printUnsignedLongLong,
                "seulolo", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_UnsignedLongLongSeq_get_discontiguous_bufferI(&sample->seulolo),
                DDS_UnsignedLongLongSeq_get_length(&sample->seulolo),
               (RTICdrTypePrintFunction)RTICdrType_printUnsignedLongLong,
               "seulolo", indent_level + 1);
        }
    
    }
            
    if (&sample->sech == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("sech: NULL\n");    
    } else {
    
        if (DDS_CharSeq_get_contiguous_bufferI(&sample->sech) != NULL) {
            RTICdrType_printArray(
                DDS_CharSeq_get_contiguous_bufferI(&sample->sech),
                DDS_CharSeq_get_length(&sample->sech),
                RTI_CDR_CHAR_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printChar,
                "sech", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_CharSeq_get_discontiguous_bufferI(&sample->sech),
                DDS_CharSeq_get_length(&sample->sech),
               (RTICdrTypePrintFunction)RTICdrType_printChar,
               "sech", indent_level + 1);
        }
    
    }
            
    if (&sample->sefl == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("sefl: NULL\n");    
    } else {
    
        if (DDS_FloatSeq_get_contiguous_bufferI(&sample->sefl) != NULL) {
            RTICdrType_printArray(
                DDS_FloatSeq_get_contiguous_bufferI(&sample->sefl),
                DDS_FloatSeq_get_length(&sample->sefl),
                RTI_CDR_FLOAT_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printFloat,
                "sefl", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_FloatSeq_get_discontiguous_bufferI(&sample->sefl),
                DDS_FloatSeq_get_length(&sample->sefl),
               (RTICdrTypePrintFunction)RTICdrType_printFloat,
               "sefl", indent_level + 1);
        }
    
    }
            
    if (&sample->sedl == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("sedl: NULL\n");    
    } else {
    
        if (DDS_DoubleSeq_get_contiguous_bufferI(&sample->sedl) != NULL) {
            RTICdrType_printArray(
                DDS_DoubleSeq_get_contiguous_bufferI(&sample->sedl),
                DDS_DoubleSeq_get_length(&sample->sedl),
                RTI_CDR_DOUBLE_SIZE,
                (RTICdrTypePrintFunction)RTICdrType_printDouble,
                "sedl", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                DDS_DoubleSeq_get_discontiguous_bufferI(&sample->sedl),
                DDS_DoubleSeq_get_length(&sample->sedl),
               (RTICdrTypePrintFunction)RTICdrType_printDouble,
               "sedl", indent_level + 1);
        }
    
    }
            
    InsidePluginSupport_print_data(
        &sample->ins, "ins", indent_level + 1);
            

}



/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */


PRESTypePluginParticipantData 
SequencesPlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *type_code)
{
    return PRESTypePluginDefaultParticipantData_new(participant_info);
}


void 
SequencesPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data)
{
  PRESTypePluginDefaultParticipantData_delete(participant_data);
}


PRESTypePluginEndpointData
SequencesPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *containerPluginContext)
{
    PRESTypePluginEndpointData epd = NULL;

    epd = PRESTypePluginDefaultEndpointData_new(
            participant_data,
            endpoint_info,
            (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
            SequencesPluginSupport_create_data,
            (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
            SequencesPluginSupport_destroy_data,
            NULL, NULL);
    if (epd == NULL) {
        return NULL;
    }
    
    if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
        if (PRESTypePluginDefaultEndpointData_createWriterPool(
                epd,
                endpoint_info,
                SequencesPlugin_get_serialized_sample_max_size(epd, RTI_TRUE, 0),
            (PRESTypePluginGetSerializedSampleSizeFunction)
            SequencesPlugin_get_serialized_sample_size,
            epd) == RTI_FALSE) {
            PRESTypePluginDefaultEndpointData_delete(epd);
            return NULL;
        }
    }
    return epd;    
}


void 
SequencesPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{  
    PRESTypePluginDefaultEndpointData_delete(endpoint_data);
}


RTIBool 
SequencesPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    Sequences *dst,
    const Sequences *src)
{
    return SequencesPluginSupport_copy_data(dst,src);
}

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */


RTIBool 
SequencesPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const Sequences *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;


  if(serialize_encapsulation) {
    /* Encapsulate sample */
    if (!RTICdrStream_serializeCdrEncapsulationDefault(stream)) {
        return RTI_FALSE;
    }


    position = RTICdrStream_resetAlignment(stream);

  }

  if(serialize_sample) {

    if (sample->message == NULL) {
        return RTI_FALSE;
    }
    if (!RTICdrStream_serializeString(
        stream, sample->message, (255) + 1)) {
        return RTI_FALSE;
    }
            
    if (DDS_OctetSeq_get_contiguous_bufferI(&sample->seoc) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_OctetSeq_get_contiguous_bufferI(&sample->seoc),
            DDS_OctetSeq_get_length(&sample->seoc),
            (100),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_OctetSeq_get_discontiguous_bufferI(&sample->seoc),
            DDS_OctetSeq_get_length(&sample->seoc),
            (100),
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    if (DDS_ShortSeq_get_contiguous_bufferI(&sample->sesh) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_ShortSeq_get_contiguous_bufferI(&sample->sesh),
            DDS_ShortSeq_get_length(&sample->sesh),
            (100),
            RTI_CDR_SHORT_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_ShortSeq_get_discontiguous_bufferI(&sample->sesh),
            DDS_ShortSeq_get_length(&sample->sesh),
            (100),
            RTI_CDR_SHORT_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    if (DDS_UnsignedShortSeq_get_contiguous_bufferI(&sample->seush) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_UnsignedShortSeq_get_contiguous_bufferI(&sample->seush),
            DDS_UnsignedShortSeq_get_length(&sample->seush),
            (100),
            RTI_CDR_UNSIGNED_SHORT_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_UnsignedShortSeq_get_discontiguous_bufferI(&sample->seush),
            DDS_UnsignedShortSeq_get_length(&sample->seush),
            (100),
            RTI_CDR_UNSIGNED_SHORT_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    if (DDS_LongSeq_get_contiguous_bufferI(&sample->selo) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_LongSeq_get_contiguous_bufferI(&sample->selo),
            DDS_LongSeq_get_length(&sample->selo),
            (100),
            RTI_CDR_LONG_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_LongSeq_get_discontiguous_bufferI(&sample->selo),
            DDS_LongSeq_get_length(&sample->selo),
            (100),
            RTI_CDR_LONG_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    if (DDS_UnsignedLongSeq_get_contiguous_bufferI(&sample->seulo) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_UnsignedLongSeq_get_contiguous_bufferI(&sample->seulo),
            DDS_UnsignedLongSeq_get_length(&sample->seulo),
            (100),
            RTI_CDR_UNSIGNED_LONG_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_UnsignedLongSeq_get_discontiguous_bufferI(&sample->seulo),
            DDS_UnsignedLongSeq_get_length(&sample->seulo),
            (100),
            RTI_CDR_UNSIGNED_LONG_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    if (DDS_LongLongSeq_get_contiguous_bufferI(&sample->selolo) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_LongLongSeq_get_contiguous_bufferI(&sample->selolo),
            DDS_LongLongSeq_get_length(&sample->selolo),
            (100),
            RTI_CDR_LONG_LONG_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_LongLongSeq_get_discontiguous_bufferI(&sample->selolo),
            DDS_LongLongSeq_get_length(&sample->selolo),
            (100),
            RTI_CDR_LONG_LONG_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    if (DDS_UnsignedLongLongSeq_get_contiguous_bufferI(&sample->seulolo) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_UnsignedLongLongSeq_get_contiguous_bufferI(&sample->seulolo),
            DDS_UnsignedLongLongSeq_get_length(&sample->seulolo),
            (100),
            RTI_CDR_UNSIGNED_LONG_LONG_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_UnsignedLongLongSeq_get_discontiguous_bufferI(&sample->seulolo),
            DDS_UnsignedLongLongSeq_get_length(&sample->seulolo),
            (100),
            RTI_CDR_UNSIGNED_LONG_LONG_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    if (DDS_CharSeq_get_contiguous_bufferI(&sample->sech) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_CharSeq_get_contiguous_bufferI(&sample->sech),
            DDS_CharSeq_get_length(&sample->sech),
            (100),
            RTI_CDR_CHAR_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_CharSeq_get_discontiguous_bufferI(&sample->sech),
            DDS_CharSeq_get_length(&sample->sech),
            (100),
            RTI_CDR_CHAR_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    if (DDS_FloatSeq_get_contiguous_bufferI(&sample->sefl) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_FloatSeq_get_contiguous_bufferI(&sample->sefl),
            DDS_FloatSeq_get_length(&sample->sefl),
            (100),
            RTI_CDR_FLOAT_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_FloatSeq_get_discontiguous_bufferI(&sample->sefl),
            DDS_FloatSeq_get_length(&sample->sefl),
            (100),
            RTI_CDR_FLOAT_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    if (DDS_DoubleSeq_get_contiguous_bufferI(&sample->sedl) != NULL) {
        if (!RTICdrStream_serializePrimitiveSequence(
            stream,
            DDS_DoubleSeq_get_contiguous_bufferI(&sample->sedl),
            DDS_DoubleSeq_get_length(&sample->sedl),
            (100),
            RTI_CDR_DOUBLE_TYPE)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializePrimitivePointerSequence(
            stream,
            (const void **)DDS_DoubleSeq_get_discontiguous_bufferI(&sample->sedl),
            DDS_DoubleSeq_get_length(&sample->sedl),
            (100),
            RTI_CDR_DOUBLE_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    if (!InsidePlugin_serialize(
            endpoint_data,
            &sample->ins, 
            stream, 
            RTI_FALSE, RTI_TRUE, 
            endpoint_plugin_qos)) {
        return RTI_FALSE;
    }
            
  }


  if(serialize_encapsulation) {
    RTICdrStream_restoreAlignment(stream,position);
  }


  return RTI_TRUE;
}


RTIBool 
SequencesPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    Sequences *sample, 
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeCdrEncapsulationAndSetDefault(stream)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }
    
    if(deserialize_sample) {

    if (!RTICdrStream_deserializeString(
        stream, sample->message, (255) + 1)) {
        return RTI_FALSE;
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (DDS_OctetSeq_get_contiguous_bufferI(&sample->seoc) != NULL) {
            if (!RTICdrStream_deserializePrimitiveSequence(
                stream,
                DDS_OctetSeq_get_contiguous_bufferI(&sample->seoc),
                &sequence_length,
                DDS_OctetSeq_get_maximum(&sample->seoc),
                RTI_CDR_OCTET_TYPE)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializePrimitivePointerSequence(
                stream,
                (void **)DDS_OctetSeq_get_discontiguous_bufferI(&sample->seoc),
                &sequence_length,
                DDS_OctetSeq_get_maximum(&sample->seoc),
                RTI_CDR_OCTET_TYPE)) {
                return RTI_FALSE;
            }
        }
        if (!DDS_OctetSeq_set_length(&sample->seoc, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (DDS_ShortSeq_get_contiguous_bufferI(&sample->sesh) != NULL) {
            if (!RTICdrStream_deserializePrimitiveSequence(
                stream,
                DDS_ShortSeq_get_contiguous_bufferI(&sample->sesh),
                &sequence_length,
                DDS_ShortSeq_get_maximum(&sample->sesh),
                RTI_CDR_SHORT_TYPE)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializePrimitivePointerSequence(
                stream,
                (void **)DDS_ShortSeq_get_discontiguous_bufferI(&sample->sesh),
                &sequence_length,
                DDS_ShortSeq_get_maximum(&sample->sesh),
                RTI_CDR_SHORT_TYPE)) {
                return RTI_FALSE;
            }
        }
        if (!DDS_ShortSeq_set_length(&sample->sesh, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (DDS_UnsignedShortSeq_get_contiguous_bufferI(&sample->seush) != NULL) {
            if (!RTICdrStream_deserializePrimitiveSequence(
                stream,
                DDS_UnsignedShortSeq_get_contiguous_bufferI(&sample->seush),
                &sequence_length,
                DDS_UnsignedShortSeq_get_maximum(&sample->seush),
                RTI_CDR_UNSIGNED_SHORT_TYPE)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializePrimitivePointerSequence(
                stream,
                (void **)DDS_UnsignedShortSeq_get_discontiguous_bufferI(&sample->seush),
                &sequence_length,
                DDS_UnsignedShortSeq_get_maximum(&sample->seush),
                RTI_CDR_UNSIGNED_SHORT_TYPE)) {
                return RTI_FALSE;
            }
        }
        if (!DDS_UnsignedShortSeq_set_length(&sample->seush, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (DDS_LongSeq_get_contiguous_bufferI(&sample->selo) != NULL) {
            if (!RTICdrStream_deserializePrimitiveSequence(
                stream,
                DDS_LongSeq_get_contiguous_bufferI(&sample->selo),
                &sequence_length,
                DDS_LongSeq_get_maximum(&sample->selo),
                RTI_CDR_LONG_TYPE)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializePrimitivePointerSequence(
                stream,
                (void **)DDS_LongSeq_get_discontiguous_bufferI(&sample->selo),
                &sequence_length,
                DDS_LongSeq_get_maximum(&sample->selo),
                RTI_CDR_LONG_TYPE)) {
                return RTI_FALSE;
            }
        }
        if (!DDS_LongSeq_set_length(&sample->selo, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (DDS_UnsignedLongSeq_get_contiguous_bufferI(&sample->seulo) != NULL) {
            if (!RTICdrStream_deserializePrimitiveSequence(
                stream,
                DDS_UnsignedLongSeq_get_contiguous_bufferI(&sample->seulo),
                &sequence_length,
                DDS_UnsignedLongSeq_get_maximum(&sample->seulo),
                RTI_CDR_UNSIGNED_LONG_TYPE)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializePrimitivePointerSequence(
                stream,
                (void **)DDS_UnsignedLongSeq_get_discontiguous_bufferI(&sample->seulo),
                &sequence_length,
                DDS_UnsignedLongSeq_get_maximum(&sample->seulo),
                RTI_CDR_UNSIGNED_LONG_TYPE)) {
                return RTI_FALSE;
            }
        }
        if (!DDS_UnsignedLongSeq_set_length(&sample->seulo, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (DDS_LongLongSeq_get_contiguous_bufferI(&sample->selolo) != NULL) {
            if (!RTICdrStream_deserializePrimitiveSequence(
                stream,
                DDS_LongLongSeq_get_contiguous_bufferI(&sample->selolo),
                &sequence_length,
                DDS_LongLongSeq_get_maximum(&sample->selolo),
                RTI_CDR_LONG_LONG_TYPE)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializePrimitivePointerSequence(
                stream,
                (void **)DDS_LongLongSeq_get_discontiguous_bufferI(&sample->selolo),
                &sequence_length,
                DDS_LongLongSeq_get_maximum(&sample->selolo),
                RTI_CDR_LONG_LONG_TYPE)) {
                return RTI_FALSE;
            }
        }
        if (!DDS_LongLongSeq_set_length(&sample->selolo, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (DDS_UnsignedLongLongSeq_get_contiguous_bufferI(&sample->seulolo) != NULL) {
            if (!RTICdrStream_deserializePrimitiveSequence(
                stream,
                DDS_UnsignedLongLongSeq_get_contiguous_bufferI(&sample->seulolo),
                &sequence_length,
                DDS_UnsignedLongLongSeq_get_maximum(&sample->seulolo),
                RTI_CDR_UNSIGNED_LONG_LONG_TYPE)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializePrimitivePointerSequence(
                stream,
                (void **)DDS_UnsignedLongLongSeq_get_discontiguous_bufferI(&sample->seulolo),
                &sequence_length,
                DDS_UnsignedLongLongSeq_get_maximum(&sample->seulolo),
                RTI_CDR_UNSIGNED_LONG_LONG_TYPE)) {
                return RTI_FALSE;
            }
        }
        if (!DDS_UnsignedLongLongSeq_set_length(&sample->seulolo, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (DDS_CharSeq_get_contiguous_bufferI(&sample->sech) != NULL) {
            if (!RTICdrStream_deserializePrimitiveSequence(
                stream,
                DDS_CharSeq_get_contiguous_bufferI(&sample->sech),
                &sequence_length,
                DDS_CharSeq_get_maximum(&sample->sech),
                RTI_CDR_CHAR_TYPE)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializePrimitivePointerSequence(
                stream,
                (void **)DDS_CharSeq_get_discontiguous_bufferI(&sample->sech),
                &sequence_length,
                DDS_CharSeq_get_maximum(&sample->sech),
                RTI_CDR_CHAR_TYPE)) {
                return RTI_FALSE;
            }
        }
        if (!DDS_CharSeq_set_length(&sample->sech, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (DDS_FloatSeq_get_contiguous_bufferI(&sample->sefl) != NULL) {
            if (!RTICdrStream_deserializePrimitiveSequence(
                stream,
                DDS_FloatSeq_get_contiguous_bufferI(&sample->sefl),
                &sequence_length,
                DDS_FloatSeq_get_maximum(&sample->sefl),
                RTI_CDR_FLOAT_TYPE)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializePrimitivePointerSequence(
                stream,
                (void **)DDS_FloatSeq_get_discontiguous_bufferI(&sample->sefl),
                &sequence_length,
                DDS_FloatSeq_get_maximum(&sample->sefl),
                RTI_CDR_FLOAT_TYPE)) {
                return RTI_FALSE;
            }
        }
        if (!DDS_FloatSeq_set_length(&sample->sefl, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (DDS_DoubleSeq_get_contiguous_bufferI(&sample->sedl) != NULL) {
            if (!RTICdrStream_deserializePrimitiveSequence(
                stream,
                DDS_DoubleSeq_get_contiguous_bufferI(&sample->sedl),
                &sequence_length,
                DDS_DoubleSeq_get_maximum(&sample->sedl),
                RTI_CDR_DOUBLE_TYPE)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializePrimitivePointerSequence(
                stream,
                (void **)DDS_DoubleSeq_get_discontiguous_bufferI(&sample->sedl),
                &sequence_length,
                DDS_DoubleSeq_get_maximum(&sample->sedl),
                RTI_CDR_DOUBLE_TYPE)) {
                return RTI_FALSE;
            }
        }
        if (!DDS_DoubleSeq_set_length(&sample->sedl, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    if (!InsidePlugin_deserialize(
            endpoint_data,
            &sample->ins,
            stream, 
            RTI_FALSE, RTI_TRUE, 
            endpoint_plugin_qos)) {
        return RTI_FALSE;
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


RTIBool SequencesPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;


    if(skip_encapsulation) {
        if (!RTICdrStream_skipEncapsulation(stream)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (skip_sample) {

    if (!RTICdrStream_skipString(stream, (255) + 1)) {
        return RTI_FALSE;
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (!RTICdrStream_skipPrimitiveSequence(
            stream,
            &sequence_length,
            RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (!RTICdrStream_skipPrimitiveSequence(
            stream,
            &sequence_length,
            RTI_CDR_SHORT_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (!RTICdrStream_skipPrimitiveSequence(
            stream,
            &sequence_length,
            RTI_CDR_UNSIGNED_SHORT_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (!RTICdrStream_skipPrimitiveSequence(
            stream,
            &sequence_length,
            RTI_CDR_LONG_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (!RTICdrStream_skipPrimitiveSequence(
            stream,
            &sequence_length,
            RTI_CDR_UNSIGNED_LONG_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (!RTICdrStream_skipPrimitiveSequence(
            stream,
            &sequence_length,
            RTI_CDR_LONG_LONG_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (!RTICdrStream_skipPrimitiveSequence(
            stream,
            &sequence_length,
            RTI_CDR_UNSIGNED_LONG_LONG_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (!RTICdrStream_skipPrimitiveSequence(
            stream,
            &sequence_length,
            RTI_CDR_CHAR_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (!RTICdrStream_skipPrimitiveSequence(
            stream,
            &sequence_length,
            RTI_CDR_FLOAT_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (!RTICdrStream_skipPrimitiveSequence(
            stream,
            &sequence_length,
            RTI_CDR_DOUBLE_TYPE)) {
            return RTI_FALSE;
        }
    }
            
    if (!InsidePlugin_skip(
            endpoint_data,
            stream, 
            RTI_FALSE, RTI_TRUE, 
            endpoint_plugin_qos)) {
        return RTI_FALSE;
    }
            
    }


    if(skip_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


unsigned int 
SequencesPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;


    if (include_encapsulation) {

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, (255) + 1);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, (100), RTI_CDR_OCTET_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, (100), RTI_CDR_SHORT_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, (100), RTI_CDR_UNSIGNED_SHORT_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, (100), RTI_CDR_LONG_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, (100), RTI_CDR_UNSIGNED_LONG_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, (100), RTI_CDR_LONG_LONG_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, (100), RTI_CDR_UNSIGNED_LONG_LONG_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, (100), RTI_CDR_CHAR_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, (100), RTI_CDR_FLOAT_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, (100), RTI_CDR_DOUBLE_TYPE);
            
    current_alignment +=  InsidePlugin_get_serialized_sample_max_size(
        endpoint_data,RTI_FALSE,current_alignment);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


unsigned int 
SequencesPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;


    if (include_encapsulation) {

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, 1);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, 0, RTI_CDR_OCTET_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, 0, RTI_CDR_SHORT_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, 0, RTI_CDR_UNSIGNED_SHORT_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, 0, RTI_CDR_LONG_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, 0, RTI_CDR_UNSIGNED_LONG_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, 0, RTI_CDR_LONG_LONG_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, 0, RTI_CDR_UNSIGNED_LONG_LONG_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, 0, RTI_CDR_CHAR_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, 0, RTI_CDR_FLOAT_TYPE);
            
    current_alignment +=  RTICdrType_getPrimitiveSequenceMaxSizeSerialized(
        current_alignment, 0, RTI_CDR_DOUBLE_TYPE);
            
    current_alignment +=  InsidePlugin_get_serialized_sample_min_size(
        endpoint_data,RTI_FALSE,current_alignment);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


/* Returns the size of the sample in its serialized form (in bytes).
 * It can also be an estimation in excess of the real buffer needed 
 * during a call to the serialize() function.
 * The value reported does not have to include the space for the
 * encapsulation flags.
 */
unsigned int
SequencesPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    unsigned int size,
    const void * sample) {
    /* In the default implementation, it consider each sample as big 
     * as the largest sample.
     */
    return SequencesPlugin_get_serialized_sample_max_size(
        endpoint_data,
        include_encapsulation,
        size);
}


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */


PRESTypePluginKeyKind 
SequencesPlugin_get_key_kind()
{

    return PRES_TYPEPLUGIN_NO_KEY;
     
}


RTIBool 
SequencesPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const Sequences *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;


    if(serialize_encapsulation) {
        /* Encapsulate sample */
        if (!RTICdrStream_serializeCdrEncapsulationDefault(stream)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if(serialize_key) {

        if (!SequencesPlugin_serialize(
                endpoint_data,
                sample,
                stream,
                RTI_FALSE,RTI_TRUE,
                endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    
    }


    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


RTIBool SequencesPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    Sequences *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeCdrEncapsulationAndSetDefault(stream)) {
            return RTI_FALSE;  
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

        if (!SequencesPlugin_deserialize(
                endpoint_data, sample, stream,
                RTI_FALSE, RTI_TRUE, 
                endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


unsigned int
SequencesPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    unsigned int current_alignment)
{

    unsigned int encapsulation_size = current_alignment;


    unsigned int initial_alignment = current_alignment;

    if (include_encapsulation) {

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }
        

    current_alignment += SequencesPlugin_get_serialized_sample_max_size(
        endpoint_data,RTI_FALSE,current_alignment);
    
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


RTIBool 
SequencesPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    Sequences *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;


    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeCdrEncapsulationAndSetDefault(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

        if (!SequencesPlugin_deserialize(
            endpoint_data, sample, stream, RTI_FALSE, 
            RTI_TRUE, endpoint_plugin_qos)) {
            return RTI_FALSE;
        }

    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


 

/* ------------------------------------------------------------------------
 * Plug-in Installation Methods
 * ------------------------------------------------------------------------ */
 
struct PRESTypePlugin *SequencesPlugin_new() 
{ 
    struct PRESTypePlugin *plugin = NULL;
    const struct PRESTypePluginVersion PLUGIN_VERSION = 
        PRES_TYPE_PLUGIN_VERSION_2_0;

    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);
    if (plugin == NULL) {
       return NULL;
    }

    plugin->version = PLUGIN_VERSION;

    /* set up parent's function pointers */
    plugin->onParticipantAttached =
        (PRESTypePluginOnParticipantAttachedCallback)
        SequencesPlugin_on_participant_attached;
    plugin->onParticipantDetached =
        (PRESTypePluginOnParticipantDetachedCallback)
        SequencesPlugin_on_participant_detached;
    plugin->onEndpointAttached =
        (PRESTypePluginOnEndpointAttachedCallback)
        SequencesPlugin_on_endpoint_attached;
    plugin->onEndpointDetached =
        (PRESTypePluginOnEndpointDetachedCallback)
        SequencesPlugin_on_endpoint_detached;

    plugin->copySampleFnc =
        (PRESTypePluginCopySampleFunction)
        SequencesPlugin_copy_sample;
    plugin->createSampleFnc =
        (PRESTypePluginCreateSampleFunction)
        SequencesPlugin_create_sample;
    plugin->destroySampleFnc =
        (PRESTypePluginDestroySampleFunction)
        SequencesPlugin_destroy_sample;

    plugin->serializeFnc =
        (PRESTypePluginSerializeFunction)
        SequencesPlugin_serialize;
    plugin->deserializeFnc =
        (PRESTypePluginDeserializeFunction)
        SequencesPlugin_deserialize;
    plugin->getSerializedSampleMaxSizeFnc =
        (PRESTypePluginGetSerializedSampleMaxSizeFunction)
        SequencesPlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =
        (PRESTypePluginGetSerializedSampleMinSizeFunction)
        SequencesPlugin_get_serialized_sample_min_size;

    plugin->getSampleFnc =
        (PRESTypePluginGetSampleFunction)
        SequencesPlugin_get_sample;
    plugin->returnSampleFnc =
        (PRESTypePluginReturnSampleFunction)
        SequencesPlugin_return_sample;

    plugin->getKeyKindFnc =
        (PRESTypePluginGetKeyKindFunction)
        SequencesPlugin_get_key_kind;

 
    /* These functions are only used for keyed types. As this is not a keyed
    type they are all set to NULL
    */
    plugin->serializeKeyFnc = NULL;
    plugin->deserializeKeyFnc = NULL;
    plugin->getKeyFnc = NULL;
    plugin->returnKeyFnc = NULL;
    plugin->instanceToKeyFnc = NULL;
    plugin->keyToInstanceFnc = NULL;
    plugin->getSerializedKeyMaxSizeFnc = NULL;
    plugin->instanceToKeyHashFnc = NULL;
    plugin->serializedSampleToKeyHashFnc = NULL;
    plugin->serializedKeyToKeyHashFnc = NULL;
    
    plugin->typeCode =  (struct RTICdrTypeCode *)Sequences_get_typecode();
    
    plugin->languageKind = PRES_TYPEPLUGIN_DDS_TYPE; 

    /* Serialized buffer */
    plugin->getBuffer = 
        (PRESTypePluginGetBufferFunction)
        SequencesPlugin_get_buffer;
    plugin->returnBuffer = 
        (PRESTypePluginReturnBufferFunction)
        SequencesPlugin_return_buffer;
    plugin->getSerializedSampleSizeFnc =
        (PRESTypePluginGetSerializedSampleSizeFunction)
        SequencesPlugin_get_serialized_sample_size;

    plugin->endpointTypeName = SequencesTYPENAME;

    return plugin;
}

void
SequencesPlugin_delete(struct PRESTypePlugin *plugin)
{
    RTIOsapiHeap_freeStructure(plugin);
} 
