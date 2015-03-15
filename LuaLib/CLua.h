#pragma once

struct lua_State;

#define LuaGlue extern "C" int  // ���� LuaGlue ��

extern "C" { // ����һ�� C ��ʽ�� LuaFunctionType ���ͺ���ָ��
    typedef int(*LuaFunctionType)(lua_State *pLuaState);
};

class cLua {
public:
    cLua();
    virtual ~cLua();

    bool		RunScript(const char* pFilename);
    bool		RunString(const char* pCommand);
    const char* GetErrorString(void);

    bool		AddFunction(const char* pFunctionName, LuaFunctionType pFunction);

    const char* GetStringArgument(int num, const char* pDefault = NULL);
    double		GetNumberArgument(int num, double dDefault = 0.0);
    int 		GetIntArgument(int num, int nDefault = 0);

    void		PushString(const char* pString);
    void		PushNumber(double value);
    void		PushInt(int value);

    void		SetErrorHandler(void(*pErrHandler)(const char* pError));

    lua_State*  GetScriptContext(void);

private:
    lua_State*  m_pScriptContext;
    void(*m_pErrorHandler)(const char *pError);
};