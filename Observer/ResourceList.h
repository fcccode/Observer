#ifndef RESOURCE_LIST_H
#define RESOURCE_LIST_H
#pragma once

#include <ntddk.h>

typedef struct _RESOURCE_LIST_ENTRY {
	LIST_ENTRY ListEntry;
	LONG RefCount;
} RESOURCE_LIST_ENTRY, *PRESOURCE_LIST_ENTRY;

typedef struct _RESOURCE_LIST_ENTRY_HEAD {
	RESOURCE_LIST_ENTRY Entry;
	KSPIN_LOCK SpinLock;
} RESOURCE_LIST_ENTRY_HEAD, *PRESOURCE_LIST_ENTRY_HEAD;

VOID InitializeListEntryHead(
	_In_ PRESOURCE_LIST_ENTRY_HEAD Head
);

VOID InsertHeadListEntry(
	_In_ PRESOURCE_LIST_ENTRY_HEAD Head,
	_In_ PRESOURCE_LIST_ENTRY Entry
);

PRESOURCE_LIST_ENTRY RemoveListEntry(
	_In_ PRESOURCE_LIST_ENTRY_HEAD Head,
	_In_ PRESOURCE_LIST_ENTRY Entry
);

PRESOURCE_LIST_ENTRY NextListEntry(
	_In_ PRESOURCE_LIST_ENTRY_HEAD Head,
	_In_ PRESOURCE_LIST_ENTRY CurrentEntry,
	_In_ BOOLEAN ReleaseCurrent
);

BOOLEAN ReleaseListEntry(
	_In_ PRESOURCE_LIST_ENTRY pEntry
);

#endif // !RESOURCE_LIST_H