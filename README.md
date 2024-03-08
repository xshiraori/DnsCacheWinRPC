# DnsCacheWinRPC
List the DNS Cache entries by directly making the RPC call. Other alternative is to use dnsapi!DnsGetCacheDataTable which will eventually call the same RPC for you.

There are couple of other RPCs available on the same provider:
```
	R_ReadCache
	R_ResolverGetConfig
	R_ResolverFlushCache
	R_ResolverFlushCacheEntry
	R_DnsRegisterLocal
	R_DnsDeRegisterLocal
	R_DnsStartMulticastQuery
	R_DnsGetMulticastData
	R_DnsStopMulticastQuery
	R_ResolverSimpleOp
	R_DnsGetProxyInformation
	R_DnsGetPolicyTableInfo
	R_DnsSetConnectionPolicyInfo
	R_DnsDeleteConnectionPolicyInfo
	R_DnsGetSettings
	R_DnsGetSettingsImpHandle
	R_DnsSetSettings
	R_DnsSetSettingsImpHandle
	R_DnsGetInterfaceSettings
	R_DnsGetInterfaceSettingsImpHandle
	R_DnsSetInterfaceSettings
	R_DnsSetInterfaceSettingsImpHandle
	R_DnsGetAdaptersInfo
	R_DnsSetNrptRules
	R_DnsSetWellKnownServerProperty
	R_DnsGetWellKnownServerProperty
	R_DnsGetWellKnownServers
	R_DnsDeleteSettings
	R_DnsGetDdrInfo
```
