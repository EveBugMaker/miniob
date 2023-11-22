#pragma once

#include "common/rc.h"
#include "sql/stmt/stmt.h"
#include "storage/table/table.h"

class Table;
class Db;

class DropTableStmt : public Stmt
{
private:
  Table *table_ = nullptr;

public:
  DropTableStmt(Table *table) : table_(table){};

  StmtType type() const override { return StmtType::DROP_TABLE; }

public:
  static RC create(Db *db, const DropTableSqlNode &drop_table_sql, Stmt *&stmt);

  const char *table_name() const;
};