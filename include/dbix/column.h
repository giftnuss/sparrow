
#ifndef _DBIX_COLUMN_H_
#define _DBIX_COLUMN_H_

#include <string>
#include <dbix/types/type.h>

namespace dbix {

    class column {
    public:
      column(std::string);
      column(std::string,const dbix::types::type&);
      virtual ~column();
      const std::string& name() const;
      column& nullable(bool);
      bool is_nullable() const;
    private:
      std::string name_;
      bool withnull;
      const dbix::types::type* typeptr;
    };

}

#endif
