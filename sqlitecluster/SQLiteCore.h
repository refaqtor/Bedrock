#pragma once
class SQLite;

class SQLiteCore {
  public:
    // Constructor that stores the database object we'll be working on.
    SQLiteCore(SQLite& db);

    // Commit the outstanding transaction on the DB.
    // Returns true on successful commit, false on conflict.
    bool commit(const string& description, uint64_t& commitID, string& transactionHash);

    // Roll back a transaction if we've decided not to commit it.
    void rollback();

  protected:
    SQLite& _db;
};
