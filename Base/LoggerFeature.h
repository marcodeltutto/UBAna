/**
 * \file LoggerFeature.h
 *
 * \ingroup Base
 * 
 * \brief Class definition file of LoggerFeature
 *
 * @author Marco Del Tutto
 */

/** \addtogroup Base
    @{*/

#ifndef __UBANALOGGERFEATURE_H__
#define __UBANALOGGERFEATURE_H__

#include <vector>
#include "UBAnaLogger.h"

namespace Base {
    
  /**
    \class LoggerFeature
    Framework base class equipped with a logger class
  */
  class LoggerFeature {
    
  public:
    
    /// Default constructor
    LoggerFeature(const std::string logger_name="LoggerFeature")
      : _logger(nullptr)
    { _logger = &(::Base::logger::get(logger_name)); }
    
    /// Default copy constructor
    LoggerFeature(const LoggerFeature &original) : _logger(original._logger) {}
    
    /// Default destructor
    virtual ~LoggerFeature(){};
    
    /// Logger getter
    inline const Base::logger& logger() const
    { return *_logger; }
    
    /// Verbosity level
    void set_verbosity(::Base::msg::Level_t level)
    { _logger->set(level); }

    /// Name getter, defined in a logger instance attribute
    const std::string& name() const
    { return logger().name(); }
    
  private:
    
    Base::logger *_logger;   ///< logger
    
  };
}
#endif

/** @} */ // end of doxygen group