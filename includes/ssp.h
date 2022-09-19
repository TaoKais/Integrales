//
//  ssp.h
//  ssp
//
//  Created by Dave Horton on 11/24/12.
//  Copyright (c) 2012 Beachdog Networks. All rights reserved.
//

#ifndef ssp_ssp_h
#define ssp_ssp_h

#include <C:\Workspace\Workspace_A\includes\signals.h>
#include <C:\Workspace\Workspace_A\includes\unistd.h>
#include <C:\Workspace\Workspace_A\includes\stdlib.h>
#include <C:\Workspace\Workspace_A\includes\types.h>
#include <C:\Workspace\Workspace_A\includes\stat.h>
#include <C:\Workspace\Workspace_A\includes\stdexcept>
#include <C:\Workspace\Workspace_A\includes\string>
#include <C:\Workspace\Workspace_A\includes\iostream>
#include <C:\Workspace\Workspace_A\includes\shared_ptr.hpp>
#include <C:\Workspace\Workspace_A\includes\scoped_ptr.hpp>

#include <C:\Workspace\Workspace_A\includesboost\common.hpp>
//#include <boost/log/filters.hpp>
//#include <boost/log/formatters.hpp>
#include <C:\Workspace\Workspace_A\includes\expressions.hpp>
#include <C:\Workspace\Workspace_A\includes\attributes.hpp>
#include <C:\Workspace\Workspace_A\includes\sync_frontend.hpp>
#include <C:\Workspace\Workspace_A\includes\syslog_backend.hpp>
#include <C:\Workspace\Workspace_A\includes\sources\severity_logger.hpp>
#include <C:\Workspace\Workspace_A\includes\tokenizer.hpp>
#include <C:\Workspace\Workspace_A\includes\thread.hpp>


namespace logging = boost::log;
namespace attrs = boost::log::attributes;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace expr = boost::log::expressions;
//namespace fmt = boost::log::formatters;
namespace keywords = boost::log::keywords;
//namespace filters = boost::log::filters ;


namespace ssp {
    
    class SipLbController ;
    
    typedef boost::tokenizer<boost::char_separator<char> > tokenizer ;
    
	enum severity_levels {
		log_notice,
		log_error,
		log_warning,
	    log_info,
	    log_debug
	};
    
    enum routing_error {
        invalid_sender,
        dnis_not_provisioned,
        no_available_server,
        no_routes_provisioned
    } ;
    const std::string& RoutingError2String( routing_error error ) ;
    
    enum routing_strategy {
        unknown_routing_strategy,
        round_robin,
        least_loaded,
        random,
        same_in_same_out_carrier,
        same_in_same_out_server,
        selected_carrier,
        selected_server
    } ;
    routing_strategy String2RoutingStrategy( const std::string& s) ;
    
    enum route_selector {
        unknown_route_selector,
        ani_selector,
        customer_selector
    } ;
    route_selector String2RouteSelector( const std::string& s) ;
        
    enum agent_mode {
        agent_mode_stateless,
        agent_mode_stateful
    } ;
    
    enum call_type_t {
        unknown_call_type,
        origination_call_type,
        termination_call_type
    } ;
    
}

#ifdef SSP_MAIN
ssp::SipLbController* theOneAndOnlyController = NULL ;
#else
extern ssp::SipLbController* theOneAndOnlyController ;
#endif


#define SSP_LOG(level) BOOST_LOG_SEV(theOneAndOnlyController->getLogger(), level)

#endif
