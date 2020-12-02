
#include "LearnSQLiteCoreBPLibrary.h"
#include "LearnSQLiteCore.h"
#include "SQLiteCore/Public/SQLiteTypes.h"
//    ESQLiteColumnType
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
    UE_LOG(LogLearnSQLiteCore, Warning, TEXT("Creating sqlite database object"));
    FSQLiteDatabase db = FSQLiteDatabase();

    // Open Database
    // @note LogSQLiteDatabase: Warning: Failed to open database 'D:\db\example.db': disk I/O error
    UE_LOG(LogLearnSQLiteCore, Warning, TEXT("Opening database: example.db"));
    const TCHAR* DatabaseFilename = TEXT("D:\\db\\example.db");
    const ESQLiteDatabaseOpenMode OpenMode = ESQLiteDatabaseOpenMode::ReadWriteCreate;
    const bool IsOpen = db.Open(DatabaseFilename, OpenMode);
    UE_LOG(LogLearnSQLiteCore, Warning, TEXT("Alpha(): db.Open() = %d"), IsOpen);
    if( !IsOpen )
    {
        UE_LOG(LogLearnSQLiteCore, Warning, TEXT("Failed to open example.db"));
        return;
    }

    // Perform Operations
    if( db.IsValid() )
    {
        // Execute (1/n)
        // @note LogSQLitePreparedStatement: Warning: Failed to create prepared statement from 'CREATE TABLE Alpha(a0 INT PRIMARY KEY NOT NULL, a1 TEXT)': table Alpha already exists
        UE_LOG(LogLearnSQLiteCore, Warning, TEXT("Creating table Alpha"));
        const TCHAR* SqlCreateTableAlpha = TEXT("CREATE TABLE Alpha(a0 INT PRIMARY KEY NOT NULL, a1 TEXT)");
        const int64 RowsEnumerated = db.Execute(SqlCreateTableAlpha);

        const TCHAR* SqlInsertAlphaRow1 = TEXT("INSERT INTO Alpha(a0, a1) VALUES(1, 'Alpha')");
        const TCHAR* SqlInsertAlphaRow2 = TEXT("INSERT INTO Alpha(a0, a1) VALUES(2, 'Beta')");

        db.Execute(SqlInsertAlphaRow1);
        db.Execute(SqlInsertAlphaRow2);
        
        // Execute (2/n)
        // @note: If the query result was empty, the callback was not executed, i.e. an empty table.
        UE_LOG(LogLearnSQLiteCore, Warning, TEXT("Executing 'SELECT * FROM Alpha'..."));
        TArray<int8> OutRowIds; // Captured by reference in the callback for later use once execution completes
        const TCHAR* SqlSelectAllFromAlpha = TEXT("SELECT * FROM Alpha");
        const int64 RowsEnumerated2 = db.Execute( SqlSelectAllFromAlpha, [&OutRowIds](const FSQLitePreparedStatement& InStatement)
        {
            // @return ESQLitePreparedStatementExecuteRowResult (Continue, Stop, Error)
            // @note Stop does not return an error
            // @note Error also stops

            const TArray<FString>& ColumnNames = InStatement.GetColumnNames();
            UE_LOG(LogTemp, Warning, TEXT("ColumnNames:"));
            for(const FString& ColumnName : ColumnNames )
            {
                UE_LOG(LogTemp, Warning, TEXT("\t%s"), *ColumnName);
            }

            //@todo use this
            // const TCHAR* BindingName = TEXT("");
            // const int32 GetBindingIndexByNameResult = InStatement.GetBindingIndexByName(BindingName);

            //@todo use this
            // const TCHAR* InColumnName = TEXT("");
            // const int32 GetColumnIndexByNameResult = InStatement.GetColumnIndexByName(InColumnName);

            //@todo use this
            // ESQLiteColumnType OutColumnType;
            // const bool GetColumnTypeByIndexResult = InStatement.GetColumnTypeByIndex(/** column index */ 0, OutColumnType);
            // const bool GetColumnTypeByNameResult = InStatement.GetColumnTypeByName(InColumnName, OutColumnType);

            // Out Values 
            //      int8, uint8,
            //      int16, uint16,
            //      int32, uint32,
            //      int64, uint64,
            //      FDateTime,
            //      EnumType
            //      float, double,
            //      FString, FName, FText,
            //      TArray<uint8>
            //      FGuid
            // Reference: SQLitePreparedStatement.h line 228 to 281
            
            int8 OutValueInt8;
            const bool GetColumnValueByIndexResult = InStatement.GetColumnValueByIndex(/** column index */ 0, OutValueInt8);
            if( GetColumnValueByIndexResult )
            {
                OutRowIds.Add(OutValueInt8);
            }
            
            return ESQLitePreparedStatementExecuteRowResult::Continue;
        });
        UE_LOG(LogLearnSQLiteCore, Warning, TEXT("Execution completed..."));

        // Process OutRowIds
        UE_LOG(LogLearnSQLiteCore, Warning, TEXT("Processing OutRowIds..."));
        if( RowsEnumerated2 > 0 )
        {
            for( int8 id : OutRowIds )
            {
                UE_LOG(LogLearnSQLiteCore, Warning, TEXT("\tUsing row id %d to do stuff"), id);
            }
        }

        const FString LastError = db.GetLastError();
        UE_LOG(LogLearnSQLiteCore, Warning, TEXT("Last Error: %s"), *LastError);
        
        const int64 LastInsertRowId = db.GetLastInsertRowId();
        UE_LOG(LogLearnSQLiteCore, Warning, TEXT("Last Insert Row Id: %d"), LastInsertRowId);
    }
    
    // Close Database
    if( db.IsValid() )
    {
        const bool IsClosed = db.Close();
        UE_LOG(LogLearnSQLiteCore, Warning, TEXT("Alpha(): db.Close() = %d"), IsClosed);
    }
}

/**
 ** References **
 *
 * - Epic Games, Inc. "Unreal Engine 4.6 Release Notes"
 *		https://docs.unrealengine.com/en-US/Support/Builds/ReleaseNotes/2014/4_6/index.html
 *		Search for 'TFunction' and 'TFunctionRef'
 *
 * - Epic Games, Inc. "TFunctionRef"
 *      https://docs.unrealengine.com/en-US/API/Runtime/Core/GenericPlatform/TFunctionRef/index.html
 *
 * - Epic Games, Inc.
 *      "Engine\Source\Runtime\Core\Public\Templates\Function.h". line 793-843
 *      Contains documentation on usage of TFunction and TFunctionRef in comments above class definitions
 *
 * - answers.unrealengine.com. "How to pass a function as parameter of UFUNCTION() function?"
 *      https://answers.unrealengine.com/questions/758353/view.html
 *
 * - forums.unrealengine.com. "TFunctionRef becomes nullptr after timeline finished inside a lambda. Is this behaviour intended?"
 *      https://forums.unrealengine.com/development-discussion/c-gameplay-programming/1691175-tfunctionref-becomes-nullptr-after-timeline-finished-inside-a-lambda-is-this-behaviour-intended
 *
 */
