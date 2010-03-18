
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
  class record;

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
      dbix::column& get_column(std::vector<dbix::column_type>::size_type)
	const throw (std::out_of_range);
      int column_pos(const std::string&) const
	  throw (std::invalid_argument);
      std::vector<dbix::column_type>::size_type column_count() const;

      dbix::record& row();
      table& insert(dbix::record&);
      table& update(dbix::record&);
      table& erase(dbix::record&);
    private:
      std::string name_;
      std::map<std::string,int> columnmap;
      std::vector<dbix::column_type> columns;
    };

}

#endif
