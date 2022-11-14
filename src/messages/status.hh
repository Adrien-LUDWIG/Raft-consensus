#pragma once

#include "message.hh"

namespace MessageNS
{
    class Status : public Message {
    private:
        int m_term;
        bool m_success;
    
    public:
        Status(int term, bool success, int originId);

        Status(const json& data);

        int getTerm() const;
        int isSuccess() const;

        virtual json toJSON() const override;
    };
} // namespace MessageNS