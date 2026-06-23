#pragma once
#include "type/Alias.hpp"
// MAYBE MORE WORK ON THIS?
namespace cmn::type::trait_
{
    template<typename T>                    struct underlying_type          {using type = __underlying_type(T);};
    template<typename T>                    struct type_identity            {using type = T;                   };

    template<typename... T>                 struct void_type                {using type = void;};

    template<b08 B, typename T, typename F> struct conditional              {using type = T;};
    template<       typename T, typename F> struct conditional<false, T, F> {using type = F;};

    template<b08 B, typename T = void>      struct enable_if                {               };
    template<       typename T       >      struct enable_if  <true , T   > {using type = T;};
}

namespace cmn::type::trait
{
    template<typename    T>                   using UNDERLYING_TYPE  = typename trait_::underlying_type <T>      ::type;
    template<typename    T>                   using TYPE_IDENTITY    = typename trait_::type_identity   <T>      ::type;
    template<typename... T>                   using VOID_TYPE        = typename trait_::void_type       <T...>   ::type;
    template<b08   B, typename T, typename F> using CONDITIONAL      = typename trait_::conditional     <B, T, F>::type;
    template<b08   B, typename T = void  >    using ENABLE_IF        = typename trait_::enable_if       <B, T>   ::type;
}