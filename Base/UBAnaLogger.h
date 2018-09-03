/**
 * \file HitCosmicTagLogger.h
 *
 * \ingroup Base
 * 
 * \brief logger utility class definition header file.
 *
 * @author Marco Del Tutto
 */

/** \addtogroup Base
    @{*/
#ifndef __UBANALOGGER_H__
#define __UBANALOGGER_H__

#include <cstdio>
#include <iostream>
#include <map>
// #include "DataTypes.h"

namespace Base {
  namespace msg {
    /// Verbosity message level
    enum Level_t {
      kDEBUG,
      kINFO,
      kNORMAL,
      kWARNING,
      kERROR,
      kEXCEPTION,
      kMSG_TYPE_MAX
    };

    const std::string kStringPrefix[kMSG_TYPE_MAX] =
    {
  " [DEBUG] ", ///< DEBUG message prefix
  " [INFO] ", ///< INFO message prefix
  " [NORMAL] ", ///< NORMAL message prefix
  " [WARNING] ", ///< WARNING message prefix
  " [ERROR] ", ///< ERROR message prefix
  " [EXCEPTION] "  ///< CRITICAL message prefix
};
    ///< Prefix of message
}
}


namespace Base {

  /**
     \class logger
     \brief Utility class used to show formatted message on the screen.
     A logger class for UBAna. Simply shows a formatted colored message on a screen. \n
     A static getter method is provided to create a sharable logger instance. \n
  */
  class logger{
    
  public:
    
    /// Default constructor
    logger(const std::string& name="no_name")
      : _ostrm(&std::cout)
      , _name(name)
    {}
    
    /// Default destructor
    virtual ~logger(){};
    
  private:
    
    /// ostream
    std::ostream *_ostrm;
    
    /// Level
    msg::Level_t _level;
      
    /// Name
    std::string _name;
    
    /// Set of loggers
    static std::map<std::string,Base::logger> *_logger_m;

    /// Default logger level
    static msg::Level_t _level_default;
    
  public:

    /// Logger's name
    const std::string& name() const { return _name; }

    /// Verbosity level setter
    void set(const msg::Level_t level) { _level = level; }

    /// Verbosity level getter
    msg::Level_t level() const { return _level; }

    /// Comparison operator for static collection of loggers
    inline bool operator<(const logger& rhs) const
    {
      if(_name < rhs.name()) return true;
      if(_name > rhs.name()) return false;
      return false;
    }
    
    /// Getter of a message instance 
    static logger& get(const std::string name)
    {
      if(!_logger_m) _logger_m = new std::map<std::string,Base::logger>();
      auto iter = _logger_m->find(name);
      if(iter == _logger_m->end()) {
        iter = _logger_m->emplace(name,logger(name)).first;
        iter->second.set(msg::kNORMAL);
      }
      return iter->second;
    };

    /// Default logger level getter
    static msg::Level_t default_level() { return _level_default; }
    /// Default logger level setter (only affect future loggers)
    static void default_level(msg::Level_t l) { _level_default = l; }
    /// Force all loggers to change level
    static void force_level(msg::Level_t l)
    {
      default_level(l);
      for(auto& name_logger : *_logger_m) name_logger.second.set(l);
    }
  
    //
    // Verbosity level checker
    //
    inline bool debug   () const { return _level <= msg::kDEBUG;   }
    inline bool info    () const { return _level <= msg::kINFO;    }
    inline bool normal  () const { return _level <= msg::kNORMAL;  }
    inline bool warning () const { return _level <= msg::kWARNING; }
    inline bool error   () const { return _level <= msg::kERROR;   }
    /// Formatted message (simplest)
    std::ostream& send(const msg::Level_t) const;
    /// Formatted message (function name included)
    std::ostream& send(const msg::Level_t level,
           const std::string& function ) const;
    /// Formatted message (function name + line number)
    std::ostream& send(const msg::Level_t level,
           const std::string& function,
           const unsigned int line_num ) const;
    /// Formatted message (function name + line number + file name)
    std::ostream& send(const msg::Level_t level,
           const std::string& function,
           const unsigned int line_num,
           const std::string& file_name) const;
    
  };
}
//
// Compiler macro for saving us from text typing
//
/// Compiler macro for DEBUG message
#define LOG_DEBUG()    if( logger().debug   () ) logger().send(::Base::msg::kDEBUG,    __FUNCTION__, __LINE__, __FILE__)
/// Compiler macro for INFO message
#define LOG_INFO()     if( logger().info    () ) logger().send(::Base::msg::kINFO,     __FUNCTION__, __LINE__          )
/// Compiler macro for NORMAL message
#define LOG_NORMAL()   if( logger().normal  () ) logger().send(::Base::msg::kNORMAL,   __FUNCTION__                    )
/// Compiler macro for WARNING message
#define LOG_WARNING()  if( logger().warning () ) logger().send(::Base::msg::kWARNING,  __FUNCTION__                    )
/// Compiler macro for ERROR message
#define LOG_ERROR()    if( logger().error   () ) logger().send(::Base::msg::kERROR,    __FUNCTION__, __LINE__          )
/// Compiler macro for CRITICAL message
#define LOG_CRITICAL()                           logger().send(::Base::msg::kEXCEPTION, __FUNCTION__, __LINE__, __FILE__)
  
/** @} */ // end of doxygen group logger
#endif