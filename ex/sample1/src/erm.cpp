

#include <erm.h>

using namespace dbix;

erm::erm()
  : tc()
  , entities("entity")
  , attributes("attribute")
  , relationship_roles("relationship_role")
{
  entities
    .has(*(new column("name",tc.text())));
  attributes
    .has(*(new column("name",          tc.text())))
    .has(*(new column("default_value", tc.text())))
    .has(*(new column("format",        tc.text())))
    .has(*(new column("maximum_length",tc.integer())))
    .has(*(new column("decimal",       tc.boolean())))
    .has(*(new column("formula_text",  tc.text())))
    .has(*(new column("cardinality_indicator",tc.integer())))
    .has(*(new column("default_optionality_indicator",tc.integer())));
  relationship_roles
    .has(*(new column("name",tc.text())))
    .has(*(new column("cardinality_indicator",tc.integer())))
    .has(*(new column("default_optionality_indicator",tc.integer())));

  entities
    .insert(entity().row().with("name").is("entity"))
    .insert(entity().row().with("name").is("attribute"))
    .insert(entity().row().with("name").is("relationship_role"));
}

