#ifndef _SUBSCRIBER_H
#define _SUBSCRIBER_H

#include <string>
#include <vector>
#include <stdexcept>

#include "Refill.h"
#include "Call.h"

namespace AcademyBilling
{
    class BillingRules;

    class BalanceIsEmpty: public std::logic_error
    {
    public:
        BalanceIsEmpty() :
            std::logic_error("Subscriber's balance is empty")
        {
        }
    };

    class Subscriber
    {
    private: 
        int balance;
        std::string number;
        BillingRules *tariff;
        Refill lastRefill;
    public:
        Subscriber(const std::string&, const int&, BillingRules*, const Refill&);
        Subscriber(const Subscriber&);
        ~Subscriber();
        int getBalance() const;
        std::string getNumber() const;
        BillingRules* getTariff() const;
        Refill getLastRefill() const;
        time_t getLastRefillTime() const;
        void setNumber(const std::string&);
        int charge(const int&);
        int addRefill(const Refill&);
    };
}

#endif