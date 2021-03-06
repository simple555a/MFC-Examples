#include "TortureXML.h"
#pragma hdrstop

void create_huge_element_name( LPCTSTR filename, DWORD size, CRandomNumberGenerator2& random )
{
   WFCTRACEINIT( TEXT( "create_huge_element_name()" ) );

   CFile file;

   if ( file.Open( filename, CFile::modeCreate | CFile::modeWrite ) == FALSE )
   {
      WFCTRACEERROR( GetLastError() );
      WFCTRACE( TEXT( "Can't create file." ) );
      return;
   }

   BYTE buffer[ 100 ];

   ZeroMemory( buffer, sizeof( buffer ) );

   strcpy( (char *) buffer, "<?xml version=\"1.0\" ?>" );

   file.Write( (const char *) buffer, strlen( (const char *) buffer ) );

   buffer[ 0 ] = CARRIAGE_RETURN;
   buffer[ 1 ] = LINE_FEED;
   buffer[ 2 ] = '<';

   file.Write( buffer, 3 );

   CString legal_characters( TEXT( "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_:.-" ) );

   DWORD number_of_legal_characters = legal_characters.GetLength();
   DWORD loop_index                 = 0;

   CByteArray element_name;

   element_name.SetSize( 0, 8192 );
   element_name.Add( 'S' );

   while( loop_index < size )
   {
      element_name.Add( legal_characters.GetAt( random.GetInteger() % number_of_legal_characters ) );
      loop_index++;
   }

   file.Write( element_name.GetData(), element_name.GetSize() );

   strcpy( (char *) buffer, ">Hello World</" );

   file.Write( buffer, strlen( (const char *) buffer ) );
   file.Write( element_name.GetData(), element_name.GetSize() );

   buffer[ 0 ] = '>';
   buffer[ 1 ] = CARRIAGE_RETURN;
   buffer[ 2 ] = LINE_FEED;

   file.Write( buffer, 3 );
   file.Close();
}

