/*
 * =====================================================================================
 *
 *       Filename:  LoggerFactory.h
 *
 *    Description:  ��־������
 *
 *        Version:  1.0
 *        Created:  04/24/2011 04:34:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lpc, lvpengcheng6300@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef COMMON_LOG_LOGGERFACTORY_H_
#define COMMON_LOG_LOGGERFACTORY_H_

#include <map>
#include <string>

#include "sys/Singleton.h"
#include "Logger.h"
#include "LogLevel.h"

/**
 * @brief ��־������
 */
class LoggerFactory : public Singleton<LoggerFactory> {
    friend class Singleton<LoggerFactory>;
    public:
        ~LoggerFactory();

        /**
         * @brief ��ʼ����־��ϵͳ
         *
         * @param level ��־��ʾ����
         *
         * @return 
         */
        int initialize(LogLevel level);

        /**
         * @brief ��ȡָ��Logger
         *
         * @param loggerName Logger������
         *
         * @return ָ��Logger��ָ��
         *      - NULL ָ����Logger������
         */
        Logger* getLogger(const std::string &loggerName);

        /**
         * @brief ��ȡROOT Logger��ROOT Logger���Ǵ��ڣ�
         *
         * @return ָ��ROOT Logger��ָ��
         */
        Logger* getRootLogger();

    private:
        LoggerFactory();  // can't new

    private:
        LogLevel m_Level;
        static std::map<std::string, Logger *> m_LoggerMap;  // map of logger
};

#endif // COMMON_LOG_LOGGERFACTORY_H_

