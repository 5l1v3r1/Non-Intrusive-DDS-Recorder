/* -*- C++ -*- */
/* Generated by opendds_idl version 3.3 (ACE version 5.6a_p13) running on input file HelloWorld.idl*/
#ifndef OPENDDS_IDL_GENERATED_HELLOWORLDTYPESUPPORTIMPL_H_APCQGD
#define OPENDDS_IDL_GENERATED_HELLOWORLDTYPESUPPORTIMPL_H_APCQGD
#include "dds/DCPS/Definitions.h"
#include "HelloWorldC.h"
#include "HelloWorldTypeSupportC.h"
#include "dds/DCPS/DataBlockLockPool.h"
#include "dds/DCPS/DataReaderImpl.h"
#include "dds/DCPS/DataWriterImpl.h"
#include "dds/DCPS/Dynamic_Cached_Allocator_With_Overflow_T.h"
#include "dds/DCPS/Serializer.h"
#include "dds/DCPS/SubscriptionInstance.h"
#include "dds/DCPS/TypeSupportImpl.h"


/* Begin STRUCT: HelloWorld */

namespace OpenDDS { namespace DCPS {

void gen_find_size(const HelloWorld& stru, size_t& size, size_t& padding);

bool operator<<(Serializer& strm, const HelloWorld& stru);

bool operator>>(Serializer& strm, HelloWorld& stru);

bool gen_is_bounded_size(const HelloWorld&);

size_t gen_max_marshaled_size(const HelloWorld& stru, bool align);

bool gen_is_bounded_size(KeyOnly<const HelloWorld>);

size_t gen_max_marshaled_size(KeyOnly<const HelloWorld> stru, bool align);

void gen_find_size(KeyOnly<const HelloWorld> stru, size_t& size, size_t& padding);

bool operator<<(Serializer& strm, KeyOnly<const HelloWorld> stru);

bool operator>>(Serializer& strm, KeyOnly<HelloWorld> stru);

}  }

namespace OpenDDS { namespace DCPS {

bool gen_has_key(const HelloWorld&);

}  }

namespace OpenDDSGenerated {
// This structure supports use of std::map with a key
// defined by one or more #pragma DCPS_DATA_KEY lines.
struct  HelloWorld_KeyLessThan {
  bool operator()(const HelloWorld& v1, const HelloWorld& v2) const
  {
#ifndef OPENDDS_GCC33
    using ::operator<; // TAO::String_Manager's operator< is in global NS
#endif
    ACE_UNUSED_ARG(v1);
    ACE_UNUSED_ARG(v2);
    // with no DCPS_DATA_KEYs, return false
    // to allow use of map with just one entry
    return false;
  }
};
}
/** Servant for TypeSuport interface of HelloWorld data type.
 *
 * See the DDS specification, OMG formal/04-12-02, for a description of
 * this interface.
 *
 */
class  HelloWorldTypeSupportImpl
  : public virtual OpenDDS::DCPS::LocalObject<HelloWorldTypeSupport>
  , public virtual OpenDDS::DCPS::TypeSupportImpl
{
public:

  //Constructor
  HelloWorldTypeSupportImpl ();

  //Destructor
  virtual ~HelloWorldTypeSupportImpl ();

  virtual
  ::DDS::ReturnCode_t register_type (::DDS::DomainParticipant_ptr participant,
                                     const char * type_name);

  virtual char * get_type_name ();

  virtual ::DDS::DataWriter_ptr create_datawriter ();

  virtual ::DDS::DataReader_ptr create_datareader ();

#ifndef OPENDDS_NO_MULTI_TOPIC
  virtual ::DDS::DataReader_ptr create_multitopic_datareader();
#endif

#ifndef OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE
  virtual const OpenDDS::DCPS::MetaStruct& getMetaStructForType();
#endif

  virtual bool has_dcps_key();

private:
  CORBA::String_var type_name_;
};

/** Servant for DataWriter interface of the HelloWorld data type.
 *
 * See the DDS specification, OMG formal/04-12-02, for a description of
 * this interface.
 */
