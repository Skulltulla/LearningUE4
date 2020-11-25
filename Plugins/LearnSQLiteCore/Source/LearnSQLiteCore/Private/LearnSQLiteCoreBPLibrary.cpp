
#include "LearnSQLiteCoreBPLibrary.h"
#include "LearnSQLiteCore.h"
#include "SQLiteCore/Public/SQLiteTypes.h"
//    EQLiteColumnType
#include "SQLiteCore/Public/SQLiteDatabase.h"
//    ESQLiteDataBaseOpenMode
//    FSQLiteDatabase
#include "SQLiteCore/Public/SQLitePreparedStatement.h"

DEFINE_LOG_CATEGORY_STATIC(LogLearnSQLiteCore, Warning, All);

ULearnSQLiteCoreBPLibrary::ULearnSQLiteCoreBPLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void ULearnSQLiteCoreBPLibrary::Alpha()
{
    // Create Database
    FSQLiteDatabase db = FSQLiteDatabase();

    // Open Database
    const TCHAR* DatabaseFilename = TEXT("C:\\example.db");
    const ESQLiteDatabaseOpenMode OpenMode = ESQLiteDatabaseOpenMode::ReadWriteCreate;
    bool IsOpen = db.Open(DatabaseFilename, OpenMode);
    UE_LOG(LogLearnSQLiteCore, Warning, TEXT("Alpha(): db.Open() = %d"), IsOpen);
    if( !IsOpen )
    {
        return;
    }

    // Close Database
    bool IsClosed = db.Close();
    UE_LOG(LogLearnSQLiteCore, Warning, TEXT("Alpha(): db.Close() = %d"), IsClosed);
}
