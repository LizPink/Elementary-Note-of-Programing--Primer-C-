#include <string>
#include "Quote.h"

#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
class Bulk_quote: public Quote{
    public:
        Bulk_quote() = default;
        Bulk_quote(const std::string&, double, std::size_t, double);
        virtual double net_price(std::size_t) const override;

    private:
        std::size_t min_qty = 0;
        double discount = 0.0;
};
#endif