class  HelloWorldDataWriterImpl
  : public virtual OpenDDS::DCPS::LocalObject<HelloWorldDataWriter>,
    public virtual OpenDDS::DCPS::DataWriterImpl
{
public:

  typedef std::map<HelloWorld, ::DDS::InstanceHandle_t,
      OpenDDSGenerated::HelloWorld_KeyLessThan> InstanceMap;
  typedef ::OpenDDS::DCPS::Dynamic_Cached_Allocator_With_Overflow<ACE_Null_Mutex>  DataAllocator;

  //Constructor
  HelloWorldDataWriterImpl (void);

  //Destructor
  virtual ~HelloWorldDataWriterImpl (void);

  virtual ::DDS::InstanceHandle_t register_instance (
      const ::HelloWorld & instance);

  virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
      const ::HelloWorld & instance,
      const ::DDS::Time_t & timestamp);

  virtual ::DDS::ReturnCode_t unregister_instance (
      const ::HelloWorld & instance,
      ::DDS::InstanceHandle_t handle);

  virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
      const ::HelloWorld & instance,
      ::DDS::InstanceHandle_t handle,
      const ::DDS::Time_t & timestamp);

  //WARNING: If the handle is non-nil and the instance is not registered
  //         then this operation may cause an access violation.
  //         This lack of safety helps performance.
  virtual ::DDS::ReturnCode_t write (
      const ::HelloWorld & instance_data,
      ::DDS::InstanceHandle_t handle);

  //WARNING: If the handle is non-nil and the instance is not registered
  //         then this operation may cause an access violation.
  //         This lack of safety helps performance.
  virtual ::DDS::ReturnCode_t write_w_timestamp (
      const ::HelloWorld & instance_data,
      ::DDS::InstanceHandle_t handle,
      const ::DDS::Time_t & source_timestamp);

  virtual ::DDS::ReturnCode_t dispose (
      const ::HelloWorld & instance_data,
      ::DDS::InstanceHandle_t instance_handle);

  virtual ::DDS::ReturnCode_t dispose_w_timestamp (
      const ::HelloWorld & instance_data,
      ::DDS::InstanceHandle_t instance_handle,
      const ::DDS::Time_t & source_timestamp);

  virtual ::DDS::ReturnCode_t get_key_value (
      ::HelloWorld & key_holder,
      ::DDS::InstanceHandle_t handle);

  virtual ::DDS::InstanceHandle_t lookup_instance (
      const ::HelloWorld & instance_data);

  /**
   * Initialize the DataWriter object.
   * Called as part of create_datawriter.
   */
  virtual void init (
        ::DDS::Topic_ptr                       topic,
        OpenDDS::DCPS::TopicImpl*              topic_servant,
        const ::DDS::DataWriterQos &           qos,
        ::DDS::DataWriterListener_ptr          a_listener,
        const ::DDS::StatusMask &              mask,
        OpenDDS::DCPS::DomainParticipantImpl*  participant_servant,
        OpenDDS::DCPS::PublisherImpl*          publisher_servant,
        ::DDS::DataWriter_ptr                  dw_objref
      );

  /**
   * Do parts of enable specific to the datatype.
   * Called by DataWriterImpl::enable().
   */
  virtual ::DDS::ReturnCode_t enable_specific ();

  /**
   * The framework has completed its part of unregistering the
   * given instance.
   */
  virtual void unregistered(::DDS::InstanceHandle_t instance_handle);

  /**
   * Accessor to the marshalled data sample allocator.
   */
  ACE_INLINE
  DataAllocator* data_allocator () const  {
    return data_allocator_;
  };

private:

  /**
   * Serialize the instance data.
   *
   * @param instance_data The data to serialize.
   * @param for_write If 1 use the fast allocator; otherwise use the heap.
   * @param marshaling_type Enumerated type specifying whether to marshal
   *        just the keys or the entire message.
   * @return returns the serialized data.
   */
  ACE_Message_Block* dds_marshal(
    const ::HelloWorld& instance_data,
    OpenDDS::DCPS::MarshalingType marshaling_type);

  /**
   * Find the instance handle for the given instance_data using
   * the data type's key(s).  If the instance does not already exist
   * create a new instance handle for it.
   */
  ::DDS::ReturnCode_t get_or_create_instance_handle(
    ::DDS::InstanceHandle_t& handle,
    const ::HelloWorld& instance_data,
    const ::DDS::Time_t & source_timestamp);

   InstanceMap  instance_map_;
   size_t       marshaled_size_;
   size_t       key_marshaled_size_;
   // The lock pool will be thread safe because
   // only one write call is allowed at a time.
   DataBlockLockPool*  db_lock_pool_;
   DataAllocator* data_allocator_;
   ::OpenDDS::DCPS::MessageBlockAllocator* mb_allocator_;
   ::OpenDDS::DCPS::DataBlockAllocator*    db_allocator_;
};

/** Servant for DataReader interface of HelloWorld data type.
 *
 * See the DDS specification, OMG formal/04-12-02, for a description of
 * this interface.
 *
 */
class  HelloWorldDataReaderImpl
  : public virtual OpenDDS::DCPS::LocalObject<HelloWorldDataReader>,
    public virtual OpenDDS::DCPS::DataReaderImpl
{
public:

  typedef std::map<HelloWorld, ::DDS::InstanceHandle_t,
      OpenDDSGenerated::HelloWorld_KeyLessThan> InstanceMap;
  typedef ::OpenDDS::DCPS::Cached_Allocator_With_Overflow<HelloWorld, ACE_Null_Mutex>  DataAllocator;
  typedef HelloWorldDataReader Interface;

  //Constructor
  HelloWorldDataReaderImpl (void);

  //Destructor
  virtual ~HelloWorldDataReaderImpl (void);

  virtual ::DDS::ReturnCode_t delete_contained_entities ();

  /**
   * Do parts of enable specific to the datatype.
   * Called by DataReaderImpl::enable().
   */
  virtual ::DDS::ReturnCode_t enable_specific ();

  virtual ::DDS::ReturnCode_t read (
      ::HelloWorldSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states);

  virtual ::DDS::ReturnCode_t take (
      ::HelloWorldSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states);

  virtual ::DDS::ReturnCode_t read_w_condition (
      ::HelloWorldSeq & data_values,
      ::DDS::SampleInfoSeq & sample_infos,
      ::CORBA::Long max_samples,
      ::DDS::ReadCondition_ptr a_condition);

  virtual ::DDS::ReturnCode_t take_w_condition (
      ::HelloWorldSeq & data_values,
      ::DDS::SampleInfoSeq & sample_infos,
      ::CORBA::Long max_samples,
      ::DDS::ReadCondition_ptr a_condition);

  virtual ::DDS::ReturnCode_t read_next_sample (
      ::HelloWorld & received_data,
      ::DDS::SampleInfo & sample_info);

  virtual ::DDS::ReturnCode_t take_next_sample (
      ::HelloWorld & received_data,
      ::DDS::SampleInfo & sample_info);

  virtual ::DDS::ReturnCode_t read_instance (
      ::HelloWorldSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states);

  virtual ::DDS::ReturnCode_t take_instance (
      ::HelloWorldSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states);

  virtual ::DDS::ReturnCode_t read_next_instance (
      ::HelloWorldSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states);

  virtual ::DDS::ReturnCode_t take_next_instance (
      ::HelloWorldSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states);

  virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
      ::HelloWorldSeq & data_values,
      ::DDS::SampleInfoSeq & sample_infos,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t previous_handle,
      ::DDS::ReadCondition_ptr a_condition);

  virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
      ::HelloWorldSeq & data_values,
      ::DDS::SampleInfoSeq & sample_infos,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t previous_handle,
      ::DDS::ReadCondition_ptr a_condition);

  virtual ::DDS::ReturnCode_t return_loan (
      ::HelloWorldSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq);

  virtual ::DDS::ReturnCode_t get_key_value (
      ::HelloWorld & key_holder,
      ::DDS::InstanceHandle_t handle);

  virtual ::DDS::InstanceHandle_t lookup_instance (
      const ::HelloWorld & instance_data);

  virtual ::DDS::ReturnCode_t auto_return_loan(void* seq);

  void release_loan (::HelloWorldSeq & received_data);

  void dec_ref_data_element(::OpenDDS::DCPS::ReceivedDataElement* r);

  virtual void delete_instance_map (void* map);

#ifndef OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE
  bool contains_sample_filtered(::DDS::SampleStateMask sample_states,
                                ::DDS::ViewStateMask view_states,
                                ::DDS::InstanceStateMask instance_states,
                                const OpenDDS::DCPS::FilterEvaluator& evaluator,
                                const ::DDS::StringSeq& params);

  ::DDS::ReturnCode_t read_generic(
    OpenDDS::DCPS::DataReaderImpl::GenericBundle& gen,
    ::DDS::SampleStateMask sample_states, ::DDS::ViewStateMask view_states,
    ::DDS::InstanceStateMask instance_states);

  ::DDS::InstanceHandle_t lookup_instance_generic(const void* data);

  ::DDS::ReturnCode_t read_instance_generic(void*& data,
    ::DDS::SampleInfo& info, ::DDS::InstanceHandle_t instance,
    ::DDS::SampleStateMask sample_states, ::DDS::ViewStateMask view_states,
    ::DDS::InstanceStateMask instance_states);

  ::DDS::ReturnCode_t read_next_instance_generic(void*& data,
    ::DDS::SampleInfo& info, ::DDS::InstanceHandle_t previous_instance,
    ::DDS::SampleStateMask sample_states, ::DDS::ViewStateMask view_states,
    ::DDS::InstanceStateMask instance_states);

#endif

  ::DDS::InstanceHandle_t store_synthetic_data(const HelloWorld& sample,
                                             ::DDS::ViewStateKind view);

  void set_instance_state(::DDS::InstanceHandle_t instance,
                          ::DDS::InstanceStateKind state);

  virtual void lookup_instance(const OpenDDS::DCPS::ReceivedDataSample& sample,
                               OpenDDS::DCPS::SubscriptionInstance*& instance);

 protected:

    virtual void dds_demarshal(const OpenDDS::DCPS::ReceivedDataSample& sample,
                               OpenDDS::DCPS::SubscriptionInstance*& instance,
                               bool & just_registered,
                               bool & filtered,
                               OpenDDS::DCPS::MarshalingType marshaling_type);

    virtual void dispose(const OpenDDS::DCPS::ReceivedDataSample& sample,
                         OpenDDS::DCPS::SubscriptionInstance*& instance);

    virtual void unregister(const OpenDDS::DCPS::ReceivedDataSample& sample,
                            OpenDDS::DCPS::SubscriptionInstance*& instance);

    //virtual OpenDDS::DCPS::DataReaderRemote_ptr get_datareaderremote_obj_ref ();

    virtual void purge_data(OpenDDS::DCPS::SubscriptionInstance* instance);

    virtual void release_instance_i (::DDS::InstanceHandle_t handle);

  private:

    ::DDS::ReturnCode_t read_i (
      ::HelloWorldSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states,
#ifndef OPENDDS_NO_QUERY_CONDITION
      ::DDS::QueryCondition_ptr a_condition);
#else
      int ignored);
#endif

    ::DDS::ReturnCode_t take_i (
      ::HelloWorldSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states,
#ifndef OPENDDS_NO_QUERY_CONDITION
      ::DDS::QueryCondition_ptr a_condition);
#else
      int ignored);
#endif

    ::DDS::ReturnCode_t read_instance_i (
      ::HelloWorldSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states,
#ifndef OPENDDS_NO_QUERY_CONDITION
      ::DDS::QueryCondition_ptr a_condition);
#else
      int ignored);
#endif

    ::DDS::ReturnCode_t take_instance_i (
      ::HelloWorldSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states,
#ifndef OPENDDS_NO_QUERY_CONDITION
      ::DDS::QueryCondition_ptr a_condition);
#else
      int ignored);
#endif

    ::DDS::ReturnCode_t read_next_instance_i (
      ::HelloWorldSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states,
#ifndef OPENDDS_NO_QUERY_CONDITION
      ::DDS::QueryCondition_ptr a_condition);
#else
      int ignored);
#endif

    ::DDS::ReturnCode_t take_next_instance_i (
      ::HelloWorldSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states,
#ifndef OPENDDS_NO_QUERY_CONDITION
      ::DDS::QueryCondition_ptr a_condition);
#else
      int ignored);
#endif

    void store_instance_data(
         ::HelloWorld *instance_data,
         const OpenDDS::DCPS::DataSampleHeader& header,
         OpenDDS::DCPS::SubscriptionInstance*& instance_ptr,
         bool & just_registered,
         bool & filtered
         );

    /// common input read* & take* input processing and precondition checks
    ::DDS::ReturnCode_t check_inputs (
        const char* method_name,
        ::HelloWorldSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::CORBA::Long max_samples
        );

   InstanceMap  instance_map_;
   DataAllocator* data_allocator_;
};
#ifndef OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE
namespace OpenDDS { namespace DCPS {

class MetaStruct;

template<typename T>
const MetaStruct& getMetaStruct();

template<>
const MetaStruct& getMetaStruct<HelloWorld>();
}  }

#endif

/* End STRUCT: HelloWorld */
#endif /* OPENDDS_IDL_GENERATED_HELLOWORLDTYPESUPPORTIMPL_H_APCQGD */
