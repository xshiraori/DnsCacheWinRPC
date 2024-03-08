#include <iostream>
#include "./include/dnsrslvr_h.h"

#pragma comment(lib, "RpcRT4.lib")

_Must_inspect_result_
_Ret_maybenull_ _Post_writable_byte_size_(AllocationSize)
VOID __RPC_FAR* __RPC_USER MIDL_user_allocate(_In_ SIZE_T AllocationSize)
{
	return new BYTE[AllocationSize];
}

VOID __RPC_USER MIDL_user_free(_Pre_maybenull_ _Post_invalid_ PVOID Address)
{
    delete[] static_cast<BYTE*>(Address);
}

int main()
{
    RPC_STATUS Status;
    RPC_WSTR StringBinding;
    RPC_BINDING_HANDLE Binding;
    PDNS_CACHE_ENTRY Entry = NULL;

    Status = RpcStringBindingCompose(
        NULL, 
        (RPC_WSTR)L"ncalrpc", 
        NULL, 
        (RPC_WSTR)L"DNSResolver", 
        NULL, 
        &StringBinding
    );

    if (Status != RPC_S_OK)
    {
        std::wcout << L"[*] RpcStringBindingCompose failed, exiting..." << L"[" << std::hex << Status << L"]" << std::endl;
        return -1;
    }

    Status = RpcBindingFromStringBinding(
        StringBinding, 
        &Binding
    );

    if (Status != RPC_S_OK)
    {
        std::wcout << L"[*] RpcBindingFromStringBinding failed, exiting..." << L"[" << std::hex << Status << L"]" << std::endl;
        return -1;
    }

    RpcStringFree(&StringBinding);

    auto PrintDnsCacheTable = [](PDNS_CACHE_ENTRY Entry)
    {
        do {
            std::wcout << Entry->Name << std::endl;
        } while (Entry = Entry->Next);
    };

    RpcTryExcept
    {
        R_ReadCache(
            Binding, 
            0, 
            &Entry
        );
    }
    RpcExcept(EXCEPTION_EXECUTE_HANDLER);
    {
        std::wcout << L"[*] RPC Exception : " << RpcExceptionCode() << std::endl;
    }
    RpcEndExcept

    PrintDnsCacheTable(Entry);
    
    RpcBindingFree(&Binding);

    return 0;
}