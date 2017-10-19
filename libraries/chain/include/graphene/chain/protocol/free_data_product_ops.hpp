/*
    Copyright (C) 2017 gxb

    This file is part of gxb-core.

    gxb-core is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    gxb-core is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with gxb-core.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once
#include <graphene/chain/protocol/base.hpp>
#include <graphene/chain/protocol/types.hpp>
#include <graphene/chain/free_data_product_object.hpp>

namespace graphene { namespace chain {

    struct free_data_product_create_operation : public base_operation
    {
        struct fee_parameters_type {
           uint64_t fee  = 10 * GRAPHENE_BLOCKCHAIN_PRECISION;
        };

        string                          product_name;
        string                          brief_desc;
        account_id_type                 datasource;
        data_market_category_id_type    category_id;
        uint64_t                        price;
        string                          icon;
        vector<schema_context_object>   schema_contexts;
        string       parent_id;
        account_id_type                 issuer;
        asset                           fee;
        time_point_sec                  create_date_time;;
        time_point_sec                  recommend_expiration_date_time;
        extensions_type                 extensions;

        account_id_type fee_payer() const { return issuer; }
        void validate() const {}
        share_type      calculate_fee( const fee_parameters_type& k ) const {
            return k.fee;
        }
    };

    // updated by commmittee
    struct free_data_product_update_operation : public base_operation
    {
        struct fee_parameters_type {
            uint64_t fee  = 1 * GRAPHENE_BLOCKCHAIN_PRECISION;
        };

        free_data_product_id_type                    free_data_product;
        optional < string >                          new_product_name;
        optional < string >                          new_brief_desc;
        optional <account_id_type>                   new_datasource;
        optional < data_market_category_id_type >    new_category_id;
        optional < uint64_t >                        new_price;
        optional < string >                          new_icon;
        optional < vector<schema_context_object> >   new_schema_contexts;
        optional < string >                          new_parent_id;
        optional < uint8_t >                         new_status;
        optional < account_id_type >                 new_issuer;
        optional < time_point_sec >                  new_recommend_expiration_date_time;
        asset                                        fee;
        extensions_type                              extensions;
        account_id_type fee_payer() const { return account_id_type(); }
        void validate() const {
            FC_ASSERT(fee.amount >= 0);
        }
        share_type calculate_fee( const fee_parameters_type& k ) const {
            return k.fee;
        }
    };

} } // graphene::chain

FC_REFLECT( graphene::chain::free_data_product_create_operation::fee_parameters_type, (fee) )
FC_REFLECT( graphene::chain::free_data_product_update_operation::fee_parameters_type, (fee) )

FC_REFLECT( graphene::chain::free_data_product_create_operation,
            (product_name)
            (brief_desc)
            (datasource)
            (category_id)
            (price)
            (icon)
            (schema_contexts)
            (parent_id)
            (fee)
            (issuer)
            (create_date_time)
            (recommend_expiration_date_time)
            (extensions)
)

FC_REFLECT( graphene::chain::free_data_product_update_operation,
            (free_data_product)
            (new_product_name)
            (new_brief_desc)
            (new_datasource)
            (new_category_id)
            (new_price)
            (new_icon)
            (new_schema_contexts)
            (new_parent_id)
            (new_status)
            (new_issuer)
            (new_recommend_expiration_date_time)
            (fee)
            (extensions)
)
