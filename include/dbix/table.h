
#ifndef _DBIX_TABLE_H_
#define _DBIX_TABLE_H_

#include <string>
#include <map>
#include <stdexcept>
#include <dbix/column.h>

namespace dbix {

    class table {
    public:
      table(std::string);
      virtual ~table();
      const std::string& name() const;
      table& has(dbix::column&) throw (std::invalid_argument);
      bool has_column(const std::string&) const;
      dbix::column& get_column(const std::string&) throw (std::invalid_argument);
    private:
      std::string name_;
      std::map<std::string,dbix::column> columns;
    };

}

#endif
