/// @fn int controller_loadFromText(LinkedList*, int(*)(FILE*, LinkedList*))
/// @brief
/// @param pArrayListLibros
/// @param pFunc
/// @return
int controller_loadFromText(LinkedList* pArrayListLibros, int (*pFunc) (FILE*, LinkedList*));
/// @fn int controller_loadFromBinary(char*, LinkedList*)
/// @brief
/// @param path
/// @param pArrayListEmployee
/// @return
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/// @fn int controller_addLibro(LinkedList*)
/// @brief
/// @param pArrayListEmployee
/// @return
int controller_addLibro(LinkedList* pArrayListEmployee);
/// @fn int controller_editLibro(LinkedList*)
/// @brief
/// @param pArrayListEmployee
/// @return
int controller_editLibro(LinkedList* pArrayListEmployee);
/// @fn int controller_removeLibro(LinkedList*)
/// @brief
/// @param pArrayListEmployee
/// @return
int controller_removeLibro(LinkedList* pArrayListEmployee);
/// @fn int controller_ListLibros(LinkedList*, LinkedList*)
/// @brief
/// @param pArrayListLibros
/// @param listaEditoriales
/// @return
int controller_ListLibros(LinkedList* pArrayListLibros, LinkedList* listaEditoriales);
/// @fn int controller_sortLibros(LinkedList*, LinkedList*)
/// @brief
/// @param pArrayListLibros
/// @param pArrayEditoriales
/// @return
int controller_sortLibros(LinkedList* pArrayListLibros, LinkedList* pArrayEditoriales);
/// @fn int controller_saveAsBinary(char*, LinkedList*)
/// @brief
/// @param path
/// @param pArrayListEmployee
/// @return
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
/// @fn int controller_ListEditoriales(LinkedList*)
/// @brief
/// @param pArrayListEditoriales
/// @return
int controller_ListEditoriales(LinkedList* pArrayListEditoriales);
/// @fn int controller_filtrarLibros(LinkedList*, LinkedList*)
/// @brief
/// @param listaLibros
/// @param listaEditoriales
/// @return
int controller_filtrarLibros(LinkedList* listaLibros,LinkedList* listaEditoriales);
/// @fn int controller_saveAsText(char*, LinkedList*)
/// @brief
/// @param path
/// @param pArrayListLibro
/// @return
int controller_saveAsText(char* path , LinkedList* pArrayListLibro);
/// @fn int controller_MapearLibros(LinkedList*)
/// @brief
/// @param listaLibros
/// @return
int controller_MapearLibros(LinkedList* listaLibros);
/// @fn int saveText(FILE*, LinkedList*)
/// @brief
/// @param pFile
/// @param pArrayLibros
/// @return
int saveText (FILE* pFile, LinkedList* pArrayLibros);
int controller_cantLibros(LinkedList* pArrayListLibros);
float controller_Precios_ePearson(LinkedList* pArrayListLibros);





