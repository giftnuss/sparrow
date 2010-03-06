
#ifndef _DBIX_TABLE_H_
#define _DBIX_TABLE_H_

#include <string>
#include <map>
#include <stdexcept>
#include <vector>
#include <dbix/column.h>
#include <sparrow/coat/sptr.h>

namespace dbix {

  typedef sparrow::coat::sptr<column> column_type;

    class table {
    public:
      table(std::string);
      virtual ~table();
      const std::string& name() const;
      table& has(dbix::column&) throw (std::invalid_argument);
      bool has_column(const std::string&) const;
      
      dbix::column& get_column(const std::string&) 
          throw (std::invalid_argument);
      dbix::column& get_column(std::vector<dbix::column_type>::size_type)
          throw (std::out_of_range);
      std::vector<dbix::column_type>::size_type column_count() const;

    private:
      std::string name_;
      std::map<std::string,int> columnmap;
      std::vector<dbix::column_type> columns;
    };

}

#endif
