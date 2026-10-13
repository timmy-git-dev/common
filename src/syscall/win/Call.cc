#include "syscall/win/Call.hh"
#include "syscall/win/Func.hh"

namespace cmn::syscall::win
{
    void *ntAcceptConnectPort;
    void *ntAccessCheck;
    void *ntAccessCheckAndAuditAlarm;
    void *ntAccessCheckByType;
    void *ntAccessCheckByTypeAndAuditAlarm;
    void *ntAccessCheckByTypeResultList;
    void *ntAccessCheckByTypeResultListAndAuditAlarm;
    void *ntAccessCheckByTypeResultListAndAuditAlarmByHandle;
    void *ntAcquireCrossVmMutant;
    void *ntAcquireProcessActivityReference;
    void *ntAddAtom;
    void *ntAddAtomEx;
    void *ntAddBootEntry;
    void *ntAddDriverEntry;
    void *ntAdjustGroupsToken;
    void *ntAdjustPrivilegesToken;
    void *ntAdjustTokenClaimsAndDeviceGroups;
    void *ntAlertMultipleThreadByThreadId;
    void *ntAlertResumeThread;
    void *ntAlertThread;
    void *ntAlertThreadByThreadId;
    void *ntAlertThreadByThreadIdEx;
    void *ntAllocateLocallyUniqueId;
    void *ntAllocateReserveObject;
    void *ntAllocateUserPhysicalPages;
    void *ntAllocateUserPhysicalPagesEx;
    void *ntAllocateUuids;
    void *ntAllocateVirtualMemory;
    void *ntAllocateVirtualMemoryEx;
    void *ntAlpcAcceptConnectPort;
    void *ntAlpcCancelMessage;
    void *ntAlpcConnectPort;
    void *ntAlpcConnectPortEx;
    void *ntAlpcCreatePort;
    void *ntAlpcCreatePortSection;
    void *ntAlpcCreateResourceReserve;
    void *ntAlpcCreateSectionView;
    void *ntAlpcCreateSecurityContext;
    void *ntAlpcDeletePortSection;
    void *ntAlpcDeleteResourceReserve;
    void *ntAlpcDeleteSectionView;
    void *ntAlpcDeleteSecurityContext;
    void *ntAlpcDisconnectPort;
    void *ntAlpcImpersonateClientContainerOfPort;
    void *ntAlpcImpersonateClientOfPort;
    void *ntAlpcOpenSenderProcess;
    void *ntAlpcOpenSenderThread;
    void *ntAlpcQueryInformation;
    void *ntAlpcQueryInformationMessage;
    void *ntAlpcRevokeSecurityContext;
    void *ntAlpcSendWaitReceivePort;
    void *ntAlpcSetInformation;
    void *ntApphelpCacheControl;
    void *ntAreMappedFilesTheSame;
    void *ntAssignProcessToJobObject;
    void *ntAssociateWaitCompletionPacket;
    void *ntCallEnclave;
    void *ntCallbackReturn;
    void *ntCancelIoFile;
    void *ntCancelIoFileEx;
    void *ntCancelSynchronousIoFile;
    void *ntCancelTimer;
    void *ntCancelTimer2;
    void *ntCancelWaitCompletionPacket;
    void *ntChangeProcessState;
    void *ntChangeThreadState;
    void *ntClearEvent;
    void *ntClose;
    void *ntCloseObjectAuditAlarm;
    void *ntCommitComplete;
    void *ntCommitEnlistment;
    void *ntCommitRegistryTransaction;
    void *ntCommitTransaction;
    void *ntCompactKeys;
    void *ntCompareObjects;
    void *ntCompareSigningLevels;
    void *ntCompareTokens;
    void *ntCompleteConnectPort;
    void *ntCompressKey;
    void *ntConnectPort;
    void *ntContinue;
    void *ntContinueEx;
    void *ntConvertBetweenAuxiliaryCounterAndPerformanceCounter;
    void *ntCopyFileChunk;
    void *ntCreateCpuPartition;
    void *ntCreateCrossVmEvent;
    void *ntCreateCrossVmMutant;
    void *ntCreateDebugObject;
    void *ntCreateDirectoryObject;
    void *ntCreateDirectoryObjectEx;
    void *ntCreateEnclave;
    void *ntCreateEnlistment;
    void *ntCreateEvent;
    void *ntCreateEventPair;
    void *ntCreateFile;
    void *ntCreateIRTimer;
    void *ntCreateIoCompletion;
    void *ntCreateIoRing;
    void *ntCreateJobObject;
    void *ntCreateJobSet;
    void *ntCreateKey;
    void *ntCreateKeyTransacted;
    void *ntCreateKeyedEvent;
    void *ntCreateLowBoxToken;
    void *ntCreateMailslotFile;
    void *ntCreateMutant;
    void *ntCreateNamedPipeFile;
    void *ntCreatePagingFile;
    void *ntCreatePartition;
    void *ntCreatePort;
    void *ntCreatePrivateNamespace;
    void *ntCreateProcess;
    void *ntCreateProcessEx;
    void *ntCreateProcessStateChange;
    void *ntCreateProfile;
    void *ntCreateProfileEx;
    void *ntCreateRegistryTransaction;
    void *ntCreateResourceManager;
    void *ntCreateSection;
    void *ntCreateSectionEx;
    void *ntCreateSemaphore;
    void *ntCreateSymbolicLinkObject;
    void *ntCreateThread;
    void *ntCreateThreadEx;
    void *ntCreateThreadStateChange;
    void *ntCreateTimer;
    void *ntCreateTimer2;
    void *ntCreateToken;
    void *ntCreateTokenEx;
    void *ntCreateTransaction;
    void *ntCreateTransactionManager;
    void *ntCreateUserProcess;
    void *ntCreateWaitCompletionPacket;
    void *ntCreateWaitablePort;
    void *ntCreateWnfStateName;
    void *ntCreateWorkerFactory;
    void *ntDebugActiveProcess;
    void *ntDebugContinue;
    void *ntDelayExecution;
    void *ntDeleteAtom;
    void *ntDeleteBootEntry;
    void *ntDeleteDriverEntry;
    void *ntDeleteFile;
    void *ntDeleteKey;
    void *ntDeleteObjectAuditAlarm;
    void *ntDeletePrivateNamespace;
    void *ntDeleteValueKey;
    void *ntDeleteWnfStateData;
    void *ntDeleteWnfStateName;
    void *ntDeviceIoControlFile;
    void *ntDirectGraphicsCall;
    void *ntDisableLastKnownGood;
    void *ntDisplayString;
    void *ntDrawText;
    void *ntDuplicateObject;
    void *ntDuplicateToken;
    void *ntEnableLastKnownGood;
    void *ntEnumerateBootEntries;
    void *ntEnumerateDriverEntries;
    void *ntEnumerateKey;
    void *ntEnumerateSystemEnvironmentValuesEx;
    void *ntEnumerateTransactionObject;
    void *ntEnumerateValueKey;
    void *ntExtendSection;
    void *ntFilterBootOption;
    void *ntFilterToken;
    void *ntFilterTokenEx;
    void *ntFindAtom;
    void *ntFlushBuffersFile;
    void *ntFlushBuffersFileEx;
    void *ntFlushInstallUILanguage;
    void *ntFlushInstructionCache;
    void *ntFlushKey;
    void *ntFlushProcessWriteBuffers;
    void *ntFlushVirtualMemory;
    void *ntFlushWriteBuffer;
    void *ntFreeUserPhysicalPages;
    void *ntFreeVirtualMemory;
    void *ntFreezeRegistry;
    void *ntFreezeTransactions;
    void *ntFsControlFile;
    void *ntGetCachedSigningLevel;
    void *ntGetCompleteWnfStateSubscription;
    void *ntGetContextThread;
    void *ntGetCurrentProcessorNumber;
    void *ntGetCurrentProcessorNumberEx;
    void *ntGetDevicePowerState;
    void *ntGetMUIRegistryInfo;
    void *ntGetNextProcess;
    void *ntGetNextThread;
    void *ntGetNlsSectionPtr;
    void *ntGetNotificationResourceManager;
    void *ntGetTickCount;
    void *ntGetTickCount64;
    void *ntGetWriteWatch;
    void *ntImpersonateAnonymousToken;
    void *ntImpersonateClientOfPort;
    void *ntImpersonateThread;
    void *ntInitializeEnclave;
    void *ntInitializeNlsFiles;
    void *ntInitializeRegistry;
    void *ntInitiatePowerAction;
    void *ntIsProcessInJob;
    void *ntIsSystemResumeAutomatic;
    void *ntIsUILanguageComitted;
    void *ntListenPort;
    void *ntLoadDriver;
    void *ntLoadEnclaveData;
    void *ntLoadKey;
    void *ntLoadKey2;
    void *ntLoadKey3;
    void *ntLoadKeyEx;
    void *ntLockFile;
    void *ntLockProductActivationKeys;
    void *ntLockRegistryKey;
    void *ntLockVirtualMemory;
    void *ntMakePermanentObject;
    void *ntMakeTemporaryObject;
    void *ntManageHotPatch;
    void *ntManagePartition;
    void *ntMapCMFModule;
    void *ntMapUserPhysicalPages;
    void *ntMapUserPhysicalPagesScatter;
    void *ntMapViewOfSection;
    void *ntMapViewOfSectionEx;
    void *ntModifyBootEntry;
    void *ntModifyDriverEntry;
    void *ntNotifyChangeDirectoryFile;
    void *ntNotifyChangeDirectoryFileEx;
    void *ntNotifyChangeKey;
    void *ntNotifyChangeMultipleKeys;
    void *ntNotifyChangeSession;
    void *ntOpenCpuPartition;
    void *ntOpenDirectoryObject;
    void *ntOpenEnlistment;
    void *ntOpenEvent;
    void *ntOpenEventPair;
    void *ntOpenFile;
    void *ntOpenIoCompletion;
    void *ntOpenJobObject;
    void *ntOpenKey;
    void *ntOpenKeyEx;
    void *ntOpenKeyTransacted;
    void *ntOpenKeyTransactedEx;
    void *ntOpenKeyedEvent;
    void *ntOpenMutant;
    void *ntOpenObjectAuditAlarm;
    void *ntOpenPartition;
    void *ntOpenPrivateNamespace;
    void *ntOpenProcess;
    void *ntOpenProcessToken;
    void *ntOpenProcessTokenEx;
    void *ntOpenRegistryTransaction;
    void *ntOpenResourceManager;
    void *ntOpenSection;
    void *ntOpenSemaphore;
    void *ntOpenSession;
    void *ntOpenSymbolicLinkObject;
    void *ntOpenThread;
    void *ntOpenThreadToken;
    void *ntOpenThreadTokenEx;
    void *ntOpenTimer;
    void *ntOpenTransaction;
    void *ntOpenTransactionManager;
    void *ntPlugPlayControl;
    void *ntPowerInformation;
    void *ntPrePrepareComplete;
    void *ntPrePrepareEnlistment;
    void *ntPrepareComplete;
    void *ntPrepareEnlistment;
    void *ntPrivilegeCheck;
    void *ntPrivilegeObjectAuditAlarm;
    void *ntPrivilegedServiceAuditAlarm;
    void *ntPropagationComplete;
    void *ntPropagationFailed;
    void *ntProtectVirtualMemory;
    void *ntPssCaptureVaSpaceBulk;
    void *ntPulseEvent;
    void *ntQueryAttributesFile;
    void *ntQueryAuxiliaryCounterFrequency;
    void *ntQueryBootEntryOrder;
    void *ntQueryBootOptions;
    void *ntQueryDebugFilterState;
    void *ntQueryDefaultLocale;
    void *ntQueryDefaultUILanguage;
    void *ntQueryDirectoryFile;
    void *ntQueryDirectoryFileEx;
    void *ntQueryDirectoryObject;
    void *ntQueryDriverEntryOrder;
    void *ntQueryEaFile;
    void *ntQueryEvent;
    void *ntQueryFullAttributesFile;
    void *ntQueryInformationAtom;
    void *ntQueryInformationByName;
    void *ntQueryInformationCpuPartition;
    void *ntQueryInformationEnlistment;
    void *ntQueryInformationFile;
    void *ntQueryInformationJobObject;
    void *ntQueryInformationPort;
    void *ntQueryInformationProcess;
    void *ntQueryInformationResourceManager;
    void *ntQueryInformationThread;
    void *ntQueryInformationToken;
    void *ntQueryInformationTransaction;
    void *ntQueryInformationTransactionManager;
    void *ntQueryInformationWorkerFactory;
    void *ntQueryInstallUILanguage;
    void *ntQueryIntervalProfile;
    void *ntQueryIoCompletion;
    void *ntQueryIoRingCapabilities;
    void *ntQueryKey;
    void *ntQueryLicenseValue;
    void *ntQueryMultipleValueKey;
    void *ntQueryMutant;
    void *ntQueryObject;
    void *ntQueryOpenSubKeys;
    void *ntQueryOpenSubKeysEx;
    void *ntQueryPerformanceCounter;
    void *ntQueryPortInformationProcess;
    void *ntQueryQuotaInformationFile;
    void *ntQuerySection;
    void *ntQuerySecurityAttributesToken;
    void *ntQuerySecurityObject;
    void *ntQuerySecurityPolicy;
    void *ntQuerySemaphore;
    void *ntQuerySymbolicLinkObject;
    void *ntQuerySystemEnvironmentValue;
    void *ntQuerySystemEnvironmentValueEx;
    void *ntQuerySystemInformation;
    void *ntQuerySystemInformationEx;
    void *ntQuerySystemTime;
    void *ntQueryTimer;
    void *ntQueryTimerResolution;
    void *ntQueryValueKey;
    void *ntQueryVirtualMemory;
    void *ntQueryVolumeInformationFile;
    void *ntQueryWnfStateData;
    void *ntQueryWnfStateNameInformation;
    void *ntQueueApcThread;
    void *ntQueueApcThreadEx;
    void *ntQueueApcThreadEx2;
    void *ntRaiseException;
    void *ntReadFile;
    void *ntReadFileScatter;
    void *ntReadOnlyEnlistment;
    void *ntReadRequestData;
    void *ntReadVirtualMemory;
    void *ntReadVirtualMemoryEx;
    void *ntRecoverEnlistment;
    void *ntRecoverResourceManager;
    void *ntRecoverTransactionManager;
    void *ntRegisterProtocolAddressInformation;
    void *ntRegisterThreadTerminatePort;
    void *ntReleaseKeyedEvent;
    void *ntReleaseMutant;
    void *ntReleaseSemaphore;
    void *ntReleaseWorkerFactoryWorker;
    void *ntRemoveIoCompletion;
    void *ntRemoveIoCompletionEx;
    void *ntRemoveProcessDebug;
    void *ntRenameKey;
    void *ntRenameTransactionManager;
    void *ntReplaceKey;
    void *ntReplacePartitionUnit;
    void *ntReplyPort;
    void *ntReplyWaitReceivePort;
    void *ntReplyWaitReceivePortEx;
    void *ntReplyWaitReplyPort;
    void *ntRequestPort;
    void *ntRequestWaitReplyPort;
    void *ntResetEvent;
    void *ntResetWriteWatch;
    void *ntRestoreKey;
    void *ntResumeProcess;
    void *ntResumeThread;
    void *ntRevertContainerImpersonation;
    void *ntRollbackComplete;
    void *ntRollbackEnlistment;
    void *ntRollbackRegistryTransaction;
    void *ntRollbackTransaction;
    void *ntRollforwardTransactionManager;
    void *ntSaveKey;
    void *ntSaveKeyEx;
    void *ntSaveMergedKeys;
    void *ntSecureConnectPort;
    void *ntSerializeBoot;
    void *ntSetBootEntryOrder;
    void *ntSetBootOptions;
    void *ntSetCachedSigningLevel;
    void *ntSetCachedSigningLevel2;
    void *ntSetContextThread;
    void *ntSetDebugFilterState;
    void *ntSetDefaultHardErrorPort;
    void *ntSetDefaultLocale;
    void *ntSetDefaultUILanguage;
    void *ntSetDriverEntryOrder;
    void *ntSetEaFile;
    void *ntSetEvent;
    void *ntSetEventBoostPriority;
    void *ntSetEventEx;
    void *ntSetHighEventPair;
    void *ntSetHighWaitLowEventPair;
    void *ntSetIRTimer;
    void *ntSetInformationCpuPartition;
    void *ntSetInformationDebugObject;
    void *ntSetInformationEnlistment;
    void *ntSetInformationFile;
    void *ntSetInformationIoRing;
    void *ntSetInformationJobObject;
    void *ntSetInformationKey;
    void *ntSetInformationObject;
    void *ntSetInformationProcess;
    void *ntSetInformationResourceManager;
    void *ntSetInformationSymbolicLink;
    void *ntSetInformationThread;
    void *ntSetInformationToken;
    void *ntSetInformationTransaction;
    void *ntSetInformationTransactionManager;
    void *ntSetInformationVirtualMemory;
    void *ntSetInformationWorkerFactory;
    void *ntSetIntervalProfile;
    void *ntSetIoCompletion;
    void *ntSetIoCompletionEx;
    void *ntSetLdtEntries;
    void *ntSetLowEventPair;
    void *ntSetLowWaitHighEventPair;
    void *ntSetQuotaInformationFile;
    void *ntSetSecurityObject;
    void *ntSetSystemEnvironmentValue;
    void *ntSetSystemEnvironmentValueEx;
    void *ntSetSystemInformation;
    void *ntSetSystemPowerState;
    void *ntSetSystemTime;
    void *ntSetThreadExecutionState;
    void *ntSetTimer;
    void *ntSetTimer2;
    void *ntSetTimerEx;
    void *ntSetTimerResolution;
    void *ntSetUuidSeed;
    void *ntSetValueKey;
    void *ntSetVolumeInformationFile;
    void *ntSetWnfProcessNotificationEvent;
    void *ntShutdownSystem;
    void *ntShutdownWorkerFactory;
    void *ntSignalAndWaitForSingleObject;
    void *ntSinglePhaseReject;
    void *ntStartProfile;
    void *ntStopProfile;
    void *ntSubmitIoRing;
    void *ntSubscribeWnfStateChange;
    void *ntSuspendProcess;
    void *ntSuspendThread;
    void *ntSystemDebugControl;
    void *ntTerminateEnclave;
    void *ntTerminateJobObject;
    void *ntTerminateProcess;
    void *ntTerminateThread;
    void *ntTestAlert;
    void *ntThawRegistry;
    void *ntThawTransactions;
    void *ntTraceControl;
    void *ntTraceEvent;
    void *ntTranslateFilePath;
    void *ntUmsThreadYield;
    void *ntUnloadDriver;
    void *ntUnloadKey;
    void *ntUnloadKey2;
    void *ntUnloadKeyEx;
    void *ntUnlockFile;
    void *ntUnlockVirtualMemory;
    void *ntUnmapViewOfSection;
    void *ntUnmapViewOfSectionEx;
    void *ntUnsubscribeWnfStateChange;
    void *ntUpdateWnfStateData;
    void *ntUserAllowForegroundActivation;
    void *ntUserAllowSetForegroundWindow;
    void *ntUserArrangeIconicWindows;
    void *ntUserAttachThreadInput;
    void *ntUserBeginDeferWindowPos;
    void *ntUserBeginPaint;
    void *ntUserBlockInput;
    void *ntUserBringWindowToTop;
    void *ntUserBroadcastImeShowStatusChange;
    void *ntUserBuildHwndList;
    void *ntUserBuildNameList;
    void *ntUserBuildPropList;
    void *ntUserCalculatePopupWindowPosition;
    void *ntUserCallHwnd;
    void *ntUserCallHwndLock;
    void *ntUserCallHwndLockSafe;
    void *ntUserCallHwndOpt;
    void *ntUserCallHwndParam;
    void *ntUserCallHwndParamLock;
    void *ntUserCallHwndParamLockSafe;
    void *ntUserCallHwndSafe;
    void *ntUserCallNoParam;
    void *ntUserCallOneParam;
    void *ntUserCallTwoParam;
    void *ntUserCanCurrentThreadChangeForeground;
    void *ntUserCancelQueueEventCompletionPacket;
    void *ntUserChangeWindowMessageFilter;
    void *ntUserCheckAccessForIntegrityLevel;
    void *ntUserCheckImeShowStatusInThread;
    void *ntUserCheckProcessForClipboardAccess;
    void *ntUserChildWindowFromPointEx;
    void *ntUserCitSetInfo;
    void *ntUserClearWakeMask;
    void *ntUserClearWindowState;
    void *ntUserClipCursor;
    void *ntUserCloseDesktop;
    void *ntUserCloseWindowStation;
    void *ntUserConsoleControl;
    void *ntUserCopyAcceleratorTable;
    void *ntUserCreateAcceleratorTable;
    void *ntUserCreateMenu;
    void *ntUserCreatePopupMenu;
    void *ntUserCreateSystemThreads;
    void *ntUserCreateWindowStation;
    void *ntUserCsDdeUninitialize;
    void *ntUserDWP_GetEnabledPopupOffset;
    void *ntUserDeferredDesktopRotation;
    void *ntUserDeleteMenu;
    void *ntUserDeregisterShellHookWindow;
    void *ntUserDestroyCaret;
    void *ntUserDestroyMenu;
    void *ntUserDestroyWindow;
    void *ntUserDisableProcessWindowFiltering;
    void *ntUserDisableProcessWindowsGhosting;
    void *ntUserDoInitMessagePumpHook;
    void *ntUserDoUninitMessagePumpHook;
    void *ntUserDragDetect;
    void *ntUserDragObject;
    void *ntUserDrainThreadCoreMessagingCompletions;
    void *ntUserDrawAnimatedRects;
    void *ntUserDrawMenuBar;
    void *ntUserDwmLockScreenUpdates;
    void *ntUserEnableModernAppWindowKeyboardIntercept;
    void *ntUserEnableMouseInPointerForThread;
    void *ntUserEnablePerMonitorMenuScaling;
    void *ntUserEnableSessionForMMCSS;
    void *ntUserEnableShellWindowManagementBehavior;
    void *ntUserEnableWindow;
    void *ntUserEndMenu;
    void *ntUserEndPaint;
    void *ntUserEnsureDpiDepSysMetCacheForPlateau;
    void *ntUserEnumClipboardFormats;
    void *ntUserEnumDisplayMonitors;
    void *ntUserExcludeUpdateRgn;
    void *ntUserFindWindowEx;
    void *ntUserFlashWindowEx;
    void *ntUserForceEnableNumpadTranslation;
    void *ntUserGetAncestor;
    void *ntUserGetCaretBlinkTime;
    void *ntUserGetCaretPos;
    void *ntUserGetClassIcoCur;
    void *ntUserGetClassName;
    void *ntUserGetClipCursor;
    void *ntUserGetComboBoxInfo;
    void *ntUserGetCurrentInputMessageSource;
    void *ntUserGetCursor;
    void *ntUserGetCursorInfo;
    void *ntUserGetCursorPos;
    void *ntUserGetDCEx;
    void *ntUserGetDeviceChangeInfo;
    void *ntUserGetDisplayAutoRotationPreferences;
    void *ntUserGetDoubleClickTime;
    void *ntUserGetForegroundWindow;
    void *ntUserGetGUIThreadInfo;
    void *ntUserGetGuiResources;
    void *ntUserGetIMEShowStatus;
    void *ntUserGetIconInfo;
    void *ntUserGetIconSize;
    void *ntUserGetInputDesktop;
    void *ntUserGetInputEvent;
    void *ntUserGetKeyboardType;
    void *ntUserGetLayeredWindowAttributes;
    void *ntUserGetListBoxInfo;
    void *ntUserGetMenuBarInfo;
    void *ntUserGetMenuItemRect;
    void *ntUserGetMessagePos;
    void *ntUserGetModernAppWindow;
    void *ntUserGetMouseMovePointsEx;
    void *ntUserGetObjectInformation;
    void *ntUserGetProcessDefaultLayout;
    void *ntUserGetProcessUIContextInformation;
    void *ntUserGetProcessWindowStation;
    void *ntUserGetProp;
    void *ntUserGetProp2;
    void *ntUserGetQueueIocp;
    void *ntUserGetRawInputData;
    void *ntUserGetRawInputDeviceList;
    void *ntUserGetRegisteredRawInputDevices;
    void *ntUserGetSendMessageReceiver;
    void *ntUserGetSysMenuOffset;
    void *ntUserGetSystemMenu;
    void *ntUserGetThreadDesktop;
    void *ntUserGetThreadState;
    void *ntUserGetTitleBarInfo;
    void *ntUserGetUnpredictedMessagePos;
    void *ntUserGetWinStationInfo;
    void *ntUserGetWindowContextHelpId;
    void *ntUserGetWindowDC;
    void *ntUserGetWindowPlacement;
    void *ntUserGetWindowProcessHandle;
    void *ntUserGetWindowTrackInfoAsync;
    void *ntUserGhostWindowFromHungWindow;
    void *ntUserHandleSystemThreadCreationFailure;
    void *ntUserHideCursorNoCapture;
    void *ntUserHiliteMenuItem;
    void *ntUserHungWindowFromGhostWindow;
    void *ntUserInitAnsiOem;
    void *ntUserInitThreadCoreMessagingIocp;
    void *ntUserInternalGetWindowIcon;
    void *ntUserInternalGetWindowText;
    void *ntUserInvalidateRect;
    void *ntUserInvalidateRgn;
    void *ntUserIsQueueAttached;
    void *ntUserIsTouchWindow;
    void *ntUserKillSystemTimer;
    void *ntUserKillTimer;
    void *ntUserLW_LoadFonts;
    void *ntUserLoadCursorsAndIcons;
    void *ntUserLoadUserApiHook;
    void *ntUserLockSetForegroundWindow;
    void *ntUserLockWorkStation;
    void *ntUserLogicalToPhysicalPoint;
    void *ntUserMapDesktopObject;
    void *ntUserMenuItemFromPoint;
    void *ntUserMessageBeep;
    void *ntUserMoveWindow;
    void *ntUserNlsKbdSendIMENotification;
    void *ntUserNotifyOverlayWindow;
    void *ntUserOpenDesktop;
    void *ntUserOpenInputDesktop;
    void *ntUserOpenWindowStation;
    void *ntUserPhysicalToLogicalPoint;
    void *ntUserPlayEventSound;
    void *ntUserPostQuitMessage;
    void *ntUserPrepareForLogoff;
    void *ntUserPrintWindow;
    void *ntUserQueryInformationThread;
    void *ntUserQuerySendMessage;
    void *ntUserQueryWindow;
    void *ntUserRaiseLowerShellWindow;
    void *ntUserRealChildWindowFromPoint;
    void *ntUserRealizePalette;
    void *ntUserReassociateQueueEventCompletionPacket;
    void *ntUserRedrawFrame;
    void *ntUserRedrawFrameAndHook;
    void *ntUserRedrawTitle;
    void *ntUserRedrawWindow;
    void *ntUserRegisterCloakedNotification;
    void *ntUserRegisterGhostWindow;
    void *ntUserRegisterHotKey;
    void *ntUserRegisterLPK;
    void *ntUserRegisterLogonProcess;
    void *ntUserRegisterShellHookWindow;
    void *ntUserRegisterSiblingFrostWindow;
    void *ntUserRegisterSystemThread;
    void *ntUserRegisterUserHungAppHandlers;
    void *ntUserRegisterWindowArrangementCallout;
    void *ntUserReleaseCapture;
    void *ntUserRemoteConnectState;
    void *ntUserRemoteConsoleShadowStop;
    void *ntUserRemoteDisconnect;
    void *ntUserRemoteNotify;
    void *ntUserRemotePassthruDisable;
    void *ntUserRemotePassthruEnable;
    void *ntUserRemoteReconnect;
    void *ntUserRemoteShadowCleanup;
    void *ntUserRemoteShadowSetup;
    void *ntUserRemoteShadowStart;
    void *ntUserRemoteShadowStop;
    void *ntUserRemoteThinwireStats;
    void *ntUserRemoveMenu;
    void *ntUserRemoveQueueCompletion;
    void *ntUserReplyMessage;
    void *ntUserResetDblClk;
    void *ntUserScaleSystemMetricForDPIWithoutCache;
    void *ntUserScheduleDispatchNotification;
    void *ntUserSendInput;
    void *ntUserSetActiveWindow;
    void *ntUserSetAdditionalForegroundBoostProcesses;
    void *ntUserSetAdditionalPowerThrottlingProcess;
    void *ntUserSetCancelRotationDelayHintWindow;
    void *ntUserSetCapture;
    void *ntUserSetCaretBlinkTime;
    void *ntUserSetCaretPos;
    void *ntUserSetChildWindowNoActivate;
    void *ntUserSetClassWord;
    void *ntUserSetCursorPos;
    void *ntUserSetDialogPointer;
    void *ntUserSetDialogSystemMenu;
    void *ntUserSetDoubleClickTime;
    void *ntUserSetFocus;
    void *ntUserSetForegroundWindow;
    void *ntUserSetForegroundWindowForApplication;
    void *ntUserSetInformationThread;
    void *ntUserSetLayeredWindowAttributes;
    void *ntUserSetMessageExtraInfo;
    void *ntUserSetModernAppWindow;
    void *ntUserSetMsgBox;
    void *ntUserSetProcessDefaultLayout;
    void *ntUserSetProcessRestrictionExemption;
    void *ntUserSetProcessUIAccessZorder;
    void *ntUserSetProcessWin32Capabilities;
    void *ntUserSetProcessWindowStation;
    void *ntUserSetProgmanWindow;
    void *ntUserSetShellChangeNotifyHWND;
    void *ntUserSetSysMenu;
    void *ntUserSetTSFEventState;
    void *ntUserSetTaskmanWindow;
    void *ntUserSetThreadDesktop;
    void *ntUserSetThreadQueueMergeSetting;
    void *ntUserSetTimer;
    void *ntUserSetVisible;
    void *ntUserSetWaitForQueueAttach;
    void *ntUserSetWatermarkStrings;
    void *ntUserSetWindowContextHelpId;
    void *ntUserSetWindowPlacement;
    void *ntUserSetWindowPos;
    void *ntUserSetWindowState;
    void *ntUserSetWindowStationUser;
    void *ntUserSetWindowWord;
    void *ntUserShellForegroundBoostProcess;
    void *ntUserShowCursor;
    void *ntUserShowOwnedPopups;
    void *ntUserShowStartGlass;
    void *ntUserShowWindow;
    void *ntUserShowWindowAsync;
    void *ntUserShutdownBlockReasonQuery;
    void *ntUserShutdownReasonDestroy;
    void *ntUserSwapMouseButton;
    void *ntUserSwitchDesktop;
    void *ntUserSwitchToThisWindow;
    void *ntUserTestForInteractiveUser;
    void *ntUserThreadMessageQueueAttached;
    void *ntUserTrackMouseEvent;
    void *ntUserTrackPopupMenuEx;
    void *ntUserUnhookWinEvent;
    void *ntUserUnhookWindowsHook;
    void *ntUserUnregisterHotKey;
    void *ntUserUpdateClientRect;
    void *ntUserUpdatePerUserImmEnabling;
    void *ntUserUpdateWindow;
    void *ntUserUpdateWindows;
    void *ntUserUserHandleGrantAccess;
    void *ntUserUserPowerCalloutWorker;
    void *ntUserValidateRect;
    void *ntUserValidateRgn;
    void *ntUserWOWModuleUnload;
    void *ntUserWakeRITForShutdown;
    void *ntUserWindowFromDC;
    void *ntUserWindowFromPhysicalPoint;
    void *ntUserWindowFromPoint;
    void *ntUserZapActiveAndFocus;
    void *ntVdmControl;
    void *ntWaitForAlertByThreadId;
    void *ntWaitForDebugEvent;
    void *ntWaitForKeyedEvent;
    void *ntWaitForMultipleObjects;
    void *ntWaitForMultipleObjects32;
    void *ntWaitForSingleObject;
    void *ntWaitForWorkViaWorkerFactory;
    void *ntWaitHighEventPair;
    void *ntWaitLowEventPair;
    void *ntWorkerFactoryWorkerReady;
    void *ntWow64GetNativeSystemInformation;
    void *ntWow64QueryInformationProcess64;
    void *ntWow64QueryVirtualMemory64;
    void *ntWow64ReadVirtualMemory64;
    void *ntWow64WriteVirtualMemory64;
    void *ntWriteFile;
    void *ntWriteFileGather;
    void *ntWriteRequestData;
    void *ntWriteVirtualMemory;
    void *ntYieldExecution;

    NTSTATUS NtacceptConnectPort(PHANDLE _portHandle, PVOID _portContext, PPORT_MESSAGE _connectionRequest, BOOLEAN _acceptConnection, PPORT_VIEW _serverView, PREMOTE_PORT_VIEW _clientView)
    {
        if (!ntAcceptConnectPort) ntAcceptConnectPort = win_::resolve_proc_address("NtAcceptConnectPort", 19);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, PVOID, PPORT_MESSAGE, BOOLEAN, PPORT_VIEW, PREMOTE_PORT_VIEW)>(ntAcceptConnectPort)(_portHandle, _portContext, _connectionRequest, _acceptConnection, _serverView, _clientView);
    }
    NTSTATUS NtaccessCheck(PSECURITY_DESCRIPTOR _securityDescriptor, HANDLE _clientToken, ACCESS_MASK _desiredAccess, PGENERIC_MAPPING _genericMapping, PPRIVILEGE_SET _privilegeSet, PULONG _privilegeSetLength, PACCESS_MASK _grantedAccess, PNTSTATUS _accessStatus)
    {
        if (!ntAccessCheck) ntAccessCheck = win_::resolve_proc_address("NtAccessCheck", 13);
        return reinterpret_cast<NTSTATUS(*)(PSECURITY_DESCRIPTOR, HANDLE, ACCESS_MASK, PGENERIC_MAPPING, PPRIVILEGE_SET, PULONG, PACCESS_MASK, PNTSTATUS)>(ntAccessCheck)(_securityDescriptor, _clientToken, _desiredAccess, _genericMapping, _privilegeSet, _privilegeSetLength, _grantedAccess, _accessStatus);
    }
    NTSTATUS NtaccessCheckAndAuditAlarm(PCUNICODE_STRING _subsystemName, PVOID _handleId, PCUNICODE_STRING _objectTypeName, PCUNICODE_STRING _objectName, PSECURITY_DESCRIPTOR _securityDescriptor, ACCESS_MASK _desiredAccess, PGENERIC_MAPPING _genericMapping, BOOLEAN _objectCreation, PACCESS_MASK _grantedAccess, PNTSTATUS _accessStatus, PBOOLEAN _generateOnClose)
    {
        if (!ntAccessCheckAndAuditAlarm) ntAccessCheckAndAuditAlarm = win_::resolve_proc_address("NtAccessCheckAndAuditAlarm", 26);
        return reinterpret_cast<NTSTATUS(*)(PCUNICODE_STRING, PVOID, PCUNICODE_STRING, PCUNICODE_STRING, PSECURITY_DESCRIPTOR, ACCESS_MASK, PGENERIC_MAPPING, BOOLEAN, PACCESS_MASK, PNTSTATUS, PBOOLEAN)>(ntAccessCheckAndAuditAlarm)(_subsystemName, _handleId, _objectTypeName, _objectName, _securityDescriptor, _desiredAccess, _genericMapping, _objectCreation, _grantedAccess, _accessStatus, _generateOnClose);
    }
    NTSTATUS NtaccessCheckByType(PSECURITY_DESCRIPTOR _securityDescriptor, PSID _principalSelfSid, HANDLE _clientToken, ACCESS_MASK _desiredAccess, POBJECT_TYPE_LIST _objectTypeList, ULONG _objectTypeListLength, PGENERIC_MAPPING _genericMapping, PPRIVILEGE_SET _privilegeSet, PULONG _privilegeSetLength, PACCESS_MASK _grantedAccess, PNTSTATUS _accessStatus)
    {
        if (!ntAccessCheckByType) ntAccessCheckByType = win_::resolve_proc_address("NtAccessCheckByType", 19);
        return reinterpret_cast<NTSTATUS(*)(PSECURITY_DESCRIPTOR, PSID, HANDLE, ACCESS_MASK, POBJECT_TYPE_LIST, ULONG, PGENERIC_MAPPING, PPRIVILEGE_SET, PULONG, PACCESS_MASK, PNTSTATUS)>(ntAccessCheckByType)(_securityDescriptor, _principalSelfSid, _clientToken, _desiredAccess, _objectTypeList, _objectTypeListLength, _genericMapping, _privilegeSet, _privilegeSetLength, _grantedAccess, _accessStatus);
    }
    NTSTATUS NtaccessCheckByTypeAndAuditAlarm(PCUNICODE_STRING _subsystemName, PVOID _handleId, PCUNICODE_STRING _objectTypeName, PCUNICODE_STRING _objectName, PSECURITY_DESCRIPTOR _securityDescriptor, PSID _principalSelfSid, ACCESS_MASK _desiredAccess, AUDIT_EVENT_TYPE _auditType, ULONG _flags, POBJECT_TYPE_LIST _objectTypeList, ULONG _objectTypeListLength, PGENERIC_MAPPING _genericMapping, BOOLEAN _objectCreation, PACCESS_MASK _grantedAccess, PNTSTATUS _accessStatus, PBOOLEAN _generateOnClose)
    {
        if (!ntAccessCheckByTypeAndAuditAlarm) ntAccessCheckByTypeAndAuditAlarm = win_::resolve_proc_address("NtAccessCheckByTypeAndAuditAlarm", 32);
        return reinterpret_cast<NTSTATUS(*)(PCUNICODE_STRING, PVOID, PCUNICODE_STRING, PCUNICODE_STRING, PSECURITY_DESCRIPTOR, PSID, ACCESS_MASK, AUDIT_EVENT_TYPE, ULONG, POBJECT_TYPE_LIST, ULONG, PGENERIC_MAPPING, BOOLEAN, PACCESS_MASK, PNTSTATUS, PBOOLEAN)>(ntAccessCheckByTypeAndAuditAlarm)(_subsystemName, _handleId, _objectTypeName, _objectName, _securityDescriptor, _principalSelfSid, _desiredAccess, _auditType, _flags, _objectTypeList, _objectTypeListLength, _genericMapping, _objectCreation, _grantedAccess, _accessStatus, _generateOnClose);
    }
    NTSTATUS NtaccessCheckByTypeResultList(PSECURITY_DESCRIPTOR _securityDescriptor, PSID _principalSelfSid, HANDLE _clientToken, ACCESS_MASK _desiredAccess, POBJECT_TYPE_LIST _objectTypeList, ULONG _objectTypeListLength, PGENERIC_MAPPING _genericMapping, PPRIVILEGE_SET _privilegeSet, PULONG _privilegeSetLength, PACCESS_MASK _grantedAccess, PNTSTATUS _accessStatus)
    {
        if (!ntAccessCheckByTypeResultList) ntAccessCheckByTypeResultList = win_::resolve_proc_address("NtAccessCheckByTypeResultList", 29);
        return reinterpret_cast<NTSTATUS(*)(PSECURITY_DESCRIPTOR, PSID, HANDLE, ACCESS_MASK, POBJECT_TYPE_LIST, ULONG, PGENERIC_MAPPING, PPRIVILEGE_SET, PULONG, PACCESS_MASK, PNTSTATUS)>(ntAccessCheckByTypeResultList)(_securityDescriptor, _principalSelfSid, _clientToken, _desiredAccess, _objectTypeList, _objectTypeListLength, _genericMapping, _privilegeSet, _privilegeSetLength, _grantedAccess, _accessStatus);
    }
    NTSTATUS NtaccessCheckByTypeResultListAndAuditAlarm(PCUNICODE_STRING _subsystemName, PVOID _handleId, PCUNICODE_STRING _objectTypeName, PCUNICODE_STRING _objectName, PSECURITY_DESCRIPTOR _securityDescriptor, PSID _principalSelfSid, ACCESS_MASK _desiredAccess, AUDIT_EVENT_TYPE _auditType, ULONG _flags, POBJECT_TYPE_LIST _objectTypeList, ULONG _objectTypeListLength, PGENERIC_MAPPING _genericMapping, BOOLEAN _objectCreation, PACCESS_MASK _grantedAccess, PNTSTATUS _accessStatus, PBOOLEAN _generateOnClose)
    {
        if (!ntAccessCheckByTypeResultListAndAuditAlarm) ntAccessCheckByTypeResultListAndAuditAlarm = win_::resolve_proc_address("NtAccessCheckByTypeResultListAndAuditAlarm", 42);
        return reinterpret_cast<NTSTATUS(*)(PCUNICODE_STRING, PVOID, PCUNICODE_STRING, PCUNICODE_STRING, PSECURITY_DESCRIPTOR, PSID, ACCESS_MASK, AUDIT_EVENT_TYPE, ULONG, POBJECT_TYPE_LIST, ULONG, PGENERIC_MAPPING, BOOLEAN, PACCESS_MASK, PNTSTATUS, PBOOLEAN)>(ntAccessCheckByTypeResultListAndAuditAlarm)(_subsystemName, _handleId, _objectTypeName, _objectName, _securityDescriptor, _principalSelfSid, _desiredAccess, _auditType, _flags, _objectTypeList, _objectTypeListLength, _genericMapping, _objectCreation, _grantedAccess, _accessStatus, _generateOnClose);
    }
    NTSTATUS NtaccessCheckByTypeResultListAndAuditAlarmByHandle(PCUNICODE_STRING _subsystemName, PVOID _handleId, HANDLE _clientToken, PCUNICODE_STRING _objectTypeName, PCUNICODE_STRING _objectName, PSECURITY_DESCRIPTOR _securityDescriptor, PSID _principalSelfSid, ACCESS_MASK _desiredAccess, AUDIT_EVENT_TYPE _auditType, ULONG _flags, POBJECT_TYPE_LIST _objectTypeList, ULONG _objectTypeListLength, PGENERIC_MAPPING _genericMapping, BOOLEAN _objectCreation, PACCESS_MASK _grantedAccess, PNTSTATUS _accessStatus, PBOOLEAN _generateOnClose)
    {
        if (!ntAccessCheckByTypeResultListAndAuditAlarmByHandle) ntAccessCheckByTypeResultListAndAuditAlarmByHandle = win_::resolve_proc_address("NtAccessCheckByTypeResultListAndAuditAlarmByHandle", 50);
        return reinterpret_cast<NTSTATUS(*)(PCUNICODE_STRING, PVOID, HANDLE, PCUNICODE_STRING, PCUNICODE_STRING, PSECURITY_DESCRIPTOR, PSID, ACCESS_MASK, AUDIT_EVENT_TYPE, ULONG, POBJECT_TYPE_LIST, ULONG, PGENERIC_MAPPING, BOOLEAN, PACCESS_MASK, PNTSTATUS, PBOOLEAN)>(ntAccessCheckByTypeResultListAndAuditAlarmByHandle)(_subsystemName, _handleId, _clientToken, _objectTypeName, _objectName, _securityDescriptor, _principalSelfSid, _desiredAccess, _auditType, _flags, _objectTypeList, _objectTypeListLength, _genericMapping, _objectCreation, _grantedAccess, _accessStatus, _generateOnClose);
    }
    NTSTATUS NtacquireCrossVmMutant(HANDLE _crossVmMutant, PLARGE_INTEGER _timeout)
    {
        if (!ntAcquireCrossVmMutant) ntAcquireCrossVmMutant = win_::resolve_proc_address("NtAcquireCrossVmMutant", 22);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PLARGE_INTEGER)>(ntAcquireCrossVmMutant)(_crossVmMutant, _timeout);
    }
    NTSTATUS NtacquireProcessActivityReference(PHANDLE _activityReferenceHandle, HANDLE _parentProcessHandle, ULONG _processActivityType)
    {
        if (!ntAcquireProcessActivityReference) ntAcquireProcessActivityReference = win_::resolve_proc_address("NtAcquireProcessActivityReference", 33);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, HANDLE, ULONG)>(ntAcquireProcessActivityReference)(_activityReferenceHandle, _parentProcessHandle, _processActivityType);
    }
    NTSTATUS NtaddAtom(PCWSTR _atomName, ULONG _length, PRTL_ATOM _atom)
    {
        if (!ntAddAtom) ntAddAtom = win_::resolve_proc_address("NtAddAtom", 9);
        return reinterpret_cast<NTSTATUS(*)(PCWSTR, ULONG, PRTL_ATOM)>(ntAddAtom)(_atomName, _length, _atom);
    }
    NTSTATUS NtaddAtomEx(PCWSTR _atomName, ULONG _length, PRTL_ATOM _atom, ULONG _flags)
    {
        if (!ntAddAtomEx) ntAddAtomEx = win_::resolve_proc_address("NtAddAtomEx", 11);
        return reinterpret_cast<NTSTATUS(*)(PCWSTR, ULONG, PRTL_ATOM, ULONG)>(ntAddAtomEx)(_atomName, _length, _atom, _flags);
    }
    NTSTATUS NtaddBootEntry(PBOOT_ENTRY _bootEntry, PULONG _id)
    {
        if (!ntAddBootEntry) ntAddBootEntry = win_::resolve_proc_address("NtAddBootEntry", 14);
        return reinterpret_cast<NTSTATUS(*)(PBOOT_ENTRY, PULONG)>(ntAddBootEntry)(_bootEntry, _id);
    }
    NTSTATUS NtaddDriverEntry(PEFI_DRIVER_ENTRY _driverEntry, PULONG _id)
    {
        if (!ntAddDriverEntry) ntAddDriverEntry = win_::resolve_proc_address("NtAddDriverEntry", 16);
        return reinterpret_cast<NTSTATUS(*)(PEFI_DRIVER_ENTRY, PULONG)>(ntAddDriverEntry)(_driverEntry, _id);
    }
    NTSTATUS NtadjustGroupsToken(HANDLE _tokenHandle, BOOLEAN _resetToDefault, PTOKEN_GROUPS _newState, ULONG _bufferLength, PTOKEN_GROUPS _previousState, PULONG _returnLength)
    {
        if (!ntAdjustGroupsToken) ntAdjustGroupsToken = win_::resolve_proc_address("NtAdjustGroupsToken", 19);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, BOOLEAN, PTOKEN_GROUPS, ULONG, PTOKEN_GROUPS, PULONG)>(ntAdjustGroupsToken)(_tokenHandle, _resetToDefault, _newState, _bufferLength, _previousState, _returnLength);
    }
    NTSTATUS NtadjustPrivilegesToken(HANDLE _tokenHandle, BOOLEAN _disableAllPrivileges, PTOKEN_PRIVILEGES _newState, ULONG _bufferLength, PTOKEN_PRIVILEGES _previousState, PULONG _returnLength)
    {
        if (!ntAdjustPrivilegesToken) ntAdjustPrivilegesToken = win_::resolve_proc_address("NtAdjustPrivilegesToken", 23);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, BOOLEAN, PTOKEN_PRIVILEGES, ULONG, PTOKEN_PRIVILEGES, PULONG)>(ntAdjustPrivilegesToken)(_tokenHandle, _disableAllPrivileges, _newState, _bufferLength, _previousState, _returnLength);
    }
    NTSTATUS NtadjustTokenClaimsAndDeviceGroups(HANDLE _tokenHandle, BOOLEAN _userResetToDefault, BOOLEAN _deviceResetToDefault, BOOLEAN _deviceGroupsResetToDefault, PTOKEN_SECURITY_ATTRIBUTES_INFORMATION _newUserState, PTOKEN_SECURITY_ATTRIBUTES_INFORMATION _newDeviceState, PTOKEN_GROUPS _newDeviceGroupsState, ULONG _userBufferLength, PTOKEN_SECURITY_ATTRIBUTES_INFORMATION _previousUserState, ULONG _deviceBufferLength, PTOKEN_SECURITY_ATTRIBUTES_INFORMATION _previousDeviceState, ULONG _deviceGroupsBufferLength, PTOKEN_GROUPS _previousDeviceGroups, PULONG _userReturnLength, PULONG _deviceReturnLength, PULONG _deviceGroupsReturnBufferLength)
    {
        if (!ntAdjustTokenClaimsAndDeviceGroups) ntAdjustTokenClaimsAndDeviceGroups = win_::resolve_proc_address("NtAdjustTokenClaimsAndDeviceGroups", 34);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, BOOLEAN, BOOLEAN, BOOLEAN, PTOKEN_SECURITY_ATTRIBUTES_INFORMATION, PTOKEN_SECURITY_ATTRIBUTES_INFORMATION, PTOKEN_GROUPS, ULONG, PTOKEN_SECURITY_ATTRIBUTES_INFORMATION, ULONG, PTOKEN_SECURITY_ATTRIBUTES_INFORMATION, ULONG, PTOKEN_GROUPS, PULONG, PULONG, PULONG)>(ntAdjustTokenClaimsAndDeviceGroups)(_tokenHandle, _userResetToDefault, _deviceResetToDefault, _deviceGroupsResetToDefault, _newUserState, _newDeviceState, _newDeviceGroupsState, _userBufferLength, _previousUserState, _deviceBufferLength, _previousDeviceState, _deviceGroupsBufferLength, _previousDeviceGroups, _userReturnLength, _deviceReturnLength, _deviceGroupsReturnBufferLength);
    }
    NTSTATUS NtalertMultipleThreadByThreadId(PHANDLE _multipleThreadId, ULONG _count, PPS_ALERT_THREAD_EXTENDED_PARAMETER _extendedParameters, ULONG _extendedParameterCount)
    {
        if (!ntAlertMultipleThreadByThreadId) ntAlertMultipleThreadByThreadId = win_::resolve_proc_address("NtAlertMultipleThreadByThreadId", 31);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ULONG, PPS_ALERT_THREAD_EXTENDED_PARAMETER, ULONG)>(ntAlertMultipleThreadByThreadId)(_multipleThreadId, _count, _extendedParameters, _extendedParameterCount);
    }
    NTSTATUS NtalertResumeThread(HANDLE _threadHandle, PULONG _previousSuspendCount)
    {
        if (!ntAlertResumeThread) ntAlertResumeThread = win_::resolve_proc_address("NtAlertResumeThread", 19);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PULONG)>(ntAlertResumeThread)(_threadHandle, _previousSuspendCount);
    }
    NTSTATUS NtalertThread(HANDLE _threadHandle)
    {
        if (!ntAlertThread) ntAlertThread = win_::resolve_proc_address("NtAlertThread", 13);
        return reinterpret_cast<NTSTATUS(*)(HANDLE)>(ntAlertThread)(_threadHandle);
    }
    NTSTATUS NtalertThreadByThreadId(HANDLE _threadId)
    {
        if (!ntAlertThreadByThreadId) ntAlertThreadByThreadId = win_::resolve_proc_address("NtAlertThreadByThreadId", 23);
        return reinterpret_cast<NTSTATUS(*)(HANDLE)>(ntAlertThreadByThreadId)(_threadId);
    }
    NTSTATUS NtalertThreadByThreadIdEx(HANDLE _threadId, PRTL_SRWLOCK _lock)
    {
        if (!ntAlertThreadByThreadIdEx) ntAlertThreadByThreadIdEx = win_::resolve_proc_address("NtAlertThreadByThreadIdEx", 25);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PRTL_SRWLOCK)>(ntAlertThreadByThreadIdEx)(_threadId, _lock);
    }
    NTSTATUS NtallocateLocallyUniqueId(PLUID _luid)
    {
        if (!ntAllocateLocallyUniqueId) ntAllocateLocallyUniqueId = win_::resolve_proc_address("NtAllocateLocallyUniqueId", 25);
        return reinterpret_cast<NTSTATUS(*)(PLUID)>(ntAllocateLocallyUniqueId)(_luid);
    }
    NTSTATUS NtallocateReserveObject(PHANDLE _memoryReserveHandle, PCOBJECT_ATTRIBUTES _objectAttributes, MEMORY_RESERVE_TYPE _type)
    {
        if (!ntAllocateReserveObject) ntAllocateReserveObject = win_::resolve_proc_address("NtAllocateReserveObject", 23);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, PCOBJECT_ATTRIBUTES, MEMORY_RESERVE_TYPE)>(ntAllocateReserveObject)(_memoryReserveHandle, _objectAttributes, _type);
    }
    NTSTATUS NtallocateUserPhysicalPages(HANDLE _processHandle, PSIZE_T _numberOfPages, PULONG_PTR _userPfnArray)
    {
        if (!ntAllocateUserPhysicalPages) ntAllocateUserPhysicalPages = win_::resolve_proc_address("NtAllocateUserPhysicalPages", 27);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PSIZE_T, PULONG_PTR)>(ntAllocateUserPhysicalPages)(_processHandle, _numberOfPages, _userPfnArray);
    }
    NTSTATUS NtallocateUserPhysicalPagesEx(HANDLE _processHandle, PULONG_PTR _numberOfPages, PULONG_PTR _userPfnArray, PMEM_EXTENDED_PARAMETER _extendedParameters, ULONG _extendedParameterCount)
    {
        if (!ntAllocateUserPhysicalPagesEx) ntAllocateUserPhysicalPagesEx = win_::resolve_proc_address("NtAllocateUserPhysicalPagesEx", 29);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PULONG_PTR, PULONG_PTR, PMEM_EXTENDED_PARAMETER, ULONG)>(ntAllocateUserPhysicalPagesEx)(_processHandle, _numberOfPages, _userPfnArray, _extendedParameters, _extendedParameterCount);
    }
    NTSTATUS NtallocateUuids(PULARGE_INTEGER _time, PULONG _range, PULONG _sequence, PCHAR _seed)
    {
        if (!ntAllocateUuids) ntAllocateUuids = win_::resolve_proc_address("NtAllocateUuids", 15);
        return reinterpret_cast<NTSTATUS(*)(PULARGE_INTEGER, PULONG, PULONG, PCHAR)>(ntAllocateUuids)(_time, _range, _sequence, _seed);
    }
    NTSTATUS NtallocateVirtualMemory(HANDLE _processHandle, PVOID* _baseAddress, ULONG_PTR _zeroBits, PSIZE_T _regionSize, ULONG _allocationType, ULONG _pageProtection)
    {
        if (!ntAllocateVirtualMemory) ntAllocateVirtualMemory = win_::resolve_proc_address("NtAllocateVirtualMemory", 23);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PVOID*, ULONG_PTR, PSIZE_T, ULONG, ULONG)>(ntAllocateVirtualMemory)(_processHandle, _baseAddress, _zeroBits, _regionSize, _allocationType, _pageProtection);
    }
    NTSTATUS NtallocateVirtualMemoryEx(HANDLE _processHandle, PVOID* _baseAddress, PSIZE_T _regionSize, ULONG _allocationType, ULONG _pageProtection, PMEM_EXTENDED_PARAMETER _extendedParameters, ULONG _extendedParameterCount)
    {
        if (!ntAllocateVirtualMemoryEx) ntAllocateVirtualMemoryEx = win_::resolve_proc_address("NtAllocateVirtualMemoryEx", 25);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PVOID*, PSIZE_T, ULONG, ULONG, PMEM_EXTENDED_PARAMETER, ULONG)>(ntAllocateVirtualMemoryEx)(_processHandle, _baseAddress, _regionSize, _allocationType, _pageProtection, _extendedParameters, _extendedParameterCount);
    }
    NTSTATUS NtalpcAcceptConnectPort(PHANDLE _portHandle, HANDLE _connectionPortHandle, ULONG _flags, POBJECT_ATTRIBUTES _objectAttributes, PALPC_PORT_ATTRIBUTES _portAttributes, PVOID _portContext, PPORT_MESSAGE _connectionRequest, PALPC_MESSAGE_ATTRIBUTES _connectionMessageAttributes, BOOLEAN _acceptConnection)
    {
        if (!ntAlpcAcceptConnectPort) ntAlpcAcceptConnectPort = win_::resolve_proc_address("NtAlpcAcceptConnectPort", 23);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, HANDLE, ULONG, POBJECT_ATTRIBUTES, PALPC_PORT_ATTRIBUTES, PVOID, PPORT_MESSAGE, PALPC_MESSAGE_ATTRIBUTES, BOOLEAN)>(ntAlpcAcceptConnectPort)(_portHandle, _connectionPortHandle, _flags, _objectAttributes, _portAttributes, _portContext, _connectionRequest, _connectionMessageAttributes, _acceptConnection);
    }
    NTSTATUS NtalpcCancelMessage(HANDLE _portHandle, ULONG _flags, PALPC_CONTEXT_ATTR _messageContext)
    {
        if (!ntAlpcCancelMessage) ntAlpcCancelMessage = win_::resolve_proc_address("NtAlpcCancelMessage", 19);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONG, PALPC_CONTEXT_ATTR)>(ntAlpcCancelMessage)(_portHandle, _flags, _messageContext);
    }
    NTSTATUS NtalpcConnectPort(PHANDLE _portHandle, PCUNICODE_STRING _portName, POBJECT_ATTRIBUTES _objectAttributes, PALPC_PORT_ATTRIBUTES _portAttributes, ULONG _flags, PSID _requiredServerSid, PPORT_MESSAGE _connectionMessage, PSIZE_T _bufferLength, PALPC_MESSAGE_ATTRIBUTES _outMessageAttributes, PALPC_MESSAGE_ATTRIBUTES _inMessageAttributes, PLARGE_INTEGER _timeout)
    {
        if (!ntAlpcConnectPort) ntAlpcConnectPort = win_::resolve_proc_address("NtAlpcConnectPort", 17);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, PCUNICODE_STRING, POBJECT_ATTRIBUTES, PALPC_PORT_ATTRIBUTES, ULONG, PSID, PPORT_MESSAGE, PSIZE_T, PALPC_MESSAGE_ATTRIBUTES, PALPC_MESSAGE_ATTRIBUTES, PLARGE_INTEGER)>(ntAlpcConnectPort)(_portHandle, _portName, _objectAttributes, _portAttributes, _flags, _requiredServerSid, _connectionMessage, _bufferLength, _outMessageAttributes, _inMessageAttributes, _timeout);
    }
    NTSTATUS NtalpcConnectPortEx(PHANDLE _portHandle, POBJECT_ATTRIBUTES _connectionPortObjectAttributes, POBJECT_ATTRIBUTES _clientPortObjectAttributes, PALPC_PORT_ATTRIBUTES _portAttributes, ULONG _flags, PSECURITY_DESCRIPTOR _serverSecurityRequirements, PPORT_MESSAGE _connectionMessage, PSIZE_T _bufferLength, PALPC_MESSAGE_ATTRIBUTES _outMessageAttributes, PALPC_MESSAGE_ATTRIBUTES _inMessageAttributes, PLARGE_INTEGER _timeout)
    {
        if (!ntAlpcConnectPortEx) ntAlpcConnectPortEx = win_::resolve_proc_address("NtAlpcConnectPortEx", 19);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, POBJECT_ATTRIBUTES, POBJECT_ATTRIBUTES, PALPC_PORT_ATTRIBUTES, ULONG, PSECURITY_DESCRIPTOR, PPORT_MESSAGE, PSIZE_T, PALPC_MESSAGE_ATTRIBUTES, PALPC_MESSAGE_ATTRIBUTES, PLARGE_INTEGER)>(ntAlpcConnectPortEx)(_portHandle, _connectionPortObjectAttributes, _clientPortObjectAttributes, _portAttributes, _flags, _serverSecurityRequirements, _connectionMessage, _bufferLength, _outMessageAttributes, _inMessageAttributes, _timeout);
    }
    NTSTATUS NtalpcCreatePort(PHANDLE _portHandle, POBJECT_ATTRIBUTES _objectAttributes, PALPC_PORT_ATTRIBUTES _portAttributes)
    {
        if (!ntAlpcCreatePort) ntAlpcCreatePort = win_::resolve_proc_address("NtAlpcCreatePort", 16);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, POBJECT_ATTRIBUTES, PALPC_PORT_ATTRIBUTES)>(ntAlpcCreatePort)(_portHandle, _objectAttributes, _portAttributes);
    }
    NTSTATUS NtalpcCreatePortSection(HANDLE _portHandle, ULONG _flags, HANDLE _sectionHandle, SIZE_T _sectionSize, PALPC_HANDLE _alpcSectionHandle, PSIZE_T _actualSectionSize)
    {
        if (!ntAlpcCreatePortSection) ntAlpcCreatePortSection = win_::resolve_proc_address("NtAlpcCreatePortSection", 23);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONG, HANDLE, SIZE_T, PALPC_HANDLE, PSIZE_T)>(ntAlpcCreatePortSection)(_portHandle, _flags, _sectionHandle, _sectionSize, _alpcSectionHandle, _actualSectionSize);
    }
    NTSTATUS NtalpcCreateResourceReserve(HANDLE _portHandle, ULONG _flags, SIZE_T _messageSize, PULONG _resourceId)
    {
        if (!ntAlpcCreateResourceReserve) ntAlpcCreateResourceReserve = win_::resolve_proc_address("NtAlpcCreateResourceReserve", 27);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONG, SIZE_T, PULONG)>(ntAlpcCreateResourceReserve)(_portHandle, _flags, _messageSize, _resourceId);
    }
    NTSTATUS NtalpcCreateSectionView(HANDLE _portHandle, ULONG _flags, PALPC_DATA_VIEW_ATTR _viewAttributes)
    {
        if (!ntAlpcCreateSectionView) ntAlpcCreateSectionView = win_::resolve_proc_address("NtAlpcCreateSectionView", 23);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONG, PALPC_DATA_VIEW_ATTR)>(ntAlpcCreateSectionView)(_portHandle, _flags, _viewAttributes);
    }
    NTSTATUS NtalpcCreateSecurityContext(HANDLE _portHandle, ULONG _flags, PALPC_SECURITY_ATTR _securityAttribute)
    {
        if (!ntAlpcCreateSecurityContext) ntAlpcCreateSecurityContext = win_::resolve_proc_address("NtAlpcCreateSecurityContext", 27);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONG, PALPC_SECURITY_ATTR)>(ntAlpcCreateSecurityContext)(_portHandle, _flags, _securityAttribute);
    }
    NTSTATUS NtalpcDeletePortSection(HANDLE _portHandle, ULONG _flags, ALPC_HANDLE _sectionHandle)
    {
        if (!ntAlpcDeletePortSection) ntAlpcDeletePortSection = win_::resolve_proc_address("NtAlpcDeletePortSection", 23);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONG, ALPC_HANDLE)>(ntAlpcDeletePortSection)(_portHandle, _flags, _sectionHandle);
    }
    NTSTATUS NtalpcDeleteResourceReserve(HANDLE _portHandle, ULONG _flags, ULONG _resourceId)
    {
        if (!ntAlpcDeleteResourceReserve) ntAlpcDeleteResourceReserve = win_::resolve_proc_address("NtAlpcDeleteResourceReserve", 27);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONG, ULONG)>(ntAlpcDeleteResourceReserve)(_portHandle, _flags, _resourceId);
    }
    NTSTATUS NtalpcDeleteSectionView(HANDLE _portHandle, ULONG _flags, PVOID _viewBase)
    {
        if (!ntAlpcDeleteSectionView) ntAlpcDeleteSectionView = win_::resolve_proc_address("NtAlpcDeleteSectionView", 23);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONG, PVOID)>(ntAlpcDeleteSectionView)(_portHandle, _flags, _viewBase);
    }
    NTSTATUS NtalpcDeleteSecurityContext(HANDLE _portHandle, ULONG _flags, ALPC_HANDLE _contextHandle)
    {
        if (!ntAlpcDeleteSecurityContext) ntAlpcDeleteSecurityContext = win_::resolve_proc_address("NtAlpcDeleteSecurityContext", 27);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONG, ALPC_HANDLE)>(ntAlpcDeleteSecurityContext)(_portHandle, _flags, _contextHandle);
    }
    NTSTATUS NtalpcDisconnectPort(HANDLE _portHandle, ULONG _flags)
    {
        if (!ntAlpcDisconnectPort) ntAlpcDisconnectPort = win_::resolve_proc_address("NtAlpcDisconnectPort", 20);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONG)>(ntAlpcDisconnectPort)(_portHandle, _flags);
    }
    NTSTATUS NtalpcImpersonateClientContainerOfPort(HANDLE _portHandle, PPORT_MESSAGE _message, ULONG _flags)
    {
        if (!ntAlpcImpersonateClientContainerOfPort) ntAlpcImpersonateClientContainerOfPort = win_::resolve_proc_address("NtAlpcImpersonateClientContainerOfPort", 38);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PPORT_MESSAGE, ULONG)>(ntAlpcImpersonateClientContainerOfPort)(_portHandle, _message, _flags);
    }
    NTSTATUS NtalpcImpersonateClientOfPort(HANDLE _portHandle, PPORT_MESSAGE _message, PVOID _flags)
    {
        if (!ntAlpcImpersonateClientOfPort) ntAlpcImpersonateClientOfPort = win_::resolve_proc_address("NtAlpcImpersonateClientOfPort", 29);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PPORT_MESSAGE, PVOID)>(ntAlpcImpersonateClientOfPort)(_portHandle, _message, _flags);
    }
    NTSTATUS NtalpcOpenSenderProcess(PHANDLE _processHandle, HANDLE _portHandle, PPORT_MESSAGE _portMessage, ULONG _flags, ACCESS_MASK _desiredAccess, POBJECT_ATTRIBUTES _objectAttributes)
    {
        if (!ntAlpcOpenSenderProcess) ntAlpcOpenSenderProcess = win_::resolve_proc_address("NtAlpcOpenSenderProcess", 23);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, HANDLE, PPORT_MESSAGE, ULONG, ACCESS_MASK, POBJECT_ATTRIBUTES)>(ntAlpcOpenSenderProcess)(_processHandle, _portHandle, _portMessage, _flags, _desiredAccess, _objectAttributes);
    }
    NTSTATUS NtalpcOpenSenderThread(PHANDLE _threadHandle, HANDLE _portHandle, PPORT_MESSAGE _portMessage, ULONG _flags, ACCESS_MASK _desiredAccess, POBJECT_ATTRIBUTES _objectAttributes)
    {
        if (!ntAlpcOpenSenderThread) ntAlpcOpenSenderThread = win_::resolve_proc_address("NtAlpcOpenSenderThread", 22);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, HANDLE, PPORT_MESSAGE, ULONG, ACCESS_MASK, POBJECT_ATTRIBUTES)>(ntAlpcOpenSenderThread)(_threadHandle, _portHandle, _portMessage, _flags, _desiredAccess, _objectAttributes);
    }
    NTSTATUS NtalpcQueryInformation(HANDLE _portHandle, ALPC_PORT_INFORMATION_CLASS _portInformationClass, PVOID _portInformation, ULONG _length, PULONG _returnLength)
    {
        if (!ntAlpcQueryInformation) ntAlpcQueryInformation = win_::resolve_proc_address("NtAlpcQueryInformation", 22);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ALPC_PORT_INFORMATION_CLASS, PVOID, ULONG, PULONG)>(ntAlpcQueryInformation)(_portHandle, _portInformationClass, _portInformation, _length, _returnLength);
    }
    NTSTATUS NtalpcQueryInformationMessage(HANDLE _portHandle, PPORT_MESSAGE _portMessage, ALPC_MESSAGE_INFORMATION_CLASS _messageInformationClass, PVOID _messageInformation, ULONG _length, PULONG _returnLength)
    {
        if (!ntAlpcQueryInformationMessage) ntAlpcQueryInformationMessage = win_::resolve_proc_address("NtAlpcQueryInformationMessage", 29);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PPORT_MESSAGE, ALPC_MESSAGE_INFORMATION_CLASS, PVOID, ULONG, PULONG)>(ntAlpcQueryInformationMessage)(_portHandle, _portMessage, _messageInformationClass, _messageInformation, _length, _returnLength);
    }
    NTSTATUS NtalpcRevokeSecurityContext(HANDLE _portHandle, ULONG _flags, ALPC_HANDLE _contextHandle)
    {
        if (!ntAlpcRevokeSecurityContext) ntAlpcRevokeSecurityContext = win_::resolve_proc_address("NtAlpcRevokeSecurityContext", 27);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONG, ALPC_HANDLE)>(ntAlpcRevokeSecurityContext)(_portHandle, _flags, _contextHandle);
    }
    NTSTATUS NtalpcSendWaitReceivePort(HANDLE _portHandle, ULONG _flags, PPORT_MESSAGE _sendMessageW, PALPC_MESSAGE_ATTRIBUTES _sendMessageAttributes, PPORT_MESSAGE _receiveMessage, PSIZE_T _bufferLength, PALPC_MESSAGE_ATTRIBUTES _receiveMessageAttributes, PLARGE_INTEGER _timeout)
    {
        if (!ntAlpcSendWaitReceivePort) ntAlpcSendWaitReceivePort = win_::resolve_proc_address("NtAlpcSendWaitReceivePort", 25);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONG, PPORT_MESSAGE, PALPC_MESSAGE_ATTRIBUTES, PPORT_MESSAGE, PSIZE_T, PALPC_MESSAGE_ATTRIBUTES, PLARGE_INTEGER)>(ntAlpcSendWaitReceivePort)(_portHandle, _flags, _sendMessageW, _sendMessageAttributes, _receiveMessage, _bufferLength, _receiveMessageAttributes, _timeout);
    }
    NTSTATUS NtalpcSetInformation(HANDLE _portHandle, ALPC_PORT_INFORMATION_CLASS _portInformationClass, PVOID _portInformation, ULONG _length)
    {
        if (!ntAlpcSetInformation) ntAlpcSetInformation = win_::resolve_proc_address("NtAlpcSetInformation", 20);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ALPC_PORT_INFORMATION_CLASS, PVOID, ULONG)>(ntAlpcSetInformation)(_portHandle, _portInformationClass, _portInformation, _length);
    }
    NTSTATUS NtapphelpCacheControl(AHC_SERVICE_CLASS _serviceClass, PVOID _serviceContext)
    {
        if (!ntApphelpCacheControl) ntApphelpCacheControl = win_::resolve_proc_address("NtApphelpCacheControl", 21);
        return reinterpret_cast<NTSTATUS(*)(AHC_SERVICE_CLASS, PVOID)>(ntApphelpCacheControl)(_serviceClass, _serviceContext);
    }
    NTSTATUS NtareMappedFilesTheSame(PVOID _file1MappedAsAnImage, PVOID _file2MappedAsFile)
    {
        if (!ntAreMappedFilesTheSame) ntAreMappedFilesTheSame = win_::resolve_proc_address("NtAreMappedFilesTheSame", 23);
        return reinterpret_cast<NTSTATUS(*)(PVOID, PVOID)>(ntAreMappedFilesTheSame)(_file1MappedAsAnImage, _file2MappedAsFile);
    }
    NTSTATUS NtassignProcessToJobObject(HANDLE _jobHandle, HANDLE _processHandle)
    {
        if (!ntAssignProcessToJobObject) ntAssignProcessToJobObject = win_::resolve_proc_address("NtAssignProcessToJobObject", 26);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE)>(ntAssignProcessToJobObject)(_jobHandle, _processHandle);
    }
    NTSTATUS NtassociateWaitCompletionPacket(HANDLE _waitCompletionPacketHandle, HANDLE _ioCompletionHandle, HANDLE _targetObjectHandle, PVOID _keyContext, PVOID _apcContext, NTSTATUS _ioStatus, ULONG_PTR _ioStatusInformation, PBOOLEAN _alreadySignaled)
    {
        if (!ntAssociateWaitCompletionPacket) ntAssociateWaitCompletionPacket = win_::resolve_proc_address("NtAssociateWaitCompletionPacket", 31);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE, HANDLE, PVOID, PVOID, NTSTATUS, ULONG_PTR, PBOOLEAN)>(ntAssociateWaitCompletionPacket)(_waitCompletionPacketHandle, _ioCompletionHandle, _targetObjectHandle, _keyContext, _apcContext, _ioStatus, _ioStatusInformation, _alreadySignaled);
    }
    NTSTATUS NtcallEnclave(PENCLAVE_ROUTINE _routine, PVOID _reserved, ULONG _flags, PVOID* _routineParamReturn)
    {
        if (!ntCallEnclave) ntCallEnclave = win_::resolve_proc_address("NtCallEnclave", 13);
        return reinterpret_cast<NTSTATUS(*)(PENCLAVE_ROUTINE, PVOID, ULONG, PVOID*)>(ntCallEnclave)(_routine, _reserved, _flags, _routineParamReturn);
    }
    NTSTATUS NtcallbackReturn(PVOID _outputBuffer, ULONG _outputLength, NTSTATUS _status)
    {
        if (!ntCallbackReturn) ntCallbackReturn = win_::resolve_proc_address("NtCallbackReturn", 16);
        return reinterpret_cast<NTSTATUS(*)(PVOID, ULONG, NTSTATUS)>(ntCallbackReturn)(_outputBuffer, _outputLength, _status);
    }
    NTSTATUS NtcancelIoFile(HANDLE _fileHandle, PIO_STATUS_BLOCK _ioStatusBlock)
    {
        if (!ntCancelIoFile) ntCancelIoFile = win_::resolve_proc_address("NtCancelIoFile", 14);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PIO_STATUS_BLOCK)>(ntCancelIoFile)(_fileHandle, _ioStatusBlock);
    }
    NTSTATUS NtcancelIoFileEx(HANDLE _fileHandle, PIO_STATUS_BLOCK _ioRequestToCancel, PIO_STATUS_BLOCK _ioStatusBlock)
    {
        if (!ntCancelIoFileEx) ntCancelIoFileEx = win_::resolve_proc_address("NtCancelIoFileEx", 16);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PIO_STATUS_BLOCK, PIO_STATUS_BLOCK)>(ntCancelIoFileEx)(_fileHandle, _ioRequestToCancel, _ioStatusBlock);
    }
    NTSTATUS NtcancelSynchronousIoFile(HANDLE _threadHandle, PIO_STATUS_BLOCK _ioRequestToCancel, PIO_STATUS_BLOCK _ioStatusBlock)
    {
        if (!ntCancelSynchronousIoFile) ntCancelSynchronousIoFile = win_::resolve_proc_address("NtCancelSynchronousIoFile", 25);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PIO_STATUS_BLOCK, PIO_STATUS_BLOCK)>(ntCancelSynchronousIoFile)(_threadHandle, _ioRequestToCancel, _ioStatusBlock);
    }
    NTSTATUS NtcancelTimer(HANDLE _timerHandle, PBOOLEAN _currentState)
    {
        if (!ntCancelTimer) ntCancelTimer = win_::resolve_proc_address("NtCancelTimer", 13);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PBOOLEAN)>(ntCancelTimer)(_timerHandle, _currentState);
    }
    NTSTATUS NtcancelTimer2(HANDLE _timerHandle, PT2_CANCEL_PARAMETERS _parameters)
    {
        if (!ntCancelTimer2) ntCancelTimer2 = win_::resolve_proc_address("NtCancelTimer2", 14);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PT2_CANCEL_PARAMETERS)>(ntCancelTimer2)(_timerHandle, _parameters);
    }
    NTSTATUS NtcancelWaitCompletionPacket(HANDLE _waitCompletionPacketHandle, BOOLEAN _removeSignaledPacket)
    {
        if (!ntCancelWaitCompletionPacket) ntCancelWaitCompletionPacket = win_::resolve_proc_address("NtCancelWaitCompletionPacket", 28);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, BOOLEAN)>(ntCancelWaitCompletionPacket)(_waitCompletionPacketHandle, _removeSignaledPacket);
    }
    NTSTATUS NtchangeProcessState(HANDLE _processStateChangeHandle, HANDLE _processHandle, PROCESS_STATE_CHANGE_TYPE _stateChangeType, PVOID _extendedInformation, SIZE_T _extendedInformationLength, ULONG _reserved)
    {
        if (!ntChangeProcessState) ntChangeProcessState = win_::resolve_proc_address("NtChangeProcessState", 20);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE, PROCESS_STATE_CHANGE_TYPE, PVOID, SIZE_T, ULONG)>(ntChangeProcessState)(_processStateChangeHandle, _processHandle, _stateChangeType, _extendedInformation, _extendedInformationLength, _reserved);
    }
    NTSTATUS NtchangeThreadState(HANDLE _threadStateChangeHandle, HANDLE _threadHandle, THREAD_STATE_CHANGE_TYPE _stateChangeType, PVOID _extendedInformation, SIZE_T _extendedInformationLength, ULONG _reserved)
    {
        if (!ntChangeThreadState) ntChangeThreadState = win_::resolve_proc_address("NtChangeThreadState", 19);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE, THREAD_STATE_CHANGE_TYPE, PVOID, SIZE_T, ULONG)>(ntChangeThreadState)(_threadStateChangeHandle, _threadHandle, _stateChangeType, _extendedInformation, _extendedInformationLength, _reserved);
    }
    NTSTATUS NtclearEvent(HANDLE _eventHandle)
    {
        if (!ntClearEvent) ntClearEvent = win_::resolve_proc_address("NtClearEvent", 12);
        return reinterpret_cast<NTSTATUS(*)(HANDLE)>(ntClearEvent)(_eventHandle);
    }
    NTSTATUS Ntclose(HANDLE _handle)
    {
        if (!ntClose) ntClose = win_::resolve_proc_address("NtClose", 7);
        return reinterpret_cast<NTSTATUS(*)(HANDLE)>(ntClose)(_handle);
    }
    NTSTATUS NtcloseObjectAuditAlarm(PCUNICODE_STRING _subsystemName, PVOID _handleId, BOOLEAN _generateOnClose)
    {
        if (!ntCloseObjectAuditAlarm) ntCloseObjectAuditAlarm = win_::resolve_proc_address("NtCloseObjectAuditAlarm", 23);
        return reinterpret_cast<NTSTATUS(*)(PCUNICODE_STRING, PVOID, BOOLEAN)>(ntCloseObjectAuditAlarm)(_subsystemName, _handleId, _generateOnClose);
    }
    NTSTATUS NtcommitComplete(HANDLE _enlistmentHandle, PLARGE_INTEGER _tmVirtualClock)
    {
        if (!ntCommitComplete) ntCommitComplete = win_::resolve_proc_address("NtCommitComplete", 16);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PLARGE_INTEGER)>(ntCommitComplete)(_enlistmentHandle, _tmVirtualClock);
    }
    NTSTATUS NtcommitEnlistment(HANDLE _enlistmentHandle, PLARGE_INTEGER _tmVirtualClock)
    {
        if (!ntCommitEnlistment) ntCommitEnlistment = win_::resolve_proc_address("NtCommitEnlistment", 18);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PLARGE_INTEGER)>(ntCommitEnlistment)(_enlistmentHandle, _tmVirtualClock);
    }
    NTSTATUS NtcommitRegistryTransaction(HANDLE _registryTransactionHandle, ULONG _flags)
    {
        if (!ntCommitRegistryTransaction) ntCommitRegistryTransaction = win_::resolve_proc_address("NtCommitRegistryTransaction", 27);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONG)>(ntCommitRegistryTransaction)(_registryTransactionHandle, _flags);
    }
    NTSTATUS NtcommitTransaction(HANDLE _transactionHandle, BOOLEAN _wait)
    {
        if (!ntCommitTransaction) ntCommitTransaction = win_::resolve_proc_address("NtCommitTransaction", 19);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, BOOLEAN)>(ntCommitTransaction)(_transactionHandle, _wait);
    }
    NTSTATUS NtcompactKeys(ULONG _count, HANDLE _keyArray[])
    {
        if (!ntCompactKeys) ntCompactKeys = win_::resolve_proc_address("NtCompactKeys", 13);
        return reinterpret_cast<NTSTATUS(*)(ULONG, HANDLE[])>(ntCompactKeys)(_count, _keyArray);
    }
    NTSTATUS NtcompareObjects(HANDLE _firstObjectHandle, HANDLE _secondObjectHandle)
    {
        if (!ntCompareObjects) ntCompareObjects = win_::resolve_proc_address("NtCompareObjects", 16);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE)>(ntCompareObjects)(_firstObjectHandle, _secondObjectHandle);
    }
    NTSTATUS NtcompareSigningLevels(SE_SIGNING_LEVEL _firstSigningLevel, SE_SIGNING_LEVEL _secondSigningLevel)
    {
        if (!ntCompareSigningLevels) ntCompareSigningLevels = win_::resolve_proc_address("NtCompareSigningLevels", 22);
        return reinterpret_cast<NTSTATUS(*)(SE_SIGNING_LEVEL, SE_SIGNING_LEVEL)>(ntCompareSigningLevels)(_firstSigningLevel, _secondSigningLevel);
    }
    NTSTATUS NtcompareTokens(HANDLE _firstTokenHandle, HANDLE _secondTokenHandle, PBOOLEAN _equal)
    {
        if (!ntCompareTokens) ntCompareTokens = win_::resolve_proc_address("NtCompareTokens", 15);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE, PBOOLEAN)>(ntCompareTokens)(_firstTokenHandle, _secondTokenHandle, _equal);
    }
    NTSTATUS NtcompleteConnectPort(HANDLE _portHandle)
    {
        if (!ntCompleteConnectPort) ntCompleteConnectPort = win_::resolve_proc_address("NtCompleteConnectPort", 21);
        return reinterpret_cast<NTSTATUS(*)(HANDLE)>(ntCompleteConnectPort)(_portHandle);
    }
    NTSTATUS NtcompressKey(HANDLE _keyHandle)
    {
        if (!ntCompressKey) ntCompressKey = win_::resolve_proc_address("NtCompressKey", 13);
        return reinterpret_cast<NTSTATUS(*)(HANDLE)>(ntCompressKey)(_keyHandle);
    }
    NTSTATUS NtconnectPort(PHANDLE _portHandle, PCUNICODE_STRING _portName, PSECURITY_QUALITY_OF_SERVICE _securityQos, PPORT_VIEW _clientView, PREMOTE_PORT_VIEW _serverView, PULONG _maxMessageLength, PVOID _connectionInformation, PULONG _connectionInformationLength)
    {
        if (!ntConnectPort) ntConnectPort = win_::resolve_proc_address("NtConnectPort", 13);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, PCUNICODE_STRING, PSECURITY_QUALITY_OF_SERVICE, PPORT_VIEW, PREMOTE_PORT_VIEW, PULONG, PVOID, PULONG)>(ntConnectPort)(_portHandle, _portName, _securityQos, _clientView, _serverView, _maxMessageLength, _connectionInformation, _connectionInformationLength);
    }
    NTSTATUS Ntcontinue(PCONTEXT _contextRecord, BOOLEAN _testAlert)
    {
        if (!ntContinue) ntContinue = win_::resolve_proc_address("NtContinue", 10);
        return reinterpret_cast<NTSTATUS(*)(PCONTEXT, BOOLEAN)>(ntContinue)(_contextRecord, _testAlert);
    }
    NTSTATUS NtcontinueEx(PCONTEXT _contextRecord, PVOID _continueArgument)
    {
        if (!ntContinueEx) ntContinueEx = win_::resolve_proc_address("NtContinueEx", 12);
        return reinterpret_cast<NTSTATUS(*)(PCONTEXT, PVOID)>(ntContinueEx)(_contextRecord, _continueArgument);
    }
    NTSTATUS NtconvertBetweenAuxiliaryCounterAndPerformanceCounter(BOOLEAN _convertAuxiliaryToPerformanceCounter, PULONG64 _performanceOrAuxiliaryCounterValue, PULONG64 _convertedValue, PULONG64 _conversionError)
    {
        if (!ntConvertBetweenAuxiliaryCounterAndPerformanceCounter) ntConvertBetweenAuxiliaryCounterAndPerformanceCounter = win_::resolve_proc_address("NtConvertBetweenAuxiliaryCounterAndPerformanceCounter", 53);
        return reinterpret_cast<NTSTATUS(*)(BOOLEAN, PULONG64, PULONG64, PULONG64)>(ntConvertBetweenAuxiliaryCounterAndPerformanceCounter)(_convertAuxiliaryToPerformanceCounter, _performanceOrAuxiliaryCounterValue, _convertedValue, _conversionError);
    }
    NTSTATUS NtcopyFileChunk(HANDLE _sourceHandle, HANDLE _destinationHandle, HANDLE _eventHandle, PIO_STATUS_BLOCK _ioStatusBlock, ULONG _length, PLARGE_INTEGER _sourceOffset, PLARGE_INTEGER _destOffset, PULONG _sourceKey, PULONG _destKey, ULONG _flags)
    {
        if (!ntCopyFileChunk) ntCopyFileChunk = win_::resolve_proc_address("NtCopyFileChunk", 15);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE, HANDLE, PIO_STATUS_BLOCK, ULONG, PLARGE_INTEGER, PLARGE_INTEGER, PULONG, PULONG, ULONG)>(ntCopyFileChunk)(_sourceHandle, _destinationHandle, _eventHandle, _ioStatusBlock, _length, _sourceOffset, _destOffset, _sourceKey, _destKey, _flags);
    }
    NTSTATUS NtcreateCpuPartition(PHANDLE _cpuPartitionHandle, ACCESS_MASK _desiredAccess, POBJECT_ATTRIBUTES _objectAttributes)
    {
        if (!ntCreateCpuPartition) ntCreateCpuPartition = win_::resolve_proc_address("NtCreateCpuPartition", 20);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES)>(ntCreateCpuPartition)(_cpuPartitionHandle, _desiredAccess, _objectAttributes);
    }
    NTSTATUS NtcreateCrossVmEvent(PHANDLE _crossVmEvent, ACCESS_MASK _desiredAccess, POBJECT_ATTRIBUTES _objectAttributes, ULONG _crossVmEventFlags, LPCGUID _vMID, LPCGUID _serviceID)
    {
        if (!ntCreateCrossVmEvent) ntCreateCrossVmEvent = win_::resolve_proc_address("NtCreateCrossVmEvent", 20);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES, ULONG, LPCGUID, LPCGUID)>(ntCreateCrossVmEvent)(_crossVmEvent, _desiredAccess, _objectAttributes, _crossVmEventFlags, _vMID, _serviceID);
    }
    NTSTATUS NtcreateCrossVmMutant(PHANDLE _eventHandle, ACCESS_MASK _desiredAccess, POBJECT_ATTRIBUTES _objectAttributes, ULONG _crossVmEventFlags, LPCGUID _vMID, LPCGUID _serviceID)
    {
        if (!ntCreateCrossVmMutant) ntCreateCrossVmMutant = win_::resolve_proc_address("NtCreateCrossVmMutant", 21);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES, ULONG, LPCGUID, LPCGUID)>(ntCreateCrossVmMutant)(_eventHandle, _desiredAccess, _objectAttributes, _crossVmEventFlags, _vMID, _serviceID);
    }
    NTSTATUS NtcreateDebugObject(PHANDLE _debugObjectHandle, ACCESS_MASK _desiredAccess, POBJECT_ATTRIBUTES _objectAttributes, ULONG _flags)
    {
        if (!ntCreateDebugObject) ntCreateDebugObject = win_::resolve_proc_address("NtCreateDebugObject", 19);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES, ULONG)>(ntCreateDebugObject)(_debugObjectHandle, _desiredAccess, _objectAttributes, _flags);
    }
    NTSTATUS NtcreateDirectoryObject(PHANDLE _directoryHandle, ACCESS_MASK _desiredAccess, POBJECT_ATTRIBUTES _objectAttributes)
    {
        if (!ntCreateDirectoryObject) ntCreateDirectoryObject = win_::resolve_proc_address("NtCreateDirectoryObject", 23);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES)>(ntCreateDirectoryObject)(_directoryHandle, _desiredAccess, _objectAttributes);
    }
    NTSTATUS NtcreateDirectoryObjectEx(PHANDLE _directoryHandle, ACCESS_MASK _desiredAccess, POBJECT_ATTRIBUTES _objectAttributes, HANDLE _shadowDirectoryHandle, ULONG _flags)
    {
        if (!ntCreateDirectoryObjectEx) ntCreateDirectoryObjectEx = win_::resolve_proc_address("NtCreateDirectoryObjectEx", 25);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES, HANDLE, ULONG)>(ntCreateDirectoryObjectEx)(_directoryHandle, _desiredAccess, _objectAttributes, _shadowDirectoryHandle, _flags);
    }
    NTSTATUS NtcreateEnclave(HANDLE _processHandle, PVOID* _baseAddress, ULONG_PTR _zeroBits, SIZE_T _size, SIZE_T _initialCommitment, ULONG _enclaveType, PVOID _enclaveInformation, ULONG _enclaveInformationLength, PULONG _enclaveError)
    {
        if (!ntCreateEnclave) ntCreateEnclave = win_::resolve_proc_address("NtCreateEnclave", 15);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PVOID*, ULONG_PTR, SIZE_T, SIZE_T, ULONG, PVOID, ULONG, PULONG)>(ntCreateEnclave)(_processHandle, _baseAddress, _zeroBits, _size, _initialCommitment, _enclaveType, _enclaveInformation, _enclaveInformationLength, _enclaveError);
    }
    NTSTATUS NtcreateEnlistment(PHANDLE _enlistmentHandle, ACCESS_MASK _desiredAccess, HANDLE _resourceManagerHandle, HANDLE _transactionHandle, POBJECT_ATTRIBUTES _objectAttributes, ULONG _createOptions, NOTIFICATION_MASK _notificationMask, PVOID _enlistmentKey)
    {
        if (!ntCreateEnlistment) ntCreateEnlistment = win_::resolve_proc_address("NtCreateEnlistment", 18);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, HANDLE, HANDLE, POBJECT_ATTRIBUTES, ULONG, NOTIFICATION_MASK, PVOID)>(ntCreateEnlistment)(_enlistmentHandle, _desiredAccess, _resourceManagerHandle, _transactionHandle, _objectAttributes, _createOptions, _notificationMask, _enlistmentKey);
    }
    NTSTATUS NtcreateEvent(PHANDLE _eventHandle, ACCESS_MASK _desiredAccess, POBJECT_ATTRIBUTES _objectAttributes, EVENT_TYPE _eventType, BOOLEAN _initialState)
    {
        if (!ntCreateEvent) ntCreateEvent = win_::resolve_proc_address("NtCreateEvent", 13);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES, EVENT_TYPE, BOOLEAN)>(ntCreateEvent)(_eventHandle, _desiredAccess, _objectAttributes, _eventType, _initialState);
    }
    NTSTATUS NtcreateEventPair(PHANDLE _eventPairHandle, ACCESS_MASK _desiredAccess, PCOBJECT_ATTRIBUTES _objectAttributes)
    {
        if (!ntCreateEventPair) ntCreateEventPair = win_::resolve_proc_address("NtCreateEventPair", 17);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, PCOBJECT_ATTRIBUTES)>(ntCreateEventPair)(_eventPairHandle, _desiredAccess, _objectAttributes);
    }
    NTSTATUS NtcreateFile(PHANDLE _fileHandle, ACCESS_MASK _desiredAccess, PCOBJECT_ATTRIBUTES _objectAttributes, PIO_STATUS_BLOCK _ioStatusBlock, PLARGE_INTEGER _allocationSize, ULONG _fileAttributes, ULONG _shareAccess, ULONG _createDisposition, ULONG _createOptions, PVOID _eaBuffer, ULONG _eaLength)
    {
        if (!ntCreateFile) ntCreateFile = win_::resolve_proc_address("NtCreateFile", 12);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, PCOBJECT_ATTRIBUTES, PIO_STATUS_BLOCK, PLARGE_INTEGER, ULONG, ULONG, ULONG, ULONG, PVOID, ULONG)>(ntCreateFile)(_fileHandle, _desiredAccess, _objectAttributes, _ioStatusBlock, _allocationSize, _fileAttributes, _shareAccess, _createDisposition, _createOptions, _eaBuffer, _eaLength);
    }
    NTSTATUS NtcreateIRTimer(PHANDLE _timerHandle, PULONG _timerId, ACCESS_MASK _desiredAccess)
    {
        if (!ntCreateIRTimer) ntCreateIRTimer = win_::resolve_proc_address("NtCreateIRTimer", 15);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, PULONG, ACCESS_MASK)>(ntCreateIRTimer)(_timerHandle, _timerId, _desiredAccess);
    }
    NTSTATUS NtcreateIoCompletion(PHANDLE _ioCompletionHandle, ACCESS_MASK _desiredAccess, PCOBJECT_ATTRIBUTES _objectAttributes, ULONG _numberOfConcurrentThreads)
    {
        if (!ntCreateIoCompletion) ntCreateIoCompletion = win_::resolve_proc_address("NtCreateIoCompletion", 20);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, PCOBJECT_ATTRIBUTES, ULONG)>(ntCreateIoCompletion)(_ioCompletionHandle, _desiredAccess, _objectAttributes, _numberOfConcurrentThreads);
    }
    NTSTATUS NtcreateIoRing(PHANDLE _ioRingHandle, ULONG _createParametersLength, PVOID _createParameters, ULONG _outputParametersLength, PVOID _outputParameters)
    {
        if (!ntCreateIoRing) ntCreateIoRing = win_::resolve_proc_address("NtCreateIoRing", 14);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ULONG, PVOID, ULONG, PVOID)>(ntCreateIoRing)(_ioRingHandle, _createParametersLength, _createParameters, _outputParametersLength, _outputParameters);
    }
    NTSTATUS NtcreateJobObject(PHANDLE _jobHandle, ACCESS_MASK _desiredAccess, PCOBJECT_ATTRIBUTES _objectAttributes)
    {
        if (!ntCreateJobObject) ntCreateJobObject = win_::resolve_proc_address("NtCreateJobObject", 17);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, PCOBJECT_ATTRIBUTES)>(ntCreateJobObject)(_jobHandle, _desiredAccess, _objectAttributes);
    }
    NTSTATUS NtcreateJobSet(ULONG _numJob, PJOB_SET_ARRAY _userJobSet, ULONG _flags)
    {
        if (!ntCreateJobSet) ntCreateJobSet = win_::resolve_proc_address("NtCreateJobSet", 14);
        return reinterpret_cast<NTSTATUS(*)(ULONG, PJOB_SET_ARRAY, ULONG)>(ntCreateJobSet)(_numJob, _userJobSet, _flags);
    }
    NTSTATUS NtcreateKey(PHANDLE _keyHandle, ACCESS_MASK _desiredAccess, POBJECT_ATTRIBUTES _objectAttributes, ULONG _titleIndex, PCUNICODE_STRING _class, ULONG _createOptions, PULONG _disposition)
    {
        if (!ntCreateKey) ntCreateKey = win_::resolve_proc_address("NtCreateKey", 11);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES, ULONG, PCUNICODE_STRING, ULONG, PULONG)>(ntCreateKey)(_keyHandle, _desiredAccess, _objectAttributes, _titleIndex, _class, _createOptions, _disposition);
    }
    NTSTATUS NtcreateKeyTransacted(PHANDLE _keyHandle, ACCESS_MASK _desiredAccess, POBJECT_ATTRIBUTES _objectAttributes, ULONG _titleIndex, PCUNICODE_STRING _class, ULONG _createOptions, HANDLE _transactionHandle, PULONG _disposition)
    {
        if (!ntCreateKeyTransacted) ntCreateKeyTransacted = win_::resolve_proc_address("NtCreateKeyTransacted", 21);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES, ULONG, PCUNICODE_STRING, ULONG, HANDLE, PULONG)>(ntCreateKeyTransacted)(_keyHandle, _desiredAccess, _objectAttributes, _titleIndex, _class, _createOptions, _transactionHandle, _disposition);
    }
    NTSTATUS NtcreateKeyedEvent(PHANDLE _keyedEventHandle, ACCESS_MASK _desiredAccess, PCOBJECT_ATTRIBUTES _objectAttributes, ULONG _flags)
    {
        if (!ntCreateKeyedEvent) ntCreateKeyedEvent = win_::resolve_proc_address("NtCreateKeyedEvent", 18);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, PCOBJECT_ATTRIBUTES, ULONG)>(ntCreateKeyedEvent)(_keyedEventHandle, _desiredAccess, _objectAttributes, _flags);
    }
    NTSTATUS NtcreateLowBoxToken(PHANDLE _tokenHandle, HANDLE _existingTokenHandle, ACCESS_MASK _desiredAccess, POBJECT_ATTRIBUTES _objectAttributes, PSID _packageSid, ULONG _capabilityCount, PSID_AND_ATTRIBUTES _capabilities, ULONG _handleCount, HANDLE* _handles)
    {
        if (!ntCreateLowBoxToken) ntCreateLowBoxToken = win_::resolve_proc_address("NtCreateLowBoxToken", 19);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, HANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES, PSID, ULONG, PSID_AND_ATTRIBUTES, ULONG, HANDLE*)>(ntCreateLowBoxToken)(_tokenHandle, _existingTokenHandle, _desiredAccess, _objectAttributes, _packageSid, _capabilityCount, _capabilities, _handleCount, _handles);
    }
    NTSTATUS NtcreateMailslotFile(PHANDLE _fileHandle, ACCESS_MASK _desiredAccess, PCOBJECT_ATTRIBUTES _objectAttributes, PIO_STATUS_BLOCK _ioStatusBlock, ULONG _createOptions, ULONG _mailslotQuota, ULONG _maximumMessageSize, PLARGE_INTEGER _readTimeout)
    {
        if (!ntCreateMailslotFile) ntCreateMailslotFile = win_::resolve_proc_address("NtCreateMailslotFile", 20);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, PCOBJECT_ATTRIBUTES, PIO_STATUS_BLOCK, ULONG, ULONG, ULONG, PLARGE_INTEGER)>(ntCreateMailslotFile)(_fileHandle, _desiredAccess, _objectAttributes, _ioStatusBlock, _createOptions, _mailslotQuota, _maximumMessageSize, _readTimeout);
    }
    NTSTATUS NtcreateMutant(PHANDLE _mutantHandle, ACCESS_MASK _desiredAccess, PCOBJECT_ATTRIBUTES _objectAttributes, BOOLEAN _initialOwner)
    {
        if (!ntCreateMutant) ntCreateMutant = win_::resolve_proc_address("NtCreateMutant", 14);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, PCOBJECT_ATTRIBUTES, BOOLEAN)>(ntCreateMutant)(_mutantHandle, _desiredAccess, _objectAttributes, _initialOwner);
    }
    NTSTATUS NtcreateNamedPipeFile(PHANDLE _fileHandle, ACCESS_MASK _desiredAccess, PCOBJECT_ATTRIBUTES _objectAttributes, PIO_STATUS_BLOCK _ioStatusBlock, ULONG _shareAccess, ULONG _createDisposition, ULONG _createOptions, ULONG _namedPipeType, ULONG _readMode, ULONG _completionMode, ULONG _maximumInstances, ULONG _inboundQuota, ULONG _outboundQuota, PLARGE_INTEGER _defaultTimeout)
    {
        if (!ntCreateNamedPipeFile) ntCreateNamedPipeFile = win_::resolve_proc_address("NtCreateNamedPipeFile", 21);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, PCOBJECT_ATTRIBUTES, PIO_STATUS_BLOCK, ULONG, ULONG, ULONG, ULONG, ULONG, ULONG, ULONG, ULONG, ULONG, PLARGE_INTEGER)>(ntCreateNamedPipeFile)(_fileHandle, _desiredAccess, _objectAttributes, _ioStatusBlock, _shareAccess, _createDisposition, _createOptions, _namedPipeType, _readMode, _completionMode, _maximumInstances, _inboundQuota, _outboundQuota, _defaultTimeout);
    }
    NTSTATUS NtcreatePagingFile(PCUNICODE_STRING _pageFileName, PLARGE_INTEGER _minimumSize, PLARGE_INTEGER _maximumSize, ULONG _priority)
    {
        if (!ntCreatePagingFile) ntCreatePagingFile = win_::resolve_proc_address("NtCreatePagingFile", 18);
        return reinterpret_cast<NTSTATUS(*)(PCUNICODE_STRING, PLARGE_INTEGER, PLARGE_INTEGER, ULONG)>(ntCreatePagingFile)(_pageFileName, _minimumSize, _maximumSize, _priority);
    }
    NTSTATUS NtcreatePartition(HANDLE _parentPartitionHandle, PHANDLE _partitionHandle, ACCESS_MASK _desiredAccess, PCOBJECT_ATTRIBUTES _objectAttributes)
    {
        if (!ntCreatePartition) ntCreatePartition = win_::resolve_proc_address("NtCreatePartition", 17);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PHANDLE, ACCESS_MASK, PCOBJECT_ATTRIBUTES)>(ntCreatePartition)(_parentPartitionHandle, _partitionHandle, _desiredAccess, _objectAttributes);
    }
    NTSTATUS NtcreatePort(PHANDLE _portHandle, POBJECT_ATTRIBUTES _objectAttributes, ULONG _maxConnectionInfoLength, ULONG _maxMessageLength, ULONG _maxPoolUsage)
    {
        if (!ntCreatePort) ntCreatePort = win_::resolve_proc_address("NtCreatePort", 12);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, POBJECT_ATTRIBUTES, ULONG, ULONG, ULONG)>(ntCreatePort)(_portHandle, _objectAttributes, _maxConnectionInfoLength, _maxMessageLength, _maxPoolUsage);
    }
    NTSTATUS NtcreatePrivateNamespace(PHANDLE _namespaceHandle, ACCESS_MASK _desiredAccess, POBJECT_ATTRIBUTES _objectAttributes, POBJECT_BOUNDARY_DESCRIPTOR _boundaryDescriptor)
    {
        if (!ntCreatePrivateNamespace) ntCreatePrivateNamespace = win_::resolve_proc_address("NtCreatePrivateNamespace", 24);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES, POBJECT_BOUNDARY_DESCRIPTOR)>(ntCreatePrivateNamespace)(_namespaceHandle, _desiredAccess, _objectAttributes, _boundaryDescriptor);
    }
    NTSTATUS NtcreateProcess(PHANDLE _processHandle, ACCESS_MASK _desiredAccess, PCOBJECT_ATTRIBUTES _objectAttributes, HANDLE _parentProcess, BOOLEAN _inheritObjectTable, HANDLE _sectionHandle, HANDLE _debugPort, HANDLE _tokenHandle)
    {
        if (!ntCreateProcess) ntCreateProcess = win_::resolve_proc_address("NtCreateProcess", 15);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, PCOBJECT_ATTRIBUTES, HANDLE, BOOLEAN, HANDLE, HANDLE, HANDLE)>(ntCreateProcess)(_processHandle, _desiredAccess, _objectAttributes, _parentProcess, _inheritObjectTable, _sectionHandle, _debugPort, _tokenHandle);
    }
    NTSTATUS NtcreateProcessEx(PHANDLE _processHandle, ACCESS_MASK _desiredAccess, PCOBJECT_ATTRIBUTES _objectAttributes, HANDLE _parentProcess, ULONG _flags, HANDLE _sectionHandle, HANDLE _debugPort, HANDLE _tokenHandle, ULONG _reserved)
    {
        if (!ntCreateProcessEx) ntCreateProcessEx = win_::resolve_proc_address("NtCreateProcessEx", 17);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, PCOBJECT_ATTRIBUTES, HANDLE, ULONG, HANDLE, HANDLE, HANDLE, ULONG)>(ntCreateProcessEx)(_processHandle, _desiredAccess, _objectAttributes, _parentProcess, _flags, _sectionHandle, _debugPort, _tokenHandle, _reserved);
    }
    NTSTATUS NtcreateProcessStateChange(PHANDLE _processStateChangeHandle, ACCESS_MASK _desiredAccess, PCOBJECT_ATTRIBUTES _objectAttributes, HANDLE _processHandle, ULONG _reserved)
    {
        if (!ntCreateProcessStateChange) ntCreateProcessStateChange = win_::resolve_proc_address("NtCreateProcessStateChange", 26);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, PCOBJECT_ATTRIBUTES, HANDLE, ULONG)>(ntCreateProcessStateChange)(_processStateChangeHandle, _desiredAccess, _objectAttributes, _processHandle, _reserved);
    }
    NTSTATUS NtcreateProfile(PHANDLE _profileHandle, HANDLE _process, PVOID _profileBase, SIZE_T _profileSize, ULONG _bucketSize, PULONG _buffer, ULONG _bufferSize, KPROFILE_SOURCE _profileSource, KAFFINITY _affinity)
    {
        if (!ntCreateProfile) ntCreateProfile = win_::resolve_proc_address("NtCreateProfile", 15);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, HANDLE, PVOID, SIZE_T, ULONG, PULONG, ULONG, KPROFILE_SOURCE, KAFFINITY)>(ntCreateProfile)(_profileHandle, _process, _profileBase, _profileSize, _bucketSize, _buffer, _bufferSize, _profileSource, _affinity);
    }
    NTSTATUS NtcreateProfileEx(PHANDLE _profileHandle, HANDLE _process, PVOID _profileBase, SIZE_T _profileSize, ULONG _bucketSize, PULONG _buffer, ULONG _bufferSize, KPROFILE_SOURCE _profileSource, USHORT _groupCount, PGROUP_AFFINITY _groupAffinity)
    {
        if (!ntCreateProfileEx) ntCreateProfileEx = win_::resolve_proc_address("NtCreateProfileEx", 17);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, HANDLE, PVOID, SIZE_T, ULONG, PULONG, ULONG, KPROFILE_SOURCE, USHORT, PGROUP_AFFINITY)>(ntCreateProfileEx)(_profileHandle, _process, _profileBase, _profileSize, _bucketSize, _buffer, _bufferSize, _profileSource, _groupCount, _groupAffinity);
    }
    NTSTATUS NtcreateRegistryTransaction(HANDLE* _registryTransactionHandle, ACCESS_MASK _desiredAccess, POBJECT_ATTRIBUTES _objAttributes, ULONG _createOptions)
    {
        if (!ntCreateRegistryTransaction) ntCreateRegistryTransaction = win_::resolve_proc_address("NtCreateRegistryTransaction", 27);
        return reinterpret_cast<NTSTATUS(*)(HANDLE*, ACCESS_MASK, POBJECT_ATTRIBUTES, ULONG)>(ntCreateRegistryTransaction)(_registryTransactionHandle, _desiredAccess, _objAttributes, _createOptions);
    }
    NTSTATUS NtcreateResourceManager(PHANDLE _resourceManagerHandle, ACCESS_MASK _desiredAccess, HANDLE _tmHandle, LPGUID _rmGuid, POBJECT_ATTRIBUTES _objectAttributes, ULONG _createOptions, PCUNICODE_STRING _description)
    {
        if (!ntCreateResourceManager) ntCreateResourceManager = win_::resolve_proc_address("NtCreateResourceManager", 23);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, HANDLE, LPGUID, POBJECT_ATTRIBUTES, ULONG, PCUNICODE_STRING)>(ntCreateResourceManager)(_resourceManagerHandle, _desiredAccess, _tmHandle, _rmGuid, _objectAttributes, _createOptions, _description);
    }
    NTSTATUS NtcreateSection(PHANDLE _sectionHandle, ACCESS_MASK _desiredAccess, PCOBJECT_ATTRIBUTES _objectAttributes, PLARGE_INTEGER _maximumSize, ULONG _sectionPageProtection, ULONG _allocationAttributes, HANDLE _fileHandle)
    {
        if (!ntCreateSection) ntCreateSection = win_::resolve_proc_address("NtCreateSection", 15);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, PCOBJECT_ATTRIBUTES, PLARGE_INTEGER, ULONG, ULONG, HANDLE)>(ntCreateSection)(_sectionHandle, _desiredAccess, _objectAttributes, _maximumSize, _sectionPageProtection, _allocationAttributes, _fileHandle);
    }
    NTSTATUS NtcreateSectionEx(PHANDLE _sectionHandle, ACCESS_MASK _desiredAccess, PCOBJECT_ATTRIBUTES _objectAttributes, PLARGE_INTEGER _maximumSize, ULONG _sectionPageProtection, ULONG _allocationAttributes, HANDLE _fileHandle, PMEM_EXTENDED_PARAMETER _extendedParameters, ULONG _extendedParameterCount)
    {
        if (!ntCreateSectionEx) ntCreateSectionEx = win_::resolve_proc_address("NtCreateSectionEx", 17);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, PCOBJECT_ATTRIBUTES, PLARGE_INTEGER, ULONG, ULONG, HANDLE, PMEM_EXTENDED_PARAMETER, ULONG)>(ntCreateSectionEx)(_sectionHandle, _desiredAccess, _objectAttributes, _maximumSize, _sectionPageProtection, _allocationAttributes, _fileHandle, _extendedParameters, _extendedParameterCount);
    }
    NTSTATUS NtcreateSemaphore(PHANDLE _semaphoreHandle, ACCESS_MASK _desiredAccess, PCOBJECT_ATTRIBUTES _objectAttributes, LONG _initialCount, LONG _maximumCount)
    {
        if (!ntCreateSemaphore) ntCreateSemaphore = win_::resolve_proc_address("NtCreateSemaphore", 17);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, PCOBJECT_ATTRIBUTES, LONG, LONG)>(ntCreateSemaphore)(_semaphoreHandle, _desiredAccess, _objectAttributes, _initialCount, _maximumCount);
    }
    NTSTATUS NtcreateSymbolicLinkObject(PHANDLE _linkHandle, ACCESS_MASK _desiredAccess, POBJECT_ATTRIBUTES _objectAttributes, PCUNICODE_STRING _linkTarget)
    {
        if (!ntCreateSymbolicLinkObject) ntCreateSymbolicLinkObject = win_::resolve_proc_address("NtCreateSymbolicLinkObject", 26);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES, PCUNICODE_STRING)>(ntCreateSymbolicLinkObject)(_linkHandle, _desiredAccess, _objectAttributes, _linkTarget);
    }
    NTSTATUS NtcreateThread(PHANDLE _threadHandle, ACCESS_MASK _desiredAccess, PCOBJECT_ATTRIBUTES _objectAttributes, HANDLE _processHandle, PCLIENT_ID _clientId, PCONTEXT _threadContext, PINITIAL_TEB _initialTeb, BOOLEAN _createSuspended)
    {
        if (!ntCreateThread) ntCreateThread = win_::resolve_proc_address("NtCreateThread", 14);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, PCOBJECT_ATTRIBUTES, HANDLE, PCLIENT_ID, PCONTEXT, PINITIAL_TEB, BOOLEAN)>(ntCreateThread)(_threadHandle, _desiredAccess, _objectAttributes, _processHandle, _clientId, _threadContext, _initialTeb, _createSuspended);
    }
    NTSTATUS NtcreateThreadEx(PHANDLE _threadHandle, ACCESS_MASK _desiredAccess, PCOBJECT_ATTRIBUTES _objectAttributes, HANDLE _processHandle, PUSER_THREAD_START_ROUTINE _startRoutine, PVOID _argument, ULONG _createFlags, SIZE_T _zeroBits, SIZE_T _stackSize, SIZE_T _maximumStackSize, PPS_ATTRIBUTE_LIST _attributeList)
    {
        if (!ntCreateThreadEx) ntCreateThreadEx = win_::resolve_proc_address("NtCreateThreadEx", 16);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, PCOBJECT_ATTRIBUTES, HANDLE, PUSER_THREAD_START_ROUTINE, PVOID, ULONG, SIZE_T, SIZE_T, SIZE_T, PPS_ATTRIBUTE_LIST)>(ntCreateThreadEx)(_threadHandle, _desiredAccess, _objectAttributes, _processHandle, _startRoutine, _argument, _createFlags, _zeroBits, _stackSize, _maximumStackSize, _attributeList);
    }
    NTSTATUS NtcreateThreadStateChange(PHANDLE _threadStateChangeHandle, ACCESS_MASK _desiredAccess, PCOBJECT_ATTRIBUTES _objectAttributes, HANDLE _threadHandle, ULONG _reserved)
    {
        if (!ntCreateThreadStateChange) ntCreateThreadStateChange = win_::resolve_proc_address("NtCreateThreadStateChange", 25);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, PCOBJECT_ATTRIBUTES, HANDLE, ULONG)>(ntCreateThreadStateChange)(_threadStateChangeHandle, _desiredAccess, _objectAttributes, _threadHandle, _reserved);
    }
    NTSTATUS NtcreateTimer(PHANDLE _timerHandle, ACCESS_MASK _desiredAccess, PCOBJECT_ATTRIBUTES _objectAttributes, TIMER_TYPE _timerType)
    {
        if (!ntCreateTimer) ntCreateTimer = win_::resolve_proc_address("NtCreateTimer", 13);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, PCOBJECT_ATTRIBUTES, TIMER_TYPE)>(ntCreateTimer)(_timerHandle, _desiredAccess, _objectAttributes, _timerType);
    }
    NTSTATUS NtcreateTimer2(PHANDLE _timerHandle, PULONG _timerId, PCOBJECT_ATTRIBUTES _objectAttributes, ULONG _attributes, ACCESS_MASK _desiredAccess)
    {
        if (!ntCreateTimer2) ntCreateTimer2 = win_::resolve_proc_address("NtCreateTimer2", 14);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, PULONG, PCOBJECT_ATTRIBUTES, ULONG, ACCESS_MASK)>(ntCreateTimer2)(_timerHandle, _timerId, _objectAttributes, _attributes, _desiredAccess);
    }
    NTSTATUS NtcreateToken(PHANDLE _tokenHandle, ACCESS_MASK _desiredAccess, POBJECT_ATTRIBUTES _objectAttributes, TOKEN_TYPE _type, PLUID _authenticationId, PLARGE_INTEGER _expirationTime, PTOKEN_USER _user, PTOKEN_GROUPS _groups, PTOKEN_PRIVILEGES _privileges, PTOKEN_OWNER _owner, PTOKEN_PRIMARY_GROUP _primaryGroup, PTOKEN_DEFAULT_DACL _defaultDacl, PTOKEN_SOURCE _source)
    {
        if (!ntCreateToken) ntCreateToken = win_::resolve_proc_address("NtCreateToken", 13);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES, TOKEN_TYPE, PLUID, PLARGE_INTEGER, PTOKEN_USER, PTOKEN_GROUPS, PTOKEN_PRIVILEGES, PTOKEN_OWNER, PTOKEN_PRIMARY_GROUP, PTOKEN_DEFAULT_DACL, PTOKEN_SOURCE)>(ntCreateToken)(_tokenHandle, _desiredAccess, _objectAttributes, _type, _authenticationId, _expirationTime, _user, _groups, _privileges, _owner, _primaryGroup, _defaultDacl, _source);
    }
    NTSTATUS NtcreateTokenEx(PHANDLE _tokenHandle, ACCESS_MASK _desiredAccess, POBJECT_ATTRIBUTES _objectAttributes, TOKEN_TYPE _type, PLUID _authenticationId, PLARGE_INTEGER _expirationTime, PTOKEN_USER _user, PTOKEN_GROUPS _groups, PTOKEN_PRIVILEGES _privileges, PTOKEN_SECURITY_ATTRIBUTES_INFORMATION _userAttributes, PTOKEN_SECURITY_ATTRIBUTES_INFORMATION _deviceAttributes, PTOKEN_GROUPS _deviceGroups, PTOKEN_MANDATORY_POLICY _mandatoryPolicy, PTOKEN_OWNER _owner, PTOKEN_PRIMARY_GROUP _primaryGroup, PTOKEN_DEFAULT_DACL _defaultDacl, PTOKEN_SOURCE _source)
    {
        if (!ntCreateTokenEx) ntCreateTokenEx = win_::resolve_proc_address("NtCreateTokenEx", 15);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES, TOKEN_TYPE, PLUID, PLARGE_INTEGER, PTOKEN_USER, PTOKEN_GROUPS, PTOKEN_PRIVILEGES, PTOKEN_SECURITY_ATTRIBUTES_INFORMATION, PTOKEN_SECURITY_ATTRIBUTES_INFORMATION, PTOKEN_GROUPS, PTOKEN_MANDATORY_POLICY, PTOKEN_OWNER, PTOKEN_PRIMARY_GROUP, PTOKEN_DEFAULT_DACL, PTOKEN_SOURCE)>(ntCreateTokenEx)(_tokenHandle, _desiredAccess, _objectAttributes, _type, _authenticationId, _expirationTime, _user, _groups, _privileges, _userAttributes, _deviceAttributes, _deviceGroups, _mandatoryPolicy, _owner, _primaryGroup, _defaultDacl, _source);
    }
    NTSTATUS NtcreateTransaction(PHANDLE _transactionHandle, ACCESS_MASK _desiredAccess, POBJECT_ATTRIBUTES _objectAttributes, LPGUID _uow, HANDLE _tmHandle, ULONG _createOptions, ULONG _isolationLevel, ULONG _isolationFlags, PLARGE_INTEGER _timeout, PCUNICODE_STRING _description)
    {
        if (!ntCreateTransaction) ntCreateTransaction = win_::resolve_proc_address("NtCreateTransaction", 19);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES, LPGUID, HANDLE, ULONG, ULONG, ULONG, PLARGE_INTEGER, PCUNICODE_STRING)>(ntCreateTransaction)(_transactionHandle, _desiredAccess, _objectAttributes, _uow, _tmHandle, _createOptions, _isolationLevel, _isolationFlags, _timeout, _description);
    }
    NTSTATUS NtcreateTransactionManager(PHANDLE _tmHandle, ACCESS_MASK _desiredAccess, POBJECT_ATTRIBUTES _objectAttributes, PCUNICODE_STRING _logFileName, ULONG _createOptions, ULONG _commitStrength)
    {
        if (!ntCreateTransactionManager) ntCreateTransactionManager = win_::resolve_proc_address("NtCreateTransactionManager", 26);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES, PCUNICODE_STRING, ULONG, ULONG)>(ntCreateTransactionManager)(_tmHandle, _desiredAccess, _objectAttributes, _logFileName, _createOptions, _commitStrength);
    }
    NTSTATUS NtcreateUserProcess(PHANDLE _processHandle, PHANDLE _threadHandle, ACCESS_MASK _processDesiredAccess, ACCESS_MASK _threadDesiredAccess, PCOBJECT_ATTRIBUTES _processObjectAttributes, PCOBJECT_ATTRIBUTES _threadObjectAttributes, ULONG _processFlags, ULONG _threadFlags, PRTL_USER_PROCESS_PARAMETERS _processParameters, PPS_CREATE_INFO _createInfo, PPS_ATTRIBUTE_LIST _attributeList)
    {
        if (!ntCreateUserProcess) ntCreateUserProcess = win_::resolve_proc_address("NtCreateUserProcess", 19);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, PHANDLE, ACCESS_MASK, ACCESS_MASK, PCOBJECT_ATTRIBUTES, PCOBJECT_ATTRIBUTES, ULONG, ULONG, PRTL_USER_PROCESS_PARAMETERS, PPS_CREATE_INFO, PPS_ATTRIBUTE_LIST)>(ntCreateUserProcess)(_processHandle, _threadHandle, _processDesiredAccess, _threadDesiredAccess, _processObjectAttributes, _threadObjectAttributes, _processFlags, _threadFlags, _processParameters, _createInfo, _attributeList);
    }
    NTSTATUS NtcreateWaitCompletionPacket(PHANDLE _waitCompletionPacketHandle, ACCESS_MASK _desiredAccess, PCOBJECT_ATTRIBUTES _objectAttributes)
    {
        if (!ntCreateWaitCompletionPacket) ntCreateWaitCompletionPacket = win_::resolve_proc_address("NtCreateWaitCompletionPacket", 28);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, PCOBJECT_ATTRIBUTES)>(ntCreateWaitCompletionPacket)(_waitCompletionPacketHandle, _desiredAccess, _objectAttributes);
    }
    NTSTATUS NtcreateWaitablePort(PHANDLE _portHandle, POBJECT_ATTRIBUTES _objectAttributes, ULONG _maxConnectionInfoLength, ULONG _maxMessageLength, ULONG _maxPoolUsage)
    {
        if (!ntCreateWaitablePort) ntCreateWaitablePort = win_::resolve_proc_address("NtCreateWaitablePort", 20);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, POBJECT_ATTRIBUTES, ULONG, ULONG, ULONG)>(ntCreateWaitablePort)(_portHandle, _objectAttributes, _maxConnectionInfoLength, _maxMessageLength, _maxPoolUsage);
    }
    NTSTATUS NtcreateWnfStateName(PWNF_STATE_NAME _stateName, WNF_STATE_NAME_LIFETIME _nameLifetime, WNF_DATA_SCOPE _dataScope, BOOLEAN _persistData, PCWNF_TYPE_ID _typeId, ULONG _maximumStateSize, PSECURITY_DESCRIPTOR _securityDescriptor)
    {
        if (!ntCreateWnfStateName) ntCreateWnfStateName = win_::resolve_proc_address("NtCreateWnfStateName", 20);
        return reinterpret_cast<NTSTATUS(*)(PWNF_STATE_NAME, WNF_STATE_NAME_LIFETIME, WNF_DATA_SCOPE, BOOLEAN, PCWNF_TYPE_ID, ULONG, PSECURITY_DESCRIPTOR)>(ntCreateWnfStateName)(_stateName, _nameLifetime, _dataScope, _persistData, _typeId, _maximumStateSize, _securityDescriptor);
    }
    NTSTATUS NtcreateWorkerFactory(PHANDLE _workerFactoryHandleReturn, ACCESS_MASK _desiredAccess, PCOBJECT_ATTRIBUTES _objectAttributes, HANDLE _completionPortHandle, HANDLE _workerProcessHandle, PVOID _startRoutine, PVOID _startParameter, ULONG _maxThreadCount, SIZE_T _stackReserve, SIZE_T _stackCommit)
    {
        if (!ntCreateWorkerFactory) ntCreateWorkerFactory = win_::resolve_proc_address("NtCreateWorkerFactory", 21);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, PCOBJECT_ATTRIBUTES, HANDLE, HANDLE, PVOID, PVOID, ULONG, SIZE_T, SIZE_T)>(ntCreateWorkerFactory)(_workerFactoryHandleReturn, _desiredAccess, _objectAttributes, _completionPortHandle, _workerProcessHandle, _startRoutine, _startParameter, _maxThreadCount, _stackReserve, _stackCommit);
    }
    NTSTATUS NtdebugActiveProcess(HANDLE _processHandle, HANDLE _debugObjectHandle)
    {
        if (!ntDebugActiveProcess) ntDebugActiveProcess = win_::resolve_proc_address("NtDebugActiveProcess", 20);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE)>(ntDebugActiveProcess)(_processHandle, _debugObjectHandle);
    }
    NTSTATUS NtdebugContinue(HANDLE _debugObjectHandle, PCLIENT_ID _clientId, NTSTATUS _continueStatus)
    {
        if (!ntDebugContinue) ntDebugContinue = win_::resolve_proc_address("NtDebugContinue", 15);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PCLIENT_ID, NTSTATUS)>(ntDebugContinue)(_debugObjectHandle, _clientId, _continueStatus);
    }
    NTSTATUS NtdelayExecution(BOOLEAN _alertable, PLARGE_INTEGER _delayInterval)
    {
        if (!ntDelayExecution) ntDelayExecution = win_::resolve_proc_address("NtDelayExecution", 16);
        return reinterpret_cast<NTSTATUS(*)(BOOLEAN, PLARGE_INTEGER)>(ntDelayExecution)(_alertable, _delayInterval);
    }
    NTSTATUS NtdeleteAtom(RTL_ATOM _atom)
    {
        if (!ntDeleteAtom) ntDeleteAtom = win_::resolve_proc_address("NtDeleteAtom", 12);
        return reinterpret_cast<NTSTATUS(*)(RTL_ATOM)>(ntDeleteAtom)(_atom);
    }
    NTSTATUS NtdeleteBootEntry(ULONG _id)
    {
        if (!ntDeleteBootEntry) ntDeleteBootEntry = win_::resolve_proc_address("NtDeleteBootEntry", 17);
        return reinterpret_cast<NTSTATUS(*)(ULONG)>(ntDeleteBootEntry)(_id);
    }
    NTSTATUS NtdeleteDriverEntry(ULONG _id)
    {
        if (!ntDeleteDriverEntry) ntDeleteDriverEntry = win_::resolve_proc_address("NtDeleteDriverEntry", 19);
        return reinterpret_cast<NTSTATUS(*)(ULONG)>(ntDeleteDriverEntry)(_id);
    }
    NTSTATUS NtdeleteFile(PCOBJECT_ATTRIBUTES _objectAttributes)
    {
        if (!ntDeleteFile) ntDeleteFile = win_::resolve_proc_address("NtDeleteFile", 12);
        return reinterpret_cast<NTSTATUS(*)(PCOBJECT_ATTRIBUTES)>(ntDeleteFile)(_objectAttributes);
    }
    NTSTATUS NtdeleteKey(HANDLE _keyHandle)
    {
        if (!ntDeleteKey) ntDeleteKey = win_::resolve_proc_address("NtDeleteKey", 11);
        return reinterpret_cast<NTSTATUS(*)(HANDLE)>(ntDeleteKey)(_keyHandle);
    }
    NTSTATUS NtdeleteObjectAuditAlarm(PCUNICODE_STRING _subsystemName, PVOID _handleId, BOOLEAN _generateOnClose)
    {
        if (!ntDeleteObjectAuditAlarm) ntDeleteObjectAuditAlarm = win_::resolve_proc_address("NtDeleteObjectAuditAlarm", 24);
        return reinterpret_cast<NTSTATUS(*)(PCUNICODE_STRING, PVOID, BOOLEAN)>(ntDeleteObjectAuditAlarm)(_subsystemName, _handleId, _generateOnClose);
    }
    NTSTATUS NtdeletePrivateNamespace(HANDLE _namespaceHandle)
    {
        if (!ntDeletePrivateNamespace) ntDeletePrivateNamespace = win_::resolve_proc_address("NtDeletePrivateNamespace", 24);
        return reinterpret_cast<NTSTATUS(*)(HANDLE)>(ntDeletePrivateNamespace)(_namespaceHandle);
    }
    NTSTATUS NtdeleteValueKey(HANDLE _keyHandle, PCUNICODE_STRING _valueName)
    {
        if (!ntDeleteValueKey) ntDeleteValueKey = win_::resolve_proc_address("NtDeleteValueKey", 16);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PCUNICODE_STRING)>(ntDeleteValueKey)(_keyHandle, _valueName);
    }
    NTSTATUS NtdeleteWnfStateData(PCWNF_STATE_NAME _stateName, PCSID _explicitScope)
    {
        if (!ntDeleteWnfStateData) ntDeleteWnfStateData = win_::resolve_proc_address("NtDeleteWnfStateData", 20);
        return reinterpret_cast<NTSTATUS(*)(PCWNF_STATE_NAME, PCSID)>(ntDeleteWnfStateData)(_stateName, _explicitScope);
    }
    NTSTATUS NtdeleteWnfStateName(PCWNF_STATE_NAME _stateName)
    {
        if (!ntDeleteWnfStateName) ntDeleteWnfStateName = win_::resolve_proc_address("NtDeleteWnfStateName", 20);
        return reinterpret_cast<NTSTATUS(*)(PCWNF_STATE_NAME)>(ntDeleteWnfStateName)(_stateName);
    }
    NTSTATUS NtdeviceIoControlFile(HANDLE _fileHandle, HANDLE _event, PIO_APC_ROUTINE _apcRoutine, PVOID _apcContext, PIO_STATUS_BLOCK _ioStatusBlock, ULONG _ioControlCode, PVOID _inputBuffer, ULONG _inputBufferLength, PVOID _outputBuffer, ULONG _outputBufferLength)
    {
        if (!ntDeviceIoControlFile) ntDeviceIoControlFile = win_::resolve_proc_address("NtDeviceIoControlFile", 21);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE, PIO_APC_ROUTINE, PVOID, PIO_STATUS_BLOCK, ULONG, PVOID, ULONG, PVOID, ULONG)>(ntDeviceIoControlFile)(_fileHandle, _event, _apcRoutine, _apcContext, _ioStatusBlock, _ioControlCode, _inputBuffer, _inputBufferLength, _outputBuffer, _outputBufferLength);
    }
    NTSTATUS NtdirectGraphicsCall(ULONG _inputBufferLength, PVOID _inputBuffer, ULONG _outputBufferLength, PVOID _outputBuffer, PULONG _returnLength)
    {
        if (!ntDirectGraphicsCall) ntDirectGraphicsCall = win_::resolve_proc_address("NtDirectGraphicsCall", 20);
        return reinterpret_cast<NTSTATUS(*)(ULONG, PVOID, ULONG, PVOID, PULONG)>(ntDirectGraphicsCall)(_inputBufferLength, _inputBuffer, _outputBufferLength, _outputBuffer, _returnLength);
    }
    NTSTATUS NtdisableLastKnownGood()
    {
        if (!ntDisableLastKnownGood) ntDisableLastKnownGood = win_::resolve_proc_address("NtDisableLastKnownGood", 22);
        return reinterpret_cast<NTSTATUS(*)()>(ntDisableLastKnownGood)();
    }
    NTSTATUS NtdisplayString(PCUNICODE_STRING _string)
    {
        if (!ntDisplayString) ntDisplayString = win_::resolve_proc_address("NtDisplayString", 15);
        return reinterpret_cast<NTSTATUS(*)(PCUNICODE_STRING)>(ntDisplayString)(_string);
    }
    NTSTATUS NtdrawText(PCUNICODE_STRING _text)
    {
        if (!ntDrawText) ntDrawText = win_::resolve_proc_address("NtDrawText", 10);
        return reinterpret_cast<NTSTATUS(*)(PCUNICODE_STRING)>(ntDrawText)(_text);
    }
    NTSTATUS NtduplicateObject(HANDLE _sourceProcessHandle, HANDLE _sourceHandle, HANDLE _targetProcessHandle, PHANDLE _targetHandle, ACCESS_MASK _desiredAccess, ULONG _handleAttributes, ULONG _options)
    {
        if (!ntDuplicateObject) ntDuplicateObject = win_::resolve_proc_address("NtDuplicateObject", 17);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE, HANDLE, PHANDLE, ACCESS_MASK, ULONG, ULONG)>(ntDuplicateObject)(_sourceProcessHandle, _sourceHandle, _targetProcessHandle, _targetHandle, _desiredAccess, _handleAttributes, _options);
    }
    NTSTATUS NtduplicateToken(HANDLE _existingTokenHandle, ACCESS_MASK _desiredAccess, POBJECT_ATTRIBUTES _objectAttributes, BOOLEAN _effectiveOnly, TOKEN_TYPE _type, PHANDLE _newTokenHandle)
    {
        if (!ntDuplicateToken) ntDuplicateToken = win_::resolve_proc_address("NtDuplicateToken", 16);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES, BOOLEAN, TOKEN_TYPE, PHANDLE)>(ntDuplicateToken)(_existingTokenHandle, _desiredAccess, _objectAttributes, _effectiveOnly, _type, _newTokenHandle);
    }
    NTSTATUS NtenableLastKnownGood()
    {
        if (!ntEnableLastKnownGood) ntEnableLastKnownGood = win_::resolve_proc_address("NtEnableLastKnownGood", 21);
        return reinterpret_cast<NTSTATUS(*)()>(ntEnableLastKnownGood)();
    }
    NTSTATUS NtenumerateBootEntries(PVOID _buffer, PULONG _bufferLength)
    {
        if (!ntEnumerateBootEntries) ntEnumerateBootEntries = win_::resolve_proc_address("NtEnumerateBootEntries", 22);
        return reinterpret_cast<NTSTATUS(*)(PVOID, PULONG)>(ntEnumerateBootEntries)(_buffer, _bufferLength);
    }
    NTSTATUS NtenumerateDriverEntries(PVOID _buffer, PULONG _bufferLength)
    {
        if (!ntEnumerateDriverEntries) ntEnumerateDriverEntries = win_::resolve_proc_address("NtEnumerateDriverEntries", 24);
        return reinterpret_cast<NTSTATUS(*)(PVOID, PULONG)>(ntEnumerateDriverEntries)(_buffer, _bufferLength);
    }
    NTSTATUS NtenumerateKey(HANDLE _keyHandle, ULONG _index, KEY_INFORMATION_CLASS _keyInformationClass, PVOID _keyInformation, ULONG _length, PULONG _resultLength)
    {
        if (!ntEnumerateKey) ntEnumerateKey = win_::resolve_proc_address("NtEnumerateKey", 14);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONG, KEY_INFORMATION_CLASS, PVOID, ULONG, PULONG)>(ntEnumerateKey)(_keyHandle, _index, _keyInformationClass, _keyInformation, _length, _resultLength);
    }
    NTSTATUS NtenumerateSystemEnvironmentValuesEx(ULONG _informationClass, PVOID _buffer, PULONG _bufferLength)
    {
        if (!ntEnumerateSystemEnvironmentValuesEx) ntEnumerateSystemEnvironmentValuesEx = win_::resolve_proc_address("NtEnumerateSystemEnvironmentValuesEx", 36);
        return reinterpret_cast<NTSTATUS(*)(ULONG, PVOID, PULONG)>(ntEnumerateSystemEnvironmentValuesEx)(_informationClass, _buffer, _bufferLength);
    }
    NTSTATUS NtenumerateTransactionObject(HANDLE _rootObjectHandle, KTMOBJECT_TYPE _queryType, PKTMOBJECT_CURSOR _objectCursor, ULONG _objectCursorLength, PULONG _returnLength)
    {
        if (!ntEnumerateTransactionObject) ntEnumerateTransactionObject = win_::resolve_proc_address("NtEnumerateTransactionObject", 28);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, KTMOBJECT_TYPE, PKTMOBJECT_CURSOR, ULONG, PULONG)>(ntEnumerateTransactionObject)(_rootObjectHandle, _queryType, _objectCursor, _objectCursorLength, _returnLength);
    }
    NTSTATUS NtenumerateValueKey(HANDLE _keyHandle, ULONG _index, KEY_VALUE_INFORMATION_CLASS _keyValueInformationClass, PVOID _keyValueInformation, ULONG _length, PULONG _resultLength)
    {
        if (!ntEnumerateValueKey) ntEnumerateValueKey = win_::resolve_proc_address("NtEnumerateValueKey", 19);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONG, KEY_VALUE_INFORMATION_CLASS, PVOID, ULONG, PULONG)>(ntEnumerateValueKey)(_keyHandle, _index, _keyValueInformationClass, _keyValueInformation, _length, _resultLength);
    }
    NTSTATUS NtextendSection(HANDLE _sectionHandle, PLARGE_INTEGER _newSectionSize)
    {
        if (!ntExtendSection) ntExtendSection = win_::resolve_proc_address("NtExtendSection", 15);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PLARGE_INTEGER)>(ntExtendSection)(_sectionHandle, _newSectionSize);
    }
    NTSTATUS NtfilterBootOption(FILTER_BOOT_OPTION_OPERATION _filterOperation, ULONG _objectType, ULONG _elementType, PVOID _data, ULONG _dataSize)
    {
        if (!ntFilterBootOption) ntFilterBootOption = win_::resolve_proc_address("NtFilterBootOption", 18);
        return reinterpret_cast<NTSTATUS(*)(FILTER_BOOT_OPTION_OPERATION, ULONG, ULONG, PVOID, ULONG)>(ntFilterBootOption)(_filterOperation, _objectType, _elementType, _data, _dataSize);
    }
    NTSTATUS NtfilterToken(HANDLE _existingTokenHandle, ULONG _flags, PTOKEN_GROUPS _sidsToDisable, PTOKEN_PRIVILEGES _privilegesToDelete, PTOKEN_GROUPS _restrictedSids, PHANDLE _newTokenHandle)
    {
        if (!ntFilterToken) ntFilterToken = win_::resolve_proc_address("NtFilterToken", 13);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONG, PTOKEN_GROUPS, PTOKEN_PRIVILEGES, PTOKEN_GROUPS, PHANDLE)>(ntFilterToken)(_existingTokenHandle, _flags, _sidsToDisable, _privilegesToDelete, _restrictedSids, _newTokenHandle);
    }
    NTSTATUS NtfilterTokenEx(HANDLE _existingTokenHandle, ULONG _flags, PTOKEN_GROUPS _sidsToDisable, PTOKEN_PRIVILEGES _privilegesToDelete, PTOKEN_GROUPS _restrictedSids, ULONG _disableUserClaimsCount, PCUNICODE_STRING _userClaimsToDisable, ULONG _disableDeviceClaimsCount, PCUNICODE_STRING _deviceClaimsToDisable, PTOKEN_GROUPS _deviceGroupsToDisable, PTOKEN_SECURITY_ATTRIBUTES_INFORMATION _restrictedUserAttributes, PTOKEN_SECURITY_ATTRIBUTES_INFORMATION _restrictedDeviceAttributes, PTOKEN_GROUPS _restrictedDeviceGroups, PHANDLE _newTokenHandle)
    {
        if (!ntFilterTokenEx) ntFilterTokenEx = win_::resolve_proc_address("NtFilterTokenEx", 15);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONG, PTOKEN_GROUPS, PTOKEN_PRIVILEGES, PTOKEN_GROUPS, ULONG, PCUNICODE_STRING, ULONG, PCUNICODE_STRING, PTOKEN_GROUPS, PTOKEN_SECURITY_ATTRIBUTES_INFORMATION, PTOKEN_SECURITY_ATTRIBUTES_INFORMATION, PTOKEN_GROUPS, PHANDLE)>(ntFilterTokenEx)(_existingTokenHandle, _flags, _sidsToDisable, _privilegesToDelete, _restrictedSids, _disableUserClaimsCount, _userClaimsToDisable, _disableDeviceClaimsCount, _deviceClaimsToDisable, _deviceGroupsToDisable, _restrictedUserAttributes, _restrictedDeviceAttributes, _restrictedDeviceGroups, _newTokenHandle);
    }
    NTSTATUS NtfindAtom(PCWSTR _atomName, ULONG _length, PRTL_ATOM _atom)
    {
        if (!ntFindAtom) ntFindAtom = win_::resolve_proc_address("NtFindAtom", 10);
        return reinterpret_cast<NTSTATUS(*)(PCWSTR, ULONG, PRTL_ATOM)>(ntFindAtom)(_atomName, _length, _atom);
    }
    NTSTATUS NtflushBuffersFile(HANDLE _fileHandle, PIO_STATUS_BLOCK _ioStatusBlock)
    {
        if (!ntFlushBuffersFile) ntFlushBuffersFile = win_::resolve_proc_address("NtFlushBuffersFile", 18);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PIO_STATUS_BLOCK)>(ntFlushBuffersFile)(_fileHandle, _ioStatusBlock);
    }
    NTSTATUS NtflushBuffersFileEx(HANDLE _fileHandle, ULONG _flags, PVOID _parameters, ULONG _parametersSize, PIO_STATUS_BLOCK _ioStatusBlock)
    {
        if (!ntFlushBuffersFileEx) ntFlushBuffersFileEx = win_::resolve_proc_address("NtFlushBuffersFileEx", 20);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONG, PVOID, ULONG, PIO_STATUS_BLOCK)>(ntFlushBuffersFileEx)(_fileHandle, _flags, _parameters, _parametersSize, _ioStatusBlock);
    }
    NTSTATUS NtflushInstallUILanguage(LANGID _installUILanguage, ULONG _setComittedFlag)
    {
        if (!ntFlushInstallUILanguage) ntFlushInstallUILanguage = win_::resolve_proc_address("NtFlushInstallUILanguage", 24);
        return reinterpret_cast<NTSTATUS(*)(LANGID, ULONG)>(ntFlushInstallUILanguage)(_installUILanguage, _setComittedFlag);
    }
    NTSTATUS NtflushInstructionCache(HANDLE _processHandle, PVOID _baseAddress, SIZE_T _regionSize)
    {
        if (!ntFlushInstructionCache) ntFlushInstructionCache = win_::resolve_proc_address("NtFlushInstructionCache", 23);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PVOID, SIZE_T)>(ntFlushInstructionCache)(_processHandle, _baseAddress, _regionSize);
    }
    NTSTATUS NtflushKey(HANDLE _keyHandle)
    {
        if (!ntFlushKey) ntFlushKey = win_::resolve_proc_address("NtFlushKey", 10);
        return reinterpret_cast<NTSTATUS(*)(HANDLE)>(ntFlushKey)(_keyHandle);
    }
    NTSTATUS NtflushProcessWriteBuffers()
    {
        if (!ntFlushProcessWriteBuffers) ntFlushProcessWriteBuffers = win_::resolve_proc_address("NtFlushProcessWriteBuffers", 26);
        return reinterpret_cast<NTSTATUS(*)()>(ntFlushProcessWriteBuffers)();
    }
    NTSTATUS NtflushVirtualMemory(HANDLE _processHandle, PVOID* _baseAddress, PSIZE_T _regionSize, PIO_STATUS_BLOCK _ioStatus)
    {
        if (!ntFlushVirtualMemory) ntFlushVirtualMemory = win_::resolve_proc_address("NtFlushVirtualMemory", 20);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PVOID*, PSIZE_T, PIO_STATUS_BLOCK)>(ntFlushVirtualMemory)(_processHandle, _baseAddress, _regionSize, _ioStatus);
    }
    NTSTATUS NtflushWriteBuffer()
    {
        if (!ntFlushWriteBuffer) ntFlushWriteBuffer = win_::resolve_proc_address("NtFlushWriteBuffer", 18);
        return reinterpret_cast<NTSTATUS(*)()>(ntFlushWriteBuffer)();
    }
    NTSTATUS NtfreeUserPhysicalPages(HANDLE _processHandle, PULONG_PTR _numberOfPages, PULONG_PTR _userPfnArray)
    {
        if (!ntFreeUserPhysicalPages) ntFreeUserPhysicalPages = win_::resolve_proc_address("NtFreeUserPhysicalPages", 23);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PULONG_PTR, PULONG_PTR)>(ntFreeUserPhysicalPages)(_processHandle, _numberOfPages, _userPfnArray);
    }
    NTSTATUS NtfreeVirtualMemory(HANDLE _processHandle, PVOID* _baseAddress, PSIZE_T _regionSize, ULONG _freeType)
    {
        if (!ntFreeVirtualMemory) ntFreeVirtualMemory = win_::resolve_proc_address("NtFreeVirtualMemory", 19);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PVOID*, PSIZE_T, ULONG)>(ntFreeVirtualMemory)(_processHandle, _baseAddress, _regionSize, _freeType);
    }
    NTSTATUS NtfreezeRegistry(ULONG _timeOutInSeconds)
    {
        if (!ntFreezeRegistry) ntFreezeRegistry = win_::resolve_proc_address("NtFreezeRegistry", 16);
        return reinterpret_cast<NTSTATUS(*)(ULONG)>(ntFreezeRegistry)(_timeOutInSeconds);
    }
    NTSTATUS NtfreezeTransactions(PLARGE_INTEGER _freezeTimeout, PLARGE_INTEGER _thawTimeout)
    {
        if (!ntFreezeTransactions) ntFreezeTransactions = win_::resolve_proc_address("NtFreezeTransactions", 20);
        return reinterpret_cast<NTSTATUS(*)(PLARGE_INTEGER, PLARGE_INTEGER)>(ntFreezeTransactions)(_freezeTimeout, _thawTimeout);
    }
    NTSTATUS NtfsControlFile(HANDLE _fileHandle, HANDLE _event, PIO_APC_ROUTINE _apcRoutine, PVOID _apcContext, PIO_STATUS_BLOCK _ioStatusBlock, ULONG _fsControlCode, PVOID _inputBuffer, ULONG _inputBufferLength, PVOID _outputBuffer, ULONG _outputBufferLength)
    {
        if (!ntFsControlFile) ntFsControlFile = win_::resolve_proc_address("NtFsControlFile", 15);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE, PIO_APC_ROUTINE, PVOID, PIO_STATUS_BLOCK, ULONG, PVOID, ULONG, PVOID, ULONG)>(ntFsControlFile)(_fileHandle, _event, _apcRoutine, _apcContext, _ioStatusBlock, _fsControlCode, _inputBuffer, _inputBufferLength, _outputBuffer, _outputBufferLength);
    }
    NTSTATUS NtgetCachedSigningLevel(HANDLE _file, PULONG _flags, PSE_SIGNING_LEVEL _signingLevel, PUCHAR _thumbprint, PULONG _thumbprintSize, PULONG _thumbprintAlgorithm)
    {
        if (!ntGetCachedSigningLevel) ntGetCachedSigningLevel = win_::resolve_proc_address("NtGetCachedSigningLevel", 23);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PULONG, PSE_SIGNING_LEVEL, PUCHAR, PULONG, PULONG)>(ntGetCachedSigningLevel)(_file, _flags, _signingLevel, _thumbprint, _thumbprintSize, _thumbprintAlgorithm);
    }
    NTSTATUS NtgetCompleteWnfStateSubscription(PWNF_STATE_NAME _oldDescriptorStateName, ULONG64* _oldSubscriptionId, ULONG _oldDescriptorEventMask, ULONG _oldDescriptorStatus, PWNF_DELIVERY_DESCRIPTOR _newDeliveryDescriptor, ULONG _descriptorSize)
    {
        if (!ntGetCompleteWnfStateSubscription) ntGetCompleteWnfStateSubscription = win_::resolve_proc_address("NtGetCompleteWnfStateSubscription", 33);
        return reinterpret_cast<NTSTATUS(*)(PWNF_STATE_NAME, ULONG64*, ULONG, ULONG, PWNF_DELIVERY_DESCRIPTOR, ULONG)>(ntGetCompleteWnfStateSubscription)(_oldDescriptorStateName, _oldSubscriptionId, _oldDescriptorEventMask, _oldDescriptorStatus, _newDeliveryDescriptor, _descriptorSize);
    }
    NTSTATUS NtgetContextThread(HANDLE _threadHandle, PCONTEXT _threadContext)
    {
        if (!ntGetContextThread) ntGetContextThread = win_::resolve_proc_address("NtGetContextThread", 18);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PCONTEXT)>(ntGetContextThread)(_threadHandle, _threadContext);
    }
    ULONG NtgetCurrentProcessorNumber()
    {
        if (!ntGetCurrentProcessorNumber) ntGetCurrentProcessorNumber = win_::resolve_proc_address("NtGetCurrentProcessorNumber", 27);
        return reinterpret_cast<ULONG(*)()>(ntGetCurrentProcessorNumber)();
    }
    ULONG NtgetCurrentProcessorNumberEx(PPROCESSOR_NUMBER _processorNumber)
    {
        if (!ntGetCurrentProcessorNumberEx) ntGetCurrentProcessorNumberEx = win_::resolve_proc_address("NtGetCurrentProcessorNumberEx", 29);
        return reinterpret_cast<ULONG(*)(PPROCESSOR_NUMBER)>(ntGetCurrentProcessorNumberEx)(_processorNumber);
    }
    NTSTATUS NtgetDevicePowerState(HANDLE _device, PDEVICE_POWER_STATE _state)
    {
        if (!ntGetDevicePowerState) ntGetDevicePowerState = win_::resolve_proc_address("NtGetDevicePowerState", 21);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PDEVICE_POWER_STATE)>(ntGetDevicePowerState)(_device, _state);
    }
    NTSTATUS NtgetMUIRegistryInfo(ULONG _flags, PULONG _dataSize, PVOID _data)
    {
        if (!ntGetMUIRegistryInfo) ntGetMUIRegistryInfo = win_::resolve_proc_address("NtGetMUIRegistryInfo", 20);
        return reinterpret_cast<NTSTATUS(*)(ULONG, PULONG, PVOID)>(ntGetMUIRegistryInfo)(_flags, _dataSize, _data);
    }
    NTSTATUS NtgetNextProcess(HANDLE _processHandle, ACCESS_MASK _desiredAccess, ULONG _handleAttributes, ULONG _flags, PHANDLE _newProcessHandle)
    {
        if (!ntGetNextProcess) ntGetNextProcess = win_::resolve_proc_address("NtGetNextProcess", 16);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ACCESS_MASK, ULONG, ULONG, PHANDLE)>(ntGetNextProcess)(_processHandle, _desiredAccess, _handleAttributes, _flags, _newProcessHandle);
    }
    NTSTATUS NtgetNextThread(HANDLE _processHandle, HANDLE _threadHandle, ACCESS_MASK _desiredAccess, ULONG _handleAttributes, ULONG _flags, PHANDLE _newThreadHandle)
    {
        if (!ntGetNextThread) ntGetNextThread = win_::resolve_proc_address("NtGetNextThread", 15);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE, ACCESS_MASK, ULONG, ULONG, PHANDLE)>(ntGetNextThread)(_processHandle, _threadHandle, _desiredAccess, _handleAttributes, _flags, _newThreadHandle);
    }
    NTSTATUS NtgetNlsSectionPtr(ULONG _sectionType, ULONG _sectionData, PVOID _contextData, PVOID* _sectionPointer, PULONG _sectionSize)
    {
        if (!ntGetNlsSectionPtr) ntGetNlsSectionPtr = win_::resolve_proc_address("NtGetNlsSectionPtr", 18);
        return reinterpret_cast<NTSTATUS(*)(ULONG, ULONG, PVOID, PVOID*, PULONG)>(ntGetNlsSectionPtr)(_sectionType, _sectionData, _contextData, _sectionPointer, _sectionSize);
    }
    NTSTATUS NtgetNotificationResourceManager(HANDLE _resourceManagerHandle, PTRANSACTION_NOTIFICATION _transactionNotification, ULONG _notificationLength, PLARGE_INTEGER _timeout, PULONG _returnLength, ULONG _asynchronous, ULONG_PTR _asynchronousContext)
    {
        if (!ntGetNotificationResourceManager) ntGetNotificationResourceManager = win_::resolve_proc_address("NtGetNotificationResourceManager", 32);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PTRANSACTION_NOTIFICATION, ULONG, PLARGE_INTEGER, PULONG, ULONG, ULONG_PTR)>(ntGetNotificationResourceManager)(_resourceManagerHandle, _transactionNotification, _notificationLength, _timeout, _returnLength, _asynchronous, _asynchronousContext);
    }
    ULONG NtgetTickCount()
    {
        if (!ntGetTickCount) ntGetTickCount = win_::resolve_proc_address("NtGetTickCount", 14);
        return reinterpret_cast<ULONG(*)()>(ntGetTickCount)();
    }
    ULONGLONG NtgetTickCount64()
    {
        if (!ntGetTickCount64) ntGetTickCount64 = win_::resolve_proc_address("NtGetTickCount64", 16);
        return reinterpret_cast<ULONGLONG(*)()>(ntGetTickCount64)();
    }
    NTSTATUS NtgetWriteWatch(HANDLE _processHandle, ULONG _flags, PVOID _baseAddress, SIZE_T _regionSize, PVOID* _userAddressArray, PULONG_PTR _entriesInUserAddressArray, PULONG _granularity)
    {
        if (!ntGetWriteWatch) ntGetWriteWatch = win_::resolve_proc_address("NtGetWriteWatch", 15);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONG, PVOID, SIZE_T, PVOID*, PULONG_PTR, PULONG)>(ntGetWriteWatch)(_processHandle, _flags, _baseAddress, _regionSize, _userAddressArray, _entriesInUserAddressArray, _granularity);
    }
    NTSTATUS NtimpersonateAnonymousToken(HANDLE _threadHandle)
    {
        if (!ntImpersonateAnonymousToken) ntImpersonateAnonymousToken = win_::resolve_proc_address("NtImpersonateAnonymousToken", 27);
        return reinterpret_cast<NTSTATUS(*)(HANDLE)>(ntImpersonateAnonymousToken)(_threadHandle);
    }
    NTSTATUS NtimpersonateClientOfPort(HANDLE _portHandle, PPORT_MESSAGE _message)
    {
        if (!ntImpersonateClientOfPort) ntImpersonateClientOfPort = win_::resolve_proc_address("NtImpersonateClientOfPort", 25);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PPORT_MESSAGE)>(ntImpersonateClientOfPort)(_portHandle, _message);
    }
    NTSTATUS NtimpersonateThread(HANDLE _serverThreadHandle, HANDLE _clientThreadHandle, PSECURITY_QUALITY_OF_SERVICE _securityQos)
    {
        if (!ntImpersonateThread) ntImpersonateThread = win_::resolve_proc_address("NtImpersonateThread", 19);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE, PSECURITY_QUALITY_OF_SERVICE)>(ntImpersonateThread)(_serverThreadHandle, _clientThreadHandle, _securityQos);
    }
    NTSTATUS NtinitializeEnclave(HANDLE _processHandle, PVOID _baseAddress, PVOID _enclaveInformation, ULONG _enclaveInformationLength, PULONG _enclaveError)
    {
        if (!ntInitializeEnclave) ntInitializeEnclave = win_::resolve_proc_address("NtInitializeEnclave", 19);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PVOID, PVOID, ULONG, PULONG)>(ntInitializeEnclave)(_processHandle, _baseAddress, _enclaveInformation, _enclaveInformationLength, _enclaveError);
    }
    NTSTATUS NtinitializeNlsFiles(PVOID* _baseAddress, PLCID _defaultLocaleId, PLARGE_INTEGER _defaultCasingTableSize, PULONG _currentNLSVersion)
    {
        if (!ntInitializeNlsFiles) ntInitializeNlsFiles = win_::resolve_proc_address("NtInitializeNlsFiles", 20);
        return reinterpret_cast<NTSTATUS(*)(PVOID*, PLCID, PLARGE_INTEGER, PULONG)>(ntInitializeNlsFiles)(_baseAddress, _defaultLocaleId, _defaultCasingTableSize, _currentNLSVersion);
    }
    NTSTATUS NtinitializeRegistry(USHORT _bootCondition)
    {
        if (!ntInitializeRegistry) ntInitializeRegistry = win_::resolve_proc_address("NtInitializeRegistry", 20);
        return reinterpret_cast<NTSTATUS(*)(USHORT)>(ntInitializeRegistry)(_bootCondition);
    }
    NTSTATUS NtinitiatePowerAction(POWER_ACTION _systemAction, SYSTEM_POWER_STATE _lightestSystemState, ULONG _flags, BOOLEAN _asynchronous)
    {
        if (!ntInitiatePowerAction) ntInitiatePowerAction = win_::resolve_proc_address("NtInitiatePowerAction", 21);
        return reinterpret_cast<NTSTATUS(*)(POWER_ACTION, SYSTEM_POWER_STATE, ULONG, BOOLEAN)>(ntInitiatePowerAction)(_systemAction, _lightestSystemState, _flags, _asynchronous);
    }
    NTSTATUS NtisProcessInJob(HANDLE _processHandle, HANDLE _jobHandle)
    {
        if (!ntIsProcessInJob) ntIsProcessInJob = win_::resolve_proc_address("NtIsProcessInJob", 16);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE)>(ntIsProcessInJob)(_processHandle, _jobHandle);
    }
    BOOLEAN NtisSystemResumeAutomatic()
    {
        if (!ntIsSystemResumeAutomatic) ntIsSystemResumeAutomatic = win_::resolve_proc_address("NtIsSystemResumeAutomatic", 25);
        return reinterpret_cast<BOOLEAN(*)()>(ntIsSystemResumeAutomatic)();
    }
    NTSTATUS NtisUILanguageComitted()
    {
        if (!ntIsUILanguageComitted) ntIsUILanguageComitted = win_::resolve_proc_address("NtIsUILanguageComitted", 22);
        return reinterpret_cast<NTSTATUS(*)()>(ntIsUILanguageComitted)();
    }
    NTSTATUS NtlistenPort(HANDLE _portHandle, PPORT_MESSAGE _connectionRequest)
    {
        if (!ntListenPort) ntListenPort = win_::resolve_proc_address("NtListenPort", 12);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PPORT_MESSAGE)>(ntListenPort)(_portHandle, _connectionRequest);
    }
    NTSTATUS NtloadDriver(PCUNICODE_STRING _driverServiceName)
    {
        if (!ntLoadDriver) ntLoadDriver = win_::resolve_proc_address("NtLoadDriver", 12);
        return reinterpret_cast<NTSTATUS(*)(PCUNICODE_STRING)>(ntLoadDriver)(_driverServiceName);
    }
    NTSTATUS NtloadEnclaveData(HANDLE _processHandle, PVOID _baseAddress, PVOID _buffer, SIZE_T _bufferSize, ULONG _protect, PVOID _pageInformation, ULONG _pageInformationLength, PSIZE_T _numberOfBytesWritten, PULONG _enclaveError)
    {
        if (!ntLoadEnclaveData) ntLoadEnclaveData = win_::resolve_proc_address("NtLoadEnclaveData", 17);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PVOID, PVOID, SIZE_T, ULONG, PVOID, ULONG, PSIZE_T, PULONG)>(ntLoadEnclaveData)(_processHandle, _baseAddress, _buffer, _bufferSize, _protect, _pageInformation, _pageInformationLength, _numberOfBytesWritten, _enclaveError);
    }
    NTSTATUS NtloadKey(POBJECT_ATTRIBUTES _targetKey, POBJECT_ATTRIBUTES _sourceFile)
    {
        if (!ntLoadKey) ntLoadKey = win_::resolve_proc_address("NtLoadKey", 9);
        return reinterpret_cast<NTSTATUS(*)(POBJECT_ATTRIBUTES, POBJECT_ATTRIBUTES)>(ntLoadKey)(_targetKey, _sourceFile);
    }
    NTSTATUS NtloadKey2(POBJECT_ATTRIBUTES _targetKey, POBJECT_ATTRIBUTES _sourceFile, ULONG _flags)
    {
        if (!ntLoadKey2) ntLoadKey2 = win_::resolve_proc_address("NtLoadKey2", 10);
        return reinterpret_cast<NTSTATUS(*)(POBJECT_ATTRIBUTES, POBJECT_ATTRIBUTES, ULONG)>(ntLoadKey2)(_targetKey, _sourceFile, _flags);
    }
    NTSTATUS NtloadKey3(POBJECT_ATTRIBUTES _targetKey, POBJECT_ATTRIBUTES _sourceFile, ULONG _flags, PCM_EXTENDED_PARAMETER _extendedParameters, ULONG _extendedParameterCount, ACCESS_MASK _desiredAccess, PHANDLE _rootHandle, PVOID _reserved)
    {
        if (!ntLoadKey3) ntLoadKey3 = win_::resolve_proc_address("NtLoadKey3", 10);
        return reinterpret_cast<NTSTATUS(*)(POBJECT_ATTRIBUTES, POBJECT_ATTRIBUTES, ULONG, PCM_EXTENDED_PARAMETER, ULONG, ACCESS_MASK, PHANDLE, PVOID)>(ntLoadKey3)(_targetKey, _sourceFile, _flags, _extendedParameters, _extendedParameterCount, _desiredAccess, _rootHandle, _reserved);
    }
    NTSTATUS NtloadKeyEx(POBJECT_ATTRIBUTES _targetKey, POBJECT_ATTRIBUTES _sourceFile, ULONG _flags, HANDLE _trustClassKey, HANDLE _event, ACCESS_MASK _desiredAccess, PHANDLE _rootHandle, PVOID _reserved)
    {
        if (!ntLoadKeyEx) ntLoadKeyEx = win_::resolve_proc_address("NtLoadKeyEx", 11);
        return reinterpret_cast<NTSTATUS(*)(POBJECT_ATTRIBUTES, POBJECT_ATTRIBUTES, ULONG, HANDLE, HANDLE, ACCESS_MASK, PHANDLE, PVOID)>(ntLoadKeyEx)(_targetKey, _sourceFile, _flags, _trustClassKey, _event, _desiredAccess, _rootHandle, _reserved);
    }
    NTSTATUS NtlockFile(HANDLE _fileHandle, HANDLE _event, PIO_APC_ROUTINE _apcRoutine, PVOID _apcContext, PIO_STATUS_BLOCK _ioStatusBlock, PLARGE_INTEGER _byteOffset, PLARGE_INTEGER _length, ULONG _key, BOOLEAN _failImmediately, BOOLEAN _exclusiveLock)
    {
        if (!ntLockFile) ntLockFile = win_::resolve_proc_address("NtLockFile", 10);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE, PIO_APC_ROUTINE, PVOID, PIO_STATUS_BLOCK, PLARGE_INTEGER, PLARGE_INTEGER, ULONG, BOOLEAN, BOOLEAN)>(ntLockFile)(_fileHandle, _event, _apcRoutine, _apcContext, _ioStatusBlock, _byteOffset, _length, _key, _failImmediately, _exclusiveLock);
    }
    NTSTATUS NtlockProductActivationKeys(ULONG* _pPrivateVer, ULONG* _pSafeMode)
    {
        if (!ntLockProductActivationKeys) ntLockProductActivationKeys = win_::resolve_proc_address("NtLockProductActivationKeys", 27);
        return reinterpret_cast<NTSTATUS(*)(ULONG*, ULONG*)>(ntLockProductActivationKeys)(_pPrivateVer, _pSafeMode);
    }
    NTSTATUS NtlockRegistryKey(HANDLE _keyHandle)
    {
        if (!ntLockRegistryKey) ntLockRegistryKey = win_::resolve_proc_address("NtLockRegistryKey", 17);
        return reinterpret_cast<NTSTATUS(*)(HANDLE)>(ntLockRegistryKey)(_keyHandle);
    }
    NTSTATUS NtlockVirtualMemory(HANDLE _processHandle, PVOID* _baseAddress, PSIZE_T _regionSize, ULONG _mapType)
    {
        if (!ntLockVirtualMemory) ntLockVirtualMemory = win_::resolve_proc_address("NtLockVirtualMemory", 19);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PVOID*, PSIZE_T, ULONG)>(ntLockVirtualMemory)(_processHandle, _baseAddress, _regionSize, _mapType);
    }
    NTSTATUS NtmakePermanentObject(HANDLE _handle)
    {
        if (!ntMakePermanentObject) ntMakePermanentObject = win_::resolve_proc_address("NtMakePermanentObject", 21);
        return reinterpret_cast<NTSTATUS(*)(HANDLE)>(ntMakePermanentObject)(_handle);
    }
    NTSTATUS NtmakeTemporaryObject(HANDLE _handle)
    {
        if (!ntMakeTemporaryObject) ntMakeTemporaryObject = win_::resolve_proc_address("NtMakeTemporaryObject", 21);
        return reinterpret_cast<NTSTATUS(*)(HANDLE)>(ntMakeTemporaryObject)(_handle);
    }
    NTSTATUS NtmanageHotPatch(HOT_PATCH_INFORMATION_CLASS _hotPatchInformationClass, PVOID _hotPatchInformation, ULONG _hotPatchInformationLength, PULONG _returnLength)
    {
        if (!ntManageHotPatch) ntManageHotPatch = win_::resolve_proc_address("NtManageHotPatch", 16);
        return reinterpret_cast<NTSTATUS(*)(HOT_PATCH_INFORMATION_CLASS, PVOID, ULONG, PULONG)>(ntManageHotPatch)(_hotPatchInformationClass, _hotPatchInformation, _hotPatchInformationLength, _returnLength);
    }
    NTSTATUS NtmanagePartition(HANDLE _targetHandle, HANDLE _sourceHandle, PARTITION_INFORMATION_CLASS _partitionInformationClass, PVOID _partitionInformation, ULONG _partitionInformationLength)
    {
        if (!ntManagePartition) ntManagePartition = win_::resolve_proc_address("NtManagePartition", 17);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE, PARTITION_INFORMATION_CLASS, PVOID, ULONG)>(ntManagePartition)(_targetHandle, _sourceHandle, _partitionInformationClass, _partitionInformation, _partitionInformationLength);
    }
    NTSTATUS NtmapCMFModule(ULONG _what, ULONG _index, PULONG _cacheIndexOut, PULONG _cacheFlagsOut, PULONG _viewSizeOut, PVOID* _baseAddress)
    {
        if (!ntMapCMFModule) ntMapCMFModule = win_::resolve_proc_address("NtMapCMFModule", 14);
        return reinterpret_cast<NTSTATUS(*)(ULONG, ULONG, PULONG, PULONG, PULONG, PVOID*)>(ntMapCMFModule)(_what, _index, _cacheIndexOut, _cacheFlagsOut, _viewSizeOut, _baseAddress);
    }
    NTSTATUS NtmapUserPhysicalPages(PVOID _virtualAddress, SIZE_T _numberOfPages, PULONG_PTR _userPfnArray)
    {
        if (!ntMapUserPhysicalPages) ntMapUserPhysicalPages = win_::resolve_proc_address("NtMapUserPhysicalPages", 22);
        return reinterpret_cast<NTSTATUS(*)(PVOID, SIZE_T, PULONG_PTR)>(ntMapUserPhysicalPages)(_virtualAddress, _numberOfPages, _userPfnArray);
    }
    NTSTATUS NtmapUserPhysicalPagesScatter(PVOID* _virtualAddresses, SIZE_T _numberOfPages, PULONG_PTR _userPfnArray)
    {
        if (!ntMapUserPhysicalPagesScatter) ntMapUserPhysicalPagesScatter = win_::resolve_proc_address("NtMapUserPhysicalPagesScatter", 29);
        return reinterpret_cast<NTSTATUS(*)(PVOID*, SIZE_T, PULONG_PTR)>(ntMapUserPhysicalPagesScatter)(_virtualAddresses, _numberOfPages, _userPfnArray);
    }
    NTSTATUS NtmapViewOfSection(HANDLE _sectionHandle, HANDLE _processHandle, PVOID* _baseAddress, ULONG_PTR _zeroBits, SIZE_T _commitSize, PLARGE_INTEGER _sectionOffset, PSIZE_T _viewSize, SECTION_INHERIT _inheritDisposition, ULONG _allocationType, ULONG _pageProtection)
    {
        if (!ntMapViewOfSection) ntMapViewOfSection = win_::resolve_proc_address("NtMapViewOfSection", 18);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE, PVOID*, ULONG_PTR, SIZE_T, PLARGE_INTEGER, PSIZE_T, SECTION_INHERIT, ULONG, ULONG)>(ntMapViewOfSection)(_sectionHandle, _processHandle, _baseAddress, _zeroBits, _commitSize, _sectionOffset, _viewSize, _inheritDisposition, _allocationType, _pageProtection);
    }
    NTSTATUS NtmapViewOfSectionEx(HANDLE _sectionHandle, HANDLE _processHandle, PVOID* _baseAddress, PLARGE_INTEGER _sectionOffset, PSIZE_T _viewSize, ULONG _allocationType, ULONG _pageProtection, PMEM_EXTENDED_PARAMETER _extendedParameters, ULONG _extendedParameterCount)
    {
        if (!ntMapViewOfSectionEx) ntMapViewOfSectionEx = win_::resolve_proc_address("NtMapViewOfSectionEx", 20);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE, PVOID*, PLARGE_INTEGER, PSIZE_T, ULONG, ULONG, PMEM_EXTENDED_PARAMETER, ULONG)>(ntMapViewOfSectionEx)(_sectionHandle, _processHandle, _baseAddress, _sectionOffset, _viewSize, _allocationType, _pageProtection, _extendedParameters, _extendedParameterCount);
    }
    NTSTATUS NtmodifyBootEntry(PBOOT_ENTRY _bootEntry)
    {
        if (!ntModifyBootEntry) ntModifyBootEntry = win_::resolve_proc_address("NtModifyBootEntry", 17);
        return reinterpret_cast<NTSTATUS(*)(PBOOT_ENTRY)>(ntModifyBootEntry)(_bootEntry);
    }
    NTSTATUS NtmodifyDriverEntry(PEFI_DRIVER_ENTRY _driverEntry)
    {
        if (!ntModifyDriverEntry) ntModifyDriverEntry = win_::resolve_proc_address("NtModifyDriverEntry", 19);
        return reinterpret_cast<NTSTATUS(*)(PEFI_DRIVER_ENTRY)>(ntModifyDriverEntry)(_driverEntry);
    }
    NTSTATUS NtnotifyChangeDirectoryFile(HANDLE _fileHandle, HANDLE _event, PIO_APC_ROUTINE _apcRoutine, PVOID _apcContext, PIO_STATUS_BLOCK _ioStatusBlock, PVOID _buffer, ULONG _length, ULONG _completionFilter, BOOLEAN _watchTree)
    {
        if (!ntNotifyChangeDirectoryFile) ntNotifyChangeDirectoryFile = win_::resolve_proc_address("NtNotifyChangeDirectoryFile", 27);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE, PIO_APC_ROUTINE, PVOID, PIO_STATUS_BLOCK, PVOID, ULONG, ULONG, BOOLEAN)>(ntNotifyChangeDirectoryFile)(_fileHandle, _event, _apcRoutine, _apcContext, _ioStatusBlock, _buffer, _length, _completionFilter, _watchTree);
    }
    NTSTATUS NtnotifyChangeDirectoryFileEx(HANDLE _fileHandle, HANDLE _event, PIO_APC_ROUTINE _apcRoutine, PVOID _apcContext, PIO_STATUS_BLOCK _ioStatusBlock, PVOID _buffer, ULONG _length, ULONG _completionFilter, BOOLEAN _watchTree, DIRECTORY_NOTIFY_INFORMATION_CLASS _directoryNotifyInformationClass)
    {
        if (!ntNotifyChangeDirectoryFileEx) ntNotifyChangeDirectoryFileEx = win_::resolve_proc_address("NtNotifyChangeDirectoryFileEx", 29);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE, PIO_APC_ROUTINE, PVOID, PIO_STATUS_BLOCK, PVOID, ULONG, ULONG, BOOLEAN, DIRECTORY_NOTIFY_INFORMATION_CLASS)>(ntNotifyChangeDirectoryFileEx)(_fileHandle, _event, _apcRoutine, _apcContext, _ioStatusBlock, _buffer, _length, _completionFilter, _watchTree, _directoryNotifyInformationClass);
    }
    NTSTATUS NtnotifyChangeKey(HANDLE _keyHandle, HANDLE _event, PIO_APC_ROUTINE _apcRoutine, PVOID _apcContext, PIO_STATUS_BLOCK _ioStatusBlock, ULONG _completionFilter, BOOLEAN _watchTree, PVOID _buffer, ULONG _bufferSize, BOOLEAN _asynchronous)
    {
        if (!ntNotifyChangeKey) ntNotifyChangeKey = win_::resolve_proc_address("NtNotifyChangeKey", 17);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE, PIO_APC_ROUTINE, PVOID, PIO_STATUS_BLOCK, ULONG, BOOLEAN, PVOID, ULONG, BOOLEAN)>(ntNotifyChangeKey)(_keyHandle, _event, _apcRoutine, _apcContext, _ioStatusBlock, _completionFilter, _watchTree, _buffer, _bufferSize, _asynchronous);
    }
    NTSTATUS NtnotifyChangeMultipleKeys(HANDLE _masterKeyHandle, ULONG _count, OBJECT_ATTRIBUTES _subordinateObjects[], HANDLE _event, PIO_APC_ROUTINE _apcRoutine, PVOID _apcContext, PIO_STATUS_BLOCK _ioStatusBlock, ULONG _completionFilter, BOOLEAN _watchTree, PVOID _buffer, ULONG _bufferSize, BOOLEAN _asynchronous)
    {
        if (!ntNotifyChangeMultipleKeys) ntNotifyChangeMultipleKeys = win_::resolve_proc_address("NtNotifyChangeMultipleKeys", 26);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONG, OBJECT_ATTRIBUTES[], HANDLE, PIO_APC_ROUTINE, PVOID, PIO_STATUS_BLOCK, ULONG, BOOLEAN, PVOID, ULONG, BOOLEAN)>(ntNotifyChangeMultipleKeys)(_masterKeyHandle, _count, _subordinateObjects, _event, _apcRoutine, _apcContext, _ioStatusBlock, _completionFilter, _watchTree, _buffer, _bufferSize, _asynchronous);
    }
    NTSTATUS NtnotifyChangeSession(HANDLE _sessionHandle, ULONG _changeSequenceNumber, PLARGE_INTEGER _changeTimeStamp, IO_SESSION_EVENT _event, IO_SESSION_STATE _newState, IO_SESSION_STATE _previousState, PVOID _payload, ULONG _payloadSize)
    {
        if (!ntNotifyChangeSession) ntNotifyChangeSession = win_::resolve_proc_address("NtNotifyChangeSession", 21);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONG, PLARGE_INTEGER, IO_SESSION_EVENT, IO_SESSION_STATE, IO_SESSION_STATE, PVOID, ULONG)>(ntNotifyChangeSession)(_sessionHandle, _changeSequenceNumber, _changeTimeStamp, _event, _newState, _previousState, _payload, _payloadSize);
    }
    NTSTATUS NtopenCpuPartition(PHANDLE _cpuPartitionHandle, ACCESS_MASK _desiredAccess, POBJECT_ATTRIBUTES _objectAttributes)
    {
        if (!ntOpenCpuPartition) ntOpenCpuPartition = win_::resolve_proc_address("NtOpenCpuPartition", 18);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES)>(ntOpenCpuPartition)(_cpuPartitionHandle, _desiredAccess, _objectAttributes);
    }
    NTSTATUS NtopenDirectoryObject(PHANDLE _directoryHandle, ACCESS_MASK _desiredAccess, POBJECT_ATTRIBUTES _objectAttributes)
    {
        if (!ntOpenDirectoryObject) ntOpenDirectoryObject = win_::resolve_proc_address("NtOpenDirectoryObject", 21);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES)>(ntOpenDirectoryObject)(_directoryHandle, _desiredAccess, _objectAttributes);
    }
    NTSTATUS NtopenEnlistment(PHANDLE _enlistmentHandle, ACCESS_MASK _desiredAccess, HANDLE _resourceManagerHandle, LPGUID _enlistmentGuid, POBJECT_ATTRIBUTES _objectAttributes)
    {
        if (!ntOpenEnlistment) ntOpenEnlistment = win_::resolve_proc_address("NtOpenEnlistment", 16);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, HANDLE, LPGUID, POBJECT_ATTRIBUTES)>(ntOpenEnlistment)(_enlistmentHandle, _desiredAccess, _resourceManagerHandle, _enlistmentGuid, _objectAttributes);
    }
    NTSTATUS NtopenEvent(PHANDLE _eventHandle, ACCESS_MASK _desiredAccess, POBJECT_ATTRIBUTES _objectAttributes)
    {
        if (!ntOpenEvent) ntOpenEvent = win_::resolve_proc_address("NtOpenEvent", 11);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES)>(ntOpenEvent)(_eventHandle, _desiredAccess, _objectAttributes);
    }
    NTSTATUS NtopenEventPair(PHANDLE _eventPairHandle, ACCESS_MASK _desiredAccess, PCOBJECT_ATTRIBUTES _objectAttributes)
    {
        if (!ntOpenEventPair) ntOpenEventPair = win_::resolve_proc_address("NtOpenEventPair", 15);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, PCOBJECT_ATTRIBUTES)>(ntOpenEventPair)(_eventPairHandle, _desiredAccess, _objectAttributes);
    }
    NTSTATUS NtopenFile(PHANDLE _fileHandle, ACCESS_MASK _desiredAccess, PCOBJECT_ATTRIBUTES _objectAttributes, PIO_STATUS_BLOCK _ioStatusBlock, ULONG _shareAccess, ULONG _openOptions)
    {
        if (!ntOpenFile) ntOpenFile = win_::resolve_proc_address("NtOpenFile", 10);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, PCOBJECT_ATTRIBUTES, PIO_STATUS_BLOCK, ULONG, ULONG)>(ntOpenFile)(_fileHandle, _desiredAccess, _objectAttributes, _ioStatusBlock, _shareAccess, _openOptions);
    }
    NTSTATUS NtopenIoCompletion(PHANDLE _ioCompletionHandle, ACCESS_MASK _desiredAccess, PCOBJECT_ATTRIBUTES _objectAttributes)
    {
        if (!ntOpenIoCompletion) ntOpenIoCompletion = win_::resolve_proc_address("NtOpenIoCompletion", 18);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, PCOBJECT_ATTRIBUTES)>(ntOpenIoCompletion)(_ioCompletionHandle, _desiredAccess, _objectAttributes);
    }
    NTSTATUS NtopenJobObject(PHANDLE _jobHandle, ACCESS_MASK _desiredAccess, PCOBJECT_ATTRIBUTES _objectAttributes)
    {
        if (!ntOpenJobObject) ntOpenJobObject = win_::resolve_proc_address("NtOpenJobObject", 15);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, PCOBJECT_ATTRIBUTES)>(ntOpenJobObject)(_jobHandle, _desiredAccess, _objectAttributes);
    }
    NTSTATUS NtopenKey(PHANDLE _keyHandle, ACCESS_MASK _desiredAccess, POBJECT_ATTRIBUTES _objectAttributes)
    {
        if (!ntOpenKey) ntOpenKey = win_::resolve_proc_address("NtOpenKey", 9);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES)>(ntOpenKey)(_keyHandle, _desiredAccess, _objectAttributes);
    }
    NTSTATUS NtopenKeyEx(PHANDLE _keyHandle, ACCESS_MASK _desiredAccess, POBJECT_ATTRIBUTES _objectAttributes, ULONG _openOptions)
    {
        if (!ntOpenKeyEx) ntOpenKeyEx = win_::resolve_proc_address("NtOpenKeyEx", 11);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES, ULONG)>(ntOpenKeyEx)(_keyHandle, _desiredAccess, _objectAttributes, _openOptions);
    }
    NTSTATUS NtopenKeyTransacted(PHANDLE _keyHandle, ACCESS_MASK _desiredAccess, POBJECT_ATTRIBUTES _objectAttributes, HANDLE _transactionHandle)
    {
        if (!ntOpenKeyTransacted) ntOpenKeyTransacted = win_::resolve_proc_address("NtOpenKeyTransacted", 19);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES, HANDLE)>(ntOpenKeyTransacted)(_keyHandle, _desiredAccess, _objectAttributes, _transactionHandle);
    }
    NTSTATUS NtopenKeyTransactedEx(PHANDLE _keyHandle, ACCESS_MASK _desiredAccess, POBJECT_ATTRIBUTES _objectAttributes, ULONG _openOptions, HANDLE _transactionHandle)
    {
        if (!ntOpenKeyTransactedEx) ntOpenKeyTransactedEx = win_::resolve_proc_address("NtOpenKeyTransactedEx", 21);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES, ULONG, HANDLE)>(ntOpenKeyTransactedEx)(_keyHandle, _desiredAccess, _objectAttributes, _openOptions, _transactionHandle);
    }
    NTSTATUS NtopenKeyedEvent(PHANDLE _keyedEventHandle, ACCESS_MASK _desiredAccess, PCOBJECT_ATTRIBUTES _objectAttributes)
    {
        if (!ntOpenKeyedEvent) ntOpenKeyedEvent = win_::resolve_proc_address("NtOpenKeyedEvent", 16);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, PCOBJECT_ATTRIBUTES)>(ntOpenKeyedEvent)(_keyedEventHandle, _desiredAccess, _objectAttributes);
    }
    NTSTATUS NtopenMutant(PHANDLE _mutantHandle, ACCESS_MASK _desiredAccess, PCOBJECT_ATTRIBUTES _objectAttributes)
    {
        if (!ntOpenMutant) ntOpenMutant = win_::resolve_proc_address("NtOpenMutant", 12);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, PCOBJECT_ATTRIBUTES)>(ntOpenMutant)(_mutantHandle, _desiredAccess, _objectAttributes);
    }
    NTSTATUS NtopenObjectAuditAlarm(PCUNICODE_STRING _subsystemName, PVOID _handleId, PCUNICODE_STRING _objectTypeName, PCUNICODE_STRING _objectName, PSECURITY_DESCRIPTOR _securityDescriptor, HANDLE _clientToken, ACCESS_MASK _desiredAccess, ACCESS_MASK _grantedAccess, PPRIVILEGE_SET _privileges, BOOLEAN _objectCreation, BOOLEAN _accessGranted, PBOOLEAN _generateOnClose)
    {
        if (!ntOpenObjectAuditAlarm) ntOpenObjectAuditAlarm = win_::resolve_proc_address("NtOpenObjectAuditAlarm", 22);
        return reinterpret_cast<NTSTATUS(*)(PCUNICODE_STRING, PVOID, PCUNICODE_STRING, PCUNICODE_STRING, PSECURITY_DESCRIPTOR, HANDLE, ACCESS_MASK, ACCESS_MASK, PPRIVILEGE_SET, BOOLEAN, BOOLEAN, PBOOLEAN)>(ntOpenObjectAuditAlarm)(_subsystemName, _handleId, _objectTypeName, _objectName, _securityDescriptor, _clientToken, _desiredAccess, _grantedAccess, _privileges, _objectCreation, _accessGranted, _generateOnClose);
    }
    NTSTATUS NtopenPartition(PHANDLE _partitionHandle, ACCESS_MASK _desiredAccess, PCOBJECT_ATTRIBUTES _objectAttributes)
    {
        if (!ntOpenPartition) ntOpenPartition = win_::resolve_proc_address("NtOpenPartition", 15);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, PCOBJECT_ATTRIBUTES)>(ntOpenPartition)(_partitionHandle, _desiredAccess, _objectAttributes);
    }
    NTSTATUS NtopenPrivateNamespace(PHANDLE _namespaceHandle, ACCESS_MASK _desiredAccess, POBJECT_ATTRIBUTES _objectAttributes, POBJECT_BOUNDARY_DESCRIPTOR _boundaryDescriptor)
    {
        if (!ntOpenPrivateNamespace) ntOpenPrivateNamespace = win_::resolve_proc_address("NtOpenPrivateNamespace", 22);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES, POBJECT_BOUNDARY_DESCRIPTOR)>(ntOpenPrivateNamespace)(_namespaceHandle, _desiredAccess, _objectAttributes, _boundaryDescriptor);
    }
    NTSTATUS NtopenProcess(PHANDLE _processHandle, ACCESS_MASK _desiredAccess, PCOBJECT_ATTRIBUTES _objectAttributes, PCLIENT_ID _clientId)
    {
        if (!ntOpenProcess) ntOpenProcess = win_::resolve_proc_address("NtOpenProcess", 13);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, PCOBJECT_ATTRIBUTES, PCLIENT_ID)>(ntOpenProcess)(_processHandle, _desiredAccess, _objectAttributes, _clientId);
    }
    NTSTATUS NtopenProcessToken(HANDLE _processHandle, ACCESS_MASK _desiredAccess, PHANDLE _tokenHandle)
    {
        if (!ntOpenProcessToken) ntOpenProcessToken = win_::resolve_proc_address("NtOpenProcessToken", 18);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ACCESS_MASK, PHANDLE)>(ntOpenProcessToken)(_processHandle, _desiredAccess, _tokenHandle);
    }
    NTSTATUS NtopenProcessTokenEx(HANDLE _processHandle, ACCESS_MASK _desiredAccess, ULONG _handleAttributes, PHANDLE _tokenHandle)
    {
        if (!ntOpenProcessTokenEx) ntOpenProcessTokenEx = win_::resolve_proc_address("NtOpenProcessTokenEx", 20);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ACCESS_MASK, ULONG, PHANDLE)>(ntOpenProcessTokenEx)(_processHandle, _desiredAccess, _handleAttributes, _tokenHandle);
    }
    NTSTATUS NtopenRegistryTransaction(HANDLE* _registryTransactionHandle, ACCESS_MASK _desiredAccess, POBJECT_ATTRIBUTES _objAttributes)
    {
        if (!ntOpenRegistryTransaction) ntOpenRegistryTransaction = win_::resolve_proc_address("NtOpenRegistryTransaction", 25);
        return reinterpret_cast<NTSTATUS(*)(HANDLE*, ACCESS_MASK, POBJECT_ATTRIBUTES)>(ntOpenRegistryTransaction)(_registryTransactionHandle, _desiredAccess, _objAttributes);
    }
    NTSTATUS NtopenResourceManager(PHANDLE _resourceManagerHandle, ACCESS_MASK _desiredAccess, HANDLE _tmHandle, LPGUID _resourceManagerGuid, POBJECT_ATTRIBUTES _objectAttributes)
    {
        if (!ntOpenResourceManager) ntOpenResourceManager = win_::resolve_proc_address("NtOpenResourceManager", 21);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, HANDLE, LPGUID, POBJECT_ATTRIBUTES)>(ntOpenResourceManager)(_resourceManagerHandle, _desiredAccess, _tmHandle, _resourceManagerGuid, _objectAttributes);
    }
    NTSTATUS NtopenSection(PHANDLE _sectionHandle, ACCESS_MASK _desiredAccess, PCOBJECT_ATTRIBUTES _objectAttributes)
    {
        if (!ntOpenSection) ntOpenSection = win_::resolve_proc_address("NtOpenSection", 13);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, PCOBJECT_ATTRIBUTES)>(ntOpenSection)(_sectionHandle, _desiredAccess, _objectAttributes);
    }
    NTSTATUS NtopenSemaphore(PHANDLE _semaphoreHandle, ACCESS_MASK _desiredAccess, PCOBJECT_ATTRIBUTES _objectAttributes)
    {
        if (!ntOpenSemaphore) ntOpenSemaphore = win_::resolve_proc_address("NtOpenSemaphore", 15);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, PCOBJECT_ATTRIBUTES)>(ntOpenSemaphore)(_semaphoreHandle, _desiredAccess, _objectAttributes);
    }
    NTSTATUS NtopenSession(PHANDLE _sessionHandle, ACCESS_MASK _desiredAccess, POBJECT_ATTRIBUTES _objectAttributes)
    {
        if (!ntOpenSession) ntOpenSession = win_::resolve_proc_address("NtOpenSession", 13);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES)>(ntOpenSession)(_sessionHandle, _desiredAccess, _objectAttributes);
    }
    NTSTATUS NtopenSymbolicLinkObject(PHANDLE _linkHandle, ACCESS_MASK _desiredAccess, POBJECT_ATTRIBUTES _objectAttributes)
    {
        if (!ntOpenSymbolicLinkObject) ntOpenSymbolicLinkObject = win_::resolve_proc_address("NtOpenSymbolicLinkObject", 24);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES)>(ntOpenSymbolicLinkObject)(_linkHandle, _desiredAccess, _objectAttributes);
    }
    NTSTATUS NtopenThread(PHANDLE _threadHandle, ACCESS_MASK _desiredAccess, PCOBJECT_ATTRIBUTES _objectAttributes, PCLIENT_ID _clientId)
    {
        if (!ntOpenThread) ntOpenThread = win_::resolve_proc_address("NtOpenThread", 12);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, PCOBJECT_ATTRIBUTES, PCLIENT_ID)>(ntOpenThread)(_threadHandle, _desiredAccess, _objectAttributes, _clientId);
    }
    NTSTATUS NtopenThreadToken(HANDLE _threadHandle, ACCESS_MASK _desiredAccess, BOOLEAN _openAsSelf, PHANDLE _tokenHandle)
    {
        if (!ntOpenThreadToken) ntOpenThreadToken = win_::resolve_proc_address("NtOpenThreadToken", 17);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ACCESS_MASK, BOOLEAN, PHANDLE)>(ntOpenThreadToken)(_threadHandle, _desiredAccess, _openAsSelf, _tokenHandle);
    }
    NTSTATUS NtopenThreadTokenEx(HANDLE _threadHandle, ACCESS_MASK _desiredAccess, BOOLEAN _openAsSelf, ULONG _handleAttributes, PHANDLE _tokenHandle)
    {
        if (!ntOpenThreadTokenEx) ntOpenThreadTokenEx = win_::resolve_proc_address("NtOpenThreadTokenEx", 19);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ACCESS_MASK, BOOLEAN, ULONG, PHANDLE)>(ntOpenThreadTokenEx)(_threadHandle, _desiredAccess, _openAsSelf, _handleAttributes, _tokenHandle);
    }
    NTSTATUS NtopenTimer(PHANDLE _timerHandle, ACCESS_MASK _desiredAccess, PCOBJECT_ATTRIBUTES _objectAttributes)
    {
        if (!ntOpenTimer) ntOpenTimer = win_::resolve_proc_address("NtOpenTimer", 11);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, PCOBJECT_ATTRIBUTES)>(ntOpenTimer)(_timerHandle, _desiredAccess, _objectAttributes);
    }
    NTSTATUS NtopenTransaction(PHANDLE _transactionHandle, ACCESS_MASK _desiredAccess, POBJECT_ATTRIBUTES _objectAttributes, LPGUID _uow, HANDLE _tmHandle)
    {
        if (!ntOpenTransaction) ntOpenTransaction = win_::resolve_proc_address("NtOpenTransaction", 17);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES, LPGUID, HANDLE)>(ntOpenTransaction)(_transactionHandle, _desiredAccess, _objectAttributes, _uow, _tmHandle);
    }
    NTSTATUS NtopenTransactionManager(PHANDLE _tmHandle, ACCESS_MASK _desiredAccess, POBJECT_ATTRIBUTES _objectAttributes, PCUNICODE_STRING _logFileName, LPGUID _tmIdentity, ULONG _openOptions)
    {
        if (!ntOpenTransactionManager) ntOpenTransactionManager = win_::resolve_proc_address("NtOpenTransactionManager", 24);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES, PCUNICODE_STRING, LPGUID, ULONG)>(ntOpenTransactionManager)(_tmHandle, _desiredAccess, _objectAttributes, _logFileName, _tmIdentity, _openOptions);
    }
    NTSTATUS NtplugPlayControl(PLUGPLAY_CONTROL_CLASS _pnPControlClass, PVOID _pnPControlData, ULONG _pnPControlDataLength)
    {
        if (!ntPlugPlayControl) ntPlugPlayControl = win_::resolve_proc_address("NtPlugPlayControl", 17);
        return reinterpret_cast<NTSTATUS(*)(PLUGPLAY_CONTROL_CLASS, PVOID, ULONG)>(ntPlugPlayControl)(_pnPControlClass, _pnPControlData, _pnPControlDataLength);
    }
    NTSTATUS NtpowerInformation(ULONG _informationLevel, PVOID _inputBuffer, ULONG _inputBufferLength, PVOID _outputBuffer, ULONG _outputBufferLength)
    {
        if (!ntPowerInformation) ntPowerInformation = win_::resolve_proc_address("NtPowerInformation", 18);
        return reinterpret_cast<NTSTATUS(*)(ULONG, PVOID, ULONG, PVOID, ULONG)>(ntPowerInformation)(_informationLevel, _inputBuffer, _inputBufferLength, _outputBuffer, _outputBufferLength);
    }
    NTSTATUS NtprePrepareComplete(HANDLE _enlistmentHandle, PLARGE_INTEGER _tmVirtualClock)
    {
        if (!ntPrePrepareComplete) ntPrePrepareComplete = win_::resolve_proc_address("NtPrePrepareComplete", 20);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PLARGE_INTEGER)>(ntPrePrepareComplete)(_enlistmentHandle, _tmVirtualClock);
    }
    NTSTATUS NtprePrepareEnlistment(HANDLE _enlistmentHandle, PLARGE_INTEGER _tmVirtualClock)
    {
        if (!ntPrePrepareEnlistment) ntPrePrepareEnlistment = win_::resolve_proc_address("NtPrePrepareEnlistment", 22);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PLARGE_INTEGER)>(ntPrePrepareEnlistment)(_enlistmentHandle, _tmVirtualClock);
    }
    NTSTATUS NtprepareComplete(HANDLE _enlistmentHandle, PLARGE_INTEGER _tmVirtualClock)
    {
        if (!ntPrepareComplete) ntPrepareComplete = win_::resolve_proc_address("NtPrepareComplete", 17);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PLARGE_INTEGER)>(ntPrepareComplete)(_enlistmentHandle, _tmVirtualClock);
    }
    NTSTATUS NtprepareEnlistment(HANDLE _enlistmentHandle, PLARGE_INTEGER _tmVirtualClock)
    {
        if (!ntPrepareEnlistment) ntPrepareEnlistment = win_::resolve_proc_address("NtPrepareEnlistment", 19);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PLARGE_INTEGER)>(ntPrepareEnlistment)(_enlistmentHandle, _tmVirtualClock);
    }
    NTSTATUS NtprivilegeCheck(HANDLE _clientToken, PPRIVILEGE_SET _requiredPrivileges, PBOOLEAN _result)
    {
        if (!ntPrivilegeCheck) ntPrivilegeCheck = win_::resolve_proc_address("NtPrivilegeCheck", 16);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PPRIVILEGE_SET, PBOOLEAN)>(ntPrivilegeCheck)(_clientToken, _requiredPrivileges, _result);
    }
    NTSTATUS NtprivilegeObjectAuditAlarm(PCUNICODE_STRING _subsystemName, PVOID _handleId, HANDLE _clientToken, ACCESS_MASK _desiredAccess, PPRIVILEGE_SET _privileges, BOOLEAN _accessGranted)
    {
        if (!ntPrivilegeObjectAuditAlarm) ntPrivilegeObjectAuditAlarm = win_::resolve_proc_address("NtPrivilegeObjectAuditAlarm", 27);
        return reinterpret_cast<NTSTATUS(*)(PCUNICODE_STRING, PVOID, HANDLE, ACCESS_MASK, PPRIVILEGE_SET, BOOLEAN)>(ntPrivilegeObjectAuditAlarm)(_subsystemName, _handleId, _clientToken, _desiredAccess, _privileges, _accessGranted);
    }
    NTSTATUS NtprivilegedServiceAuditAlarm(PCUNICODE_STRING _subsystemName, PCUNICODE_STRING _serviceName, HANDLE _clientToken, PPRIVILEGE_SET _privileges, BOOLEAN _accessGranted)
    {
        if (!ntPrivilegedServiceAuditAlarm) ntPrivilegedServiceAuditAlarm = win_::resolve_proc_address("NtPrivilegedServiceAuditAlarm", 29);
        return reinterpret_cast<NTSTATUS(*)(PCUNICODE_STRING, PCUNICODE_STRING, HANDLE, PPRIVILEGE_SET, BOOLEAN)>(ntPrivilegedServiceAuditAlarm)(_subsystemName, _serviceName, _clientToken, _privileges, _accessGranted);
    }
    NTSTATUS NtpropagationComplete(HANDLE _resourceManagerHandle, ULONG _requestCookie, ULONG _bufferLength, PVOID _buffer)
    {
        if (!ntPropagationComplete) ntPropagationComplete = win_::resolve_proc_address("NtPropagationComplete", 21);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONG, ULONG, PVOID)>(ntPropagationComplete)(_resourceManagerHandle, _requestCookie, _bufferLength, _buffer);
    }
    NTSTATUS NtpropagationFailed(HANDLE _resourceManagerHandle, ULONG _requestCookie, NTSTATUS _propStatus)
    {
        if (!ntPropagationFailed) ntPropagationFailed = win_::resolve_proc_address("NtPropagationFailed", 19);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONG, NTSTATUS)>(ntPropagationFailed)(_resourceManagerHandle, _requestCookie, _propStatus);
    }
    NTSTATUS NtprotectVirtualMemory(HANDLE _processHandle, PVOID* _baseAddress, PSIZE_T _regionSize, ULONG _newProtection, PULONG _oldProtection)
    {
        if (!ntProtectVirtualMemory) ntProtectVirtualMemory = win_::resolve_proc_address("NtProtectVirtualMemory", 22);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PVOID*, PSIZE_T, ULONG, PULONG)>(ntProtectVirtualMemory)(_processHandle, _baseAddress, _regionSize, _newProtection, _oldProtection);
    }
    NTSTATUS NtpssCaptureVaSpaceBulk(HANDLE _processHandle, PVOID _baseAddress, PNTPSS_MEMORY_BULK_INFORMATION _bulkInformation, SIZE_T _bulkInformationLength, PSIZE_T _returnLength)
    {
        if (!ntPssCaptureVaSpaceBulk) ntPssCaptureVaSpaceBulk = win_::resolve_proc_address("NtPssCaptureVaSpaceBulk", 23);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PVOID, PNTPSS_MEMORY_BULK_INFORMATION, SIZE_T, PSIZE_T)>(ntPssCaptureVaSpaceBulk)(_processHandle, _baseAddress, _bulkInformation, _bulkInformationLength, _returnLength);
    }
    NTSTATUS NtpulseEvent(HANDLE _eventHandle, PLONG _previousState)
    {
        if (!ntPulseEvent) ntPulseEvent = win_::resolve_proc_address("NtPulseEvent", 12);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PLONG)>(ntPulseEvent)(_eventHandle, _previousState);
    }
    NTSTATUS NtqueryAttributesFile(PCOBJECT_ATTRIBUTES _objectAttributes, PFILE_BASIC_INFORMATION _fileInformation)
    {
        if (!ntQueryAttributesFile) ntQueryAttributesFile = win_::resolve_proc_address("NtQueryAttributesFile", 21);
        return reinterpret_cast<NTSTATUS(*)(PCOBJECT_ATTRIBUTES, PFILE_BASIC_INFORMATION)>(ntQueryAttributesFile)(_objectAttributes, _fileInformation);
    }
    NTSTATUS NtqueryAuxiliaryCounterFrequency(PULONG64 _auxiliaryCounterFrequency)
    {
        if (!ntQueryAuxiliaryCounterFrequency) ntQueryAuxiliaryCounterFrequency = win_::resolve_proc_address("NtQueryAuxiliaryCounterFrequency", 32);
        return reinterpret_cast<NTSTATUS(*)(PULONG64)>(ntQueryAuxiliaryCounterFrequency)(_auxiliaryCounterFrequency);
    }
    NTSTATUS NtqueryBootEntryOrder(PULONG _ids, PULONG _count)
    {
        if (!ntQueryBootEntryOrder) ntQueryBootEntryOrder = win_::resolve_proc_address("NtQueryBootEntryOrder", 21);
        return reinterpret_cast<NTSTATUS(*)(PULONG, PULONG)>(ntQueryBootEntryOrder)(_ids, _count);
    }
    NTSTATUS NtqueryBootOptions(PBOOT_OPTIONS _bootOptions, PULONG _bootOptionsLength)
    {
        if (!ntQueryBootOptions) ntQueryBootOptions = win_::resolve_proc_address("NtQueryBootOptions", 18);
        return reinterpret_cast<NTSTATUS(*)(PBOOT_OPTIONS, PULONG)>(ntQueryBootOptions)(_bootOptions, _bootOptionsLength);
    }
    NTSTATUS NtqueryDebugFilterState(ULONG _componentId, ULONG _level)
    {
        if (!ntQueryDebugFilterState) ntQueryDebugFilterState = win_::resolve_proc_address("NtQueryDebugFilterState", 23);
        return reinterpret_cast<NTSTATUS(*)(ULONG, ULONG)>(ntQueryDebugFilterState)(_componentId, _level);
    }
    NTSTATUS NtqueryDefaultLocale(BOOLEAN _userProfile, PLCID _defaultLocaleId)
    {
        if (!ntQueryDefaultLocale) ntQueryDefaultLocale = win_::resolve_proc_address("NtQueryDefaultLocale", 20);
        return reinterpret_cast<NTSTATUS(*)(BOOLEAN, PLCID)>(ntQueryDefaultLocale)(_userProfile, _defaultLocaleId);
    }
    NTSTATUS NtqueryDefaultUILanguage(LANGID* _defaultUILanguageId)
    {
        if (!ntQueryDefaultUILanguage) ntQueryDefaultUILanguage = win_::resolve_proc_address("NtQueryDefaultUILanguage", 24);
        return reinterpret_cast<NTSTATUS(*)(LANGID*)>(ntQueryDefaultUILanguage)(_defaultUILanguageId);
    }
    NTSTATUS NtqueryDirectoryFile(HANDLE _fileHandle, HANDLE _event, PIO_APC_ROUTINE _apcRoutine, PVOID _apcContext, PIO_STATUS_BLOCK _ioStatusBlock, PVOID _fileInformation, ULONG _length, FILE_INFORMATION_CLASS _fileInformationClass, BOOLEAN _returnSingleEntry, PCUNICODE_STRING _fileName, BOOLEAN _restartScan)
    {
        if (!ntQueryDirectoryFile) ntQueryDirectoryFile = win_::resolve_proc_address("NtQueryDirectoryFile", 20);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE, PIO_APC_ROUTINE, PVOID, PIO_STATUS_BLOCK, PVOID, ULONG, FILE_INFORMATION_CLASS, BOOLEAN, PCUNICODE_STRING, BOOLEAN)>(ntQueryDirectoryFile)(_fileHandle, _event, _apcRoutine, _apcContext, _ioStatusBlock, _fileInformation, _length, _fileInformationClass, _returnSingleEntry, _fileName, _restartScan);
    }
    NTSTATUS NtqueryDirectoryFileEx(HANDLE _fileHandle, HANDLE _event, PIO_APC_ROUTINE _apcRoutine, PVOID _apcContext, PIO_STATUS_BLOCK _ioStatusBlock, PVOID _fileInformation, ULONG _length, FILE_INFORMATION_CLASS _fileInformationClass, ULONG _queryFlags, PCUNICODE_STRING _fileName)
    {
        if (!ntQueryDirectoryFileEx) ntQueryDirectoryFileEx = win_::resolve_proc_address("NtQueryDirectoryFileEx", 22);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE, PIO_APC_ROUTINE, PVOID, PIO_STATUS_BLOCK, PVOID, ULONG, FILE_INFORMATION_CLASS, ULONG, PCUNICODE_STRING)>(ntQueryDirectoryFileEx)(_fileHandle, _event, _apcRoutine, _apcContext, _ioStatusBlock, _fileInformation, _length, _fileInformationClass, _queryFlags, _fileName);
    }
    NTSTATUS NtqueryDirectoryObject(HANDLE _directoryHandle, PVOID _buffer, ULONG _length, BOOLEAN _returnSingleEntry, BOOLEAN _restartScan, PULONG _context, PULONG _returnLength)
    {
        if (!ntQueryDirectoryObject) ntQueryDirectoryObject = win_::resolve_proc_address("NtQueryDirectoryObject", 22);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PVOID, ULONG, BOOLEAN, BOOLEAN, PULONG, PULONG)>(ntQueryDirectoryObject)(_directoryHandle, _buffer, _length, _returnSingleEntry, _restartScan, _context, _returnLength);
    }
    NTSTATUS NtqueryDriverEntryOrder(PULONG _ids, PULONG _count)
    {
        if (!ntQueryDriverEntryOrder) ntQueryDriverEntryOrder = win_::resolve_proc_address("NtQueryDriverEntryOrder", 23);
        return reinterpret_cast<NTSTATUS(*)(PULONG, PULONG)>(ntQueryDriverEntryOrder)(_ids, _count);
    }
    NTSTATUS NtqueryEaFile(HANDLE _fileHandle, PIO_STATUS_BLOCK _ioStatusBlock, PVOID _buffer, ULONG _length, BOOLEAN _returnSingleEntry, PVOID _eaList, ULONG _eaListLength, PULONG _eaIndex, BOOLEAN _restartScan)
    {
        if (!ntQueryEaFile) ntQueryEaFile = win_::resolve_proc_address("NtQueryEaFile", 13);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PIO_STATUS_BLOCK, PVOID, ULONG, BOOLEAN, PVOID, ULONG, PULONG, BOOLEAN)>(ntQueryEaFile)(_fileHandle, _ioStatusBlock, _buffer, _length, _returnSingleEntry, _eaList, _eaListLength, _eaIndex, _restartScan);
    }
    NTSTATUS NtqueryEvent(HANDLE _eventHandle, EVENT_INFORMATION_CLASS _eventInformationClass, PVOID _eventInformation, ULONG _eventInformationLength, PULONG _returnLength)
    {
        if (!ntQueryEvent) ntQueryEvent = win_::resolve_proc_address("NtQueryEvent", 12);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, EVENT_INFORMATION_CLASS, PVOID, ULONG, PULONG)>(ntQueryEvent)(_eventHandle, _eventInformationClass, _eventInformation, _eventInformationLength, _returnLength);
    }
    NTSTATUS NtqueryFullAttributesFile(PCOBJECT_ATTRIBUTES _objectAttributes, PFILE_NETWORK_OPEN_INFORMATION _fileInformation)
    {
        if (!ntQueryFullAttributesFile) ntQueryFullAttributesFile = win_::resolve_proc_address("NtQueryFullAttributesFile", 25);
        return reinterpret_cast<NTSTATUS(*)(PCOBJECT_ATTRIBUTES, PFILE_NETWORK_OPEN_INFORMATION)>(ntQueryFullAttributesFile)(_objectAttributes, _fileInformation);
    }
    NTSTATUS NtqueryInformationAtom(RTL_ATOM _atom, ATOM_INFORMATION_CLASS _atomInformationClass, PVOID _atomInformation, ULONG _atomInformationLength, PULONG _returnLength)
    {
        if (!ntQueryInformationAtom) ntQueryInformationAtom = win_::resolve_proc_address("NtQueryInformationAtom", 22);
        return reinterpret_cast<NTSTATUS(*)(RTL_ATOM, ATOM_INFORMATION_CLASS, PVOID, ULONG, PULONG)>(ntQueryInformationAtom)(_atom, _atomInformationClass, _atomInformation, _atomInformationLength, _returnLength);
    }
    NTSTATUS NtqueryInformationByName(PCOBJECT_ATTRIBUTES _objectAttributes, PIO_STATUS_BLOCK _ioStatusBlock, PVOID _fileInformation, ULONG _length, FILE_INFORMATION_CLASS _fileInformationClass)
    {
        if (!ntQueryInformationByName) ntQueryInformationByName = win_::resolve_proc_address("NtQueryInformationByName", 24);
        return reinterpret_cast<NTSTATUS(*)(PCOBJECT_ATTRIBUTES, PIO_STATUS_BLOCK, PVOID, ULONG, FILE_INFORMATION_CLASS)>(ntQueryInformationByName)(_objectAttributes, _ioStatusBlock, _fileInformation, _length, _fileInformationClass);
    }
    NTSTATUS NtqueryInformationCpuPartition(HANDLE _cpuPartitionHandle, ULONG _cpuPartitionInformationClass, PVOID _cpuPartitionInformation, ULONG _cpuPartitionInformationLength, PULONG _returnLength)
    {
        if (!ntQueryInformationCpuPartition) ntQueryInformationCpuPartition = win_::resolve_proc_address("NtQueryInformationCpuPartition", 30);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONG, PVOID, ULONG, PULONG)>(ntQueryInformationCpuPartition)(_cpuPartitionHandle, _cpuPartitionInformationClass, _cpuPartitionInformation, _cpuPartitionInformationLength, _returnLength);
    }
    NTSTATUS NtqueryInformationEnlistment(HANDLE _enlistmentHandle, ENLISTMENT_INFORMATION_CLASS _enlistmentInformationClass, PVOID _enlistmentInformation, ULONG _enlistmentInformationLength, PULONG _returnLength)
    {
        if (!ntQueryInformationEnlistment) ntQueryInformationEnlistment = win_::resolve_proc_address("NtQueryInformationEnlistment", 28);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ENLISTMENT_INFORMATION_CLASS, PVOID, ULONG, PULONG)>(ntQueryInformationEnlistment)(_enlistmentHandle, _enlistmentInformationClass, _enlistmentInformation, _enlistmentInformationLength, _returnLength);
    }
    NTSTATUS NtqueryInformationFile(HANDLE _fileHandle, PIO_STATUS_BLOCK _ioStatusBlock, PVOID _fileInformation, ULONG _length, FILE_INFORMATION_CLASS _fileInformationClass)
    {
        if (!ntQueryInformationFile) ntQueryInformationFile = win_::resolve_proc_address("NtQueryInformationFile", 22);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PIO_STATUS_BLOCK, PVOID, ULONG, FILE_INFORMATION_CLASS)>(ntQueryInformationFile)(_fileHandle, _ioStatusBlock, _fileInformation, _length, _fileInformationClass);
    }
    NTSTATUS NtqueryInformationJobObject(HANDLE _jobHandle, ULONG _jobObjectInformationClass, PVOID _jobObjectInformation, ULONG _jobObjectInformationLength, PULONG _returnLength)
    {
        if (!ntQueryInformationJobObject) ntQueryInformationJobObject = win_::resolve_proc_address("NtQueryInformationJobObject", 27);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONG, PVOID, ULONG, PULONG)>(ntQueryInformationJobObject)(_jobHandle, _jobObjectInformationClass, _jobObjectInformation, _jobObjectInformationLength, _returnLength);
    }
    NTSTATUS NtqueryInformationPort(HANDLE _portHandle, PORT_INFORMATION_CLASS _portInformationClass, PVOID _portInformation, ULONG _length, PULONG _returnLength)
    {
        if (!ntQueryInformationPort) ntQueryInformationPort = win_::resolve_proc_address("NtQueryInformationPort", 22);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PORT_INFORMATION_CLASS, PVOID, ULONG, PULONG)>(ntQueryInformationPort)(_portHandle, _portInformationClass, _portInformation, _length, _returnLength);
    }
    NTSTATUS NtqueryInformationProcess(HANDLE _processHandle, PROCESSINFOCLASS _processInformationClass, PVOID _processInformation, ULONG _processInformationLength, PULONG _returnLength)
    {
        if (!ntQueryInformationProcess) ntQueryInformationProcess = win_::resolve_proc_address("NtQueryInformationProcess", 25);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PROCESSINFOCLASS, PVOID, ULONG, PULONG)>(ntQueryInformationProcess)(_processHandle, _processInformationClass, _processInformation, _processInformationLength, _returnLength);
    }
    NTSTATUS NtqueryInformationResourceManager(HANDLE _resourceManagerHandle, RESOURCEMANAGER_INFORMATION_CLASS _resourceManagerInformationClass, PVOID _resourceManagerInformation, ULONG _resourceManagerInformationLength, PULONG _returnLength)
    {
        if (!ntQueryInformationResourceManager) ntQueryInformationResourceManager = win_::resolve_proc_address("NtQueryInformationResourceManager", 33);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, RESOURCEMANAGER_INFORMATION_CLASS, PVOID, ULONG, PULONG)>(ntQueryInformationResourceManager)(_resourceManagerHandle, _resourceManagerInformationClass, _resourceManagerInformation, _resourceManagerInformationLength, _returnLength);
    }
    NTSTATUS NtqueryInformationThread(HANDLE _threadHandle, THREADINFOCLASS _threadInformationClass, PVOID _threadInformation, ULONG _threadInformationLength, PULONG _returnLength)
    {
        if (!ntQueryInformationThread) ntQueryInformationThread = win_::resolve_proc_address("NtQueryInformationThread", 24);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, THREADINFOCLASS, PVOID, ULONG, PULONG)>(ntQueryInformationThread)(_threadHandle, _threadInformationClass, _threadInformation, _threadInformationLength, _returnLength);
    }
    NTSTATUS NtqueryInformationToken(HANDLE _tokenHandle, TOKEN_INFORMATION_CLASS _tokenInformationClass, PVOID _tokenInformation, ULONG _tokenInformationLength, PULONG _returnLength)
    {
        if (!ntQueryInformationToken) ntQueryInformationToken = win_::resolve_proc_address("NtQueryInformationToken", 23);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, TOKEN_INFORMATION_CLASS, PVOID, ULONG, PULONG)>(ntQueryInformationToken)(_tokenHandle, _tokenInformationClass, _tokenInformation, _tokenInformationLength, _returnLength);
    }
    NTSTATUS NtqueryInformationTransaction(HANDLE _transactionHandle, TRANSACTION_INFORMATION_CLASS _transactionInformationClass, PVOID _transactionInformation, ULONG _transactionInformationLength, PULONG _returnLength)
    {
        if (!ntQueryInformationTransaction) ntQueryInformationTransaction = win_::resolve_proc_address("NtQueryInformationTransaction", 29);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, TRANSACTION_INFORMATION_CLASS, PVOID, ULONG, PULONG)>(ntQueryInformationTransaction)(_transactionHandle, _transactionInformationClass, _transactionInformation, _transactionInformationLength, _returnLength);
    }
    NTSTATUS NtqueryInformationTransactionManager(HANDLE _transactionManagerHandle, TRANSACTIONMANAGER_INFORMATION_CLASS _transactionManagerInformationClass, PVOID _transactionManagerInformation, ULONG _transactionManagerInformationLength, PULONG _returnLength)
    {
        if (!ntQueryInformationTransactionManager) ntQueryInformationTransactionManager = win_::resolve_proc_address("NtQueryInformationTransactionManager", 36);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, TRANSACTIONMANAGER_INFORMATION_CLASS, PVOID, ULONG, PULONG)>(ntQueryInformationTransactionManager)(_transactionManagerHandle, _transactionManagerInformationClass, _transactionManagerInformation, _transactionManagerInformationLength, _returnLength);
    }
    NTSTATUS NtqueryInformationWorkerFactory(HANDLE _workerFactoryHandle, WORKERFACTORYINFOCLASS _workerFactoryInformationClass, PVOID _workerFactoryInformation, ULONG _workerFactoryInformationLength, PULONG _returnLength)
    {
        if (!ntQueryInformationWorkerFactory) ntQueryInformationWorkerFactory = win_::resolve_proc_address("NtQueryInformationWorkerFactory", 31);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, WORKERFACTORYINFOCLASS, PVOID, ULONG, PULONG)>(ntQueryInformationWorkerFactory)(_workerFactoryHandle, _workerFactoryInformationClass, _workerFactoryInformation, _workerFactoryInformationLength, _returnLength);
    }
    NTSTATUS NtqueryInstallUILanguage(LANGID* _installUILanguageId)
    {
        if (!ntQueryInstallUILanguage) ntQueryInstallUILanguage = win_::resolve_proc_address("NtQueryInstallUILanguage", 24);
        return reinterpret_cast<NTSTATUS(*)(LANGID*)>(ntQueryInstallUILanguage)(_installUILanguageId);
    }
    NTSTATUS NtqueryIntervalProfile(KPROFILE_SOURCE _profileSource, PULONG _interval)
    {
        if (!ntQueryIntervalProfile) ntQueryIntervalProfile = win_::resolve_proc_address("NtQueryIntervalProfile", 22);
        return reinterpret_cast<NTSTATUS(*)(KPROFILE_SOURCE, PULONG)>(ntQueryIntervalProfile)(_profileSource, _interval);
    }
    NTSTATUS NtqueryIoCompletion(HANDLE _ioCompletionHandle, IO_COMPLETION_INFORMATION_CLASS _ioCompletionInformationClass, PVOID _ioCompletionInformation, ULONG _ioCompletionInformationLength, PULONG _returnLength)
    {
        if (!ntQueryIoCompletion) ntQueryIoCompletion = win_::resolve_proc_address("NtQueryIoCompletion", 19);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, IO_COMPLETION_INFORMATION_CLASS, PVOID, ULONG, PULONG)>(ntQueryIoCompletion)(_ioCompletionHandle, _ioCompletionInformationClass, _ioCompletionInformation, _ioCompletionInformationLength, _returnLength);
    }
    NTSTATUS NtqueryIoRingCapabilities(SIZE_T _ioRingCapabilitiesLength, PVOID _ioRingCapabilities)
    {
        if (!ntQueryIoRingCapabilities) ntQueryIoRingCapabilities = win_::resolve_proc_address("NtQueryIoRingCapabilities", 25);
        return reinterpret_cast<NTSTATUS(*)(SIZE_T, PVOID)>(ntQueryIoRingCapabilities)(_ioRingCapabilitiesLength, _ioRingCapabilities);
    }
    NTSTATUS NtqueryKey(HANDLE _keyHandle, KEY_INFORMATION_CLASS _keyInformationClass, PVOID _keyInformation, ULONG _length, PULONG _resultLength)
    {
        if (!ntQueryKey) ntQueryKey = win_::resolve_proc_address("NtQueryKey", 10);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, KEY_INFORMATION_CLASS, PVOID, ULONG, PULONG)>(ntQueryKey)(_keyHandle, _keyInformationClass, _keyInformation, _length, _resultLength);
    }
    NTSTATUS NtqueryLicenseValue(PCUNICODE_STRING _valueName, PULONG _type, PVOID _data, ULONG _dataSize, PULONG _resultDataSize)
    {
        if (!ntQueryLicenseValue) ntQueryLicenseValue = win_::resolve_proc_address("NtQueryLicenseValue", 19);
        return reinterpret_cast<NTSTATUS(*)(PCUNICODE_STRING, PULONG, PVOID, ULONG, PULONG)>(ntQueryLicenseValue)(_valueName, _type, _data, _dataSize, _resultDataSize);
    }
    NTSTATUS NtqueryMultipleValueKey(HANDLE _keyHandle, PKEY_VALUE_ENTRY _valueEntries, ULONG _entryCount, PVOID _valueBuffer, PULONG _bufferLength, PULONG _requiredBufferLength)
    {
        if (!ntQueryMultipleValueKey) ntQueryMultipleValueKey = win_::resolve_proc_address("NtQueryMultipleValueKey", 23);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PKEY_VALUE_ENTRY, ULONG, PVOID, PULONG, PULONG)>(ntQueryMultipleValueKey)(_keyHandle, _valueEntries, _entryCount, _valueBuffer, _bufferLength, _requiredBufferLength);
    }
    NTSTATUS NtqueryMutant(HANDLE _mutantHandle, MUTANT_INFORMATION_CLASS _mutantInformationClass, PVOID _mutantInformation, ULONG _mutantInformationLength, PULONG _returnLength)
    {
        if (!ntQueryMutant) ntQueryMutant = win_::resolve_proc_address("NtQueryMutant", 13);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, MUTANT_INFORMATION_CLASS, PVOID, ULONG, PULONG)>(ntQueryMutant)(_mutantHandle, _mutantInformationClass, _mutantInformation, _mutantInformationLength, _returnLength);
    }
    NTSTATUS NtqueryObject(HANDLE _handle, OBJECT_INFORMATION_CLASS _objectInformationClass, PVOID _objectInformation, ULONG _objectInformationLength, PULONG _returnLength)
    {
        if (!ntQueryObject) ntQueryObject = win_::resolve_proc_address("NtQueryObject", 13);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, OBJECT_INFORMATION_CLASS, PVOID, ULONG, PULONG)>(ntQueryObject)(_handle, _objectInformationClass, _objectInformation, _objectInformationLength, _returnLength);
    }
    NTSTATUS NtqueryOpenSubKeys(POBJECT_ATTRIBUTES _targetKey, PULONG _handleCount)
    {
        if (!ntQueryOpenSubKeys) ntQueryOpenSubKeys = win_::resolve_proc_address("NtQueryOpenSubKeys", 18);
        return reinterpret_cast<NTSTATUS(*)(POBJECT_ATTRIBUTES, PULONG)>(ntQueryOpenSubKeys)(_targetKey, _handleCount);
    }
    NTSTATUS NtqueryOpenSubKeysEx(POBJECT_ATTRIBUTES _targetKey, ULONG _bufferLength, PVOID _buffer, PULONG _requiredSize)
    {
        if (!ntQueryOpenSubKeysEx) ntQueryOpenSubKeysEx = win_::resolve_proc_address("NtQueryOpenSubKeysEx", 20);
        return reinterpret_cast<NTSTATUS(*)(POBJECT_ATTRIBUTES, ULONG, PVOID, PULONG)>(ntQueryOpenSubKeysEx)(_targetKey, _bufferLength, _buffer, _requiredSize);
    }
    NTSTATUS NtqueryPerformanceCounter(PLARGE_INTEGER _performanceCounter, PLARGE_INTEGER _performanceFrequency)
    {
        if (!ntQueryPerformanceCounter) ntQueryPerformanceCounter = win_::resolve_proc_address("NtQueryPerformanceCounter", 25);
        return reinterpret_cast<NTSTATUS(*)(PLARGE_INTEGER, PLARGE_INTEGER)>(ntQueryPerformanceCounter)(_performanceCounter, _performanceFrequency);
    }
    LOGICAL NtqueryPortInformationProcess()
    {
        if (!ntQueryPortInformationProcess) ntQueryPortInformationProcess = win_::resolve_proc_address("NtQueryPortInformationProcess", 29);
        return reinterpret_cast<LOGICAL(*)()>(ntQueryPortInformationProcess)();
    }
    NTSTATUS NtqueryQuotaInformationFile(HANDLE _fileHandle, PIO_STATUS_BLOCK _ioStatusBlock, PVOID _buffer, ULONG _length, BOOLEAN _returnSingleEntry, PVOID _sidList, ULONG _sidListLength, PSID _startSid, BOOLEAN _restartScan)
    {
        if (!ntQueryQuotaInformationFile) ntQueryQuotaInformationFile = win_::resolve_proc_address("NtQueryQuotaInformationFile", 27);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PIO_STATUS_BLOCK, PVOID, ULONG, BOOLEAN, PVOID, ULONG, PSID, BOOLEAN)>(ntQueryQuotaInformationFile)(_fileHandle, _ioStatusBlock, _buffer, _length, _returnSingleEntry, _sidList, _sidListLength, _startSid, _restartScan);
    }
    NTSTATUS NtquerySection(HANDLE _sectionHandle, SECTION_INFORMATION_CLASS _sectionInformationClass, PVOID _sectionInformation, SIZE_T _sectionInformationLength, PSIZE_T _returnLength)
    {
        if (!ntQuerySection) ntQuerySection = win_::resolve_proc_address("NtQuerySection", 14);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, SECTION_INFORMATION_CLASS, PVOID, SIZE_T, PSIZE_T)>(ntQuerySection)(_sectionHandle, _sectionInformationClass, _sectionInformation, _sectionInformationLength, _returnLength);
    }
    NTSTATUS NtquerySecurityAttributesToken(HANDLE _tokenHandle, PCUNICODE_STRING _attributes, ULONG _numberOfAttributes, PVOID _buffer, ULONG _length, PULONG _returnLength)
    {
        if (!ntQuerySecurityAttributesToken) ntQuerySecurityAttributesToken = win_::resolve_proc_address("NtQuerySecurityAttributesToken", 30);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PCUNICODE_STRING, ULONG, PVOID, ULONG, PULONG)>(ntQuerySecurityAttributesToken)(_tokenHandle, _attributes, _numberOfAttributes, _buffer, _length, _returnLength);
    }
    NTSTATUS NtquerySecurityObject(HANDLE _handle, SECURITY_INFORMATION _securityInformation, PSECURITY_DESCRIPTOR _securityDescriptor, ULONG _length, PULONG _lengthNeeded)
    {
        if (!ntQuerySecurityObject) ntQuerySecurityObject = win_::resolve_proc_address("NtQuerySecurityObject", 21);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, SECURITY_INFORMATION, PSECURITY_DESCRIPTOR, ULONG, PULONG)>(ntQuerySecurityObject)(_handle, _securityInformation, _securityDescriptor, _length, _lengthNeeded);
    }
    NTSTATUS NtquerySecurityPolicy(PCUNICODE_STRING _policy, PCUNICODE_STRING _keyName, PCUNICODE_STRING _valueName, SECURE_SETTING_VALUE_TYPE _valueType, PVOID _value, PULONG _valueSize)
    {
        if (!ntQuerySecurityPolicy) ntQuerySecurityPolicy = win_::resolve_proc_address("NtQuerySecurityPolicy", 21);
        return reinterpret_cast<NTSTATUS(*)(PCUNICODE_STRING, PCUNICODE_STRING, PCUNICODE_STRING, SECURE_SETTING_VALUE_TYPE, PVOID, PULONG)>(ntQuerySecurityPolicy)(_policy, _keyName, _valueName, _valueType, _value, _valueSize);
    }
    NTSTATUS NtquerySemaphore(HANDLE _semaphoreHandle, SEMAPHORE_INFORMATION_CLASS _semaphoreInformationClass, PVOID _semaphoreInformation, ULONG _semaphoreInformationLength, PULONG _returnLength)
    {
        if (!ntQuerySemaphore) ntQuerySemaphore = win_::resolve_proc_address("NtQuerySemaphore", 16);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, SEMAPHORE_INFORMATION_CLASS, PVOID, ULONG, PULONG)>(ntQuerySemaphore)(_semaphoreHandle, _semaphoreInformationClass, _semaphoreInformation, _semaphoreInformationLength, _returnLength);
    }
    NTSTATUS NtquerySymbolicLinkObject(HANDLE _linkHandle, PUNICODE_STRING _linkTarget, PULONG _returnedLength)
    {
        if (!ntQuerySymbolicLinkObject) ntQuerySymbolicLinkObject = win_::resolve_proc_address("NtQuerySymbolicLinkObject", 25);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PUNICODE_STRING, PULONG)>(ntQuerySymbolicLinkObject)(_linkHandle, _linkTarget, _returnedLength);
    }
    NTSTATUS NtquerySystemEnvironmentValue(PCUNICODE_STRING _variableName, PWSTR _variableValue, USHORT _valueLength, PUSHORT _returnLength)
    {
        if (!ntQuerySystemEnvironmentValue) ntQuerySystemEnvironmentValue = win_::resolve_proc_address("NtQuerySystemEnvironmentValue", 29);
        return reinterpret_cast<NTSTATUS(*)(PCUNICODE_STRING, PWSTR, USHORT, PUSHORT)>(ntQuerySystemEnvironmentValue)(_variableName, _variableValue, _valueLength, _returnLength);
    }
    NTSTATUS NtquerySystemEnvironmentValueEx(PCUNICODE_STRING _variableName, PCGUID _vendorGuid, PVOID _buffer, PULONG _bufferLength, PULONG _attributes)
    {
        if (!ntQuerySystemEnvironmentValueEx) ntQuerySystemEnvironmentValueEx = win_::resolve_proc_address("NtQuerySystemEnvironmentValueEx", 31);
        return reinterpret_cast<NTSTATUS(*)(PCUNICODE_STRING, PCGUID, PVOID, PULONG, PULONG)>(ntQuerySystemEnvironmentValueEx)(_variableName, _vendorGuid, _buffer, _bufferLength, _attributes);
    }
    NTSTATUS NtquerySystemInformation(SYSTEM_INFORMATION_CLASS _systemInformationClass, PVOID _systemInformation, ULONG _systemInformationLength, PULONG _returnLength)
    {
        if (!ntQuerySystemInformation) ntQuerySystemInformation = win_::resolve_proc_address("NtQuerySystemInformation", 24);
        return reinterpret_cast<NTSTATUS(*)(SYSTEM_INFORMATION_CLASS, PVOID, ULONG, PULONG)>(ntQuerySystemInformation)(_systemInformationClass, _systemInformation, _systemInformationLength, _returnLength);
    }
    NTSTATUS NtquerySystemInformationEx(SYSTEM_INFORMATION_CLASS _systemInformationClass, PVOID _inputBuffer, ULONG _inputBufferLength, PVOID _systemInformation, ULONG _systemInformationLength, PULONG _returnLength)
    {
        if (!ntQuerySystemInformationEx) ntQuerySystemInformationEx = win_::resolve_proc_address("NtQuerySystemInformationEx", 26);
        return reinterpret_cast<NTSTATUS(*)(SYSTEM_INFORMATION_CLASS, PVOID, ULONG, PVOID, ULONG, PULONG)>(ntQuerySystemInformationEx)(_systemInformationClass, _inputBuffer, _inputBufferLength, _systemInformation, _systemInformationLength, _returnLength);
    }
    NTSTATUS NtquerySystemTime(PLARGE_INTEGER _systemTime)
    {
        if (!ntQuerySystemTime) ntQuerySystemTime = win_::resolve_proc_address("NtQuerySystemTime", 17);
        return reinterpret_cast<NTSTATUS(*)(PLARGE_INTEGER)>(ntQuerySystemTime)(_systemTime);
    }
    NTSTATUS NtqueryTimer(HANDLE _timerHandle, TIMER_INFORMATION_CLASS _timerInformationClass, PVOID _timerInformation, ULONG _timerInformationLength, PULONG _returnLength)
    {
        if (!ntQueryTimer) ntQueryTimer = win_::resolve_proc_address("NtQueryTimer", 12);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, TIMER_INFORMATION_CLASS, PVOID, ULONG, PULONG)>(ntQueryTimer)(_timerHandle, _timerInformationClass, _timerInformation, _timerInformationLength, _returnLength);
    }
    NTSTATUS NtqueryTimerResolution(PULONG _maximumTime, PULONG _minimumTime, PULONG _currentTime)
    {
        if (!ntQueryTimerResolution) ntQueryTimerResolution = win_::resolve_proc_address("NtQueryTimerResolution", 22);
        return reinterpret_cast<NTSTATUS(*)(PULONG, PULONG, PULONG)>(ntQueryTimerResolution)(_maximumTime, _minimumTime, _currentTime);
    }
    NTSTATUS NtqueryValueKey(HANDLE _keyHandle, PCUNICODE_STRING _valueName, KEY_VALUE_INFORMATION_CLASS _keyValueInformationClass, PVOID _keyValueInformation, ULONG _length, PULONG _resultLength)
    {
        if (!ntQueryValueKey) ntQueryValueKey = win_::resolve_proc_address("NtQueryValueKey", 15);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PCUNICODE_STRING, KEY_VALUE_INFORMATION_CLASS, PVOID, ULONG, PULONG)>(ntQueryValueKey)(_keyHandle, _valueName, _keyValueInformationClass, _keyValueInformation, _length, _resultLength);
    }
    NTSTATUS NtqueryVirtualMemory(HANDLE _processHandle, PVOID _baseAddress, MEMORY_INFORMATION_CLASS _memoryInformationClass, PVOID _memoryInformation, SIZE_T _memoryInformationLength, PSIZE_T _returnLength)
    {
        if (!ntQueryVirtualMemory) ntQueryVirtualMemory = win_::resolve_proc_address("NtQueryVirtualMemory", 20);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PVOID, MEMORY_INFORMATION_CLASS, PVOID, SIZE_T, PSIZE_T)>(ntQueryVirtualMemory)(_processHandle, _baseAddress, _memoryInformationClass, _memoryInformation, _memoryInformationLength, _returnLength);
    }
    NTSTATUS NtqueryVolumeInformationFile(HANDLE _fileHandle, PIO_STATUS_BLOCK _ioStatusBlock, PVOID _fsInformation, ULONG _length, FSINFOCLASS _fsInformationClass)
    {
        if (!ntQueryVolumeInformationFile) ntQueryVolumeInformationFile = win_::resolve_proc_address("NtQueryVolumeInformationFile", 28);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PIO_STATUS_BLOCK, PVOID, ULONG, FSINFOCLASS)>(ntQueryVolumeInformationFile)(_fileHandle, _ioStatusBlock, _fsInformation, _length, _fsInformationClass);
    }
    NTSTATUS NtqueryWnfStateData(PCWNF_STATE_NAME _stateName, PCWNF_TYPE_ID _typeId, PCSID _explicitScope, PWNF_CHANGE_STAMP _changeStamp, PVOID _buffer, PULONG _bufferLength)
    {
        if (!ntQueryWnfStateData) ntQueryWnfStateData = win_::resolve_proc_address("NtQueryWnfStateData", 19);
        return reinterpret_cast<NTSTATUS(*)(PCWNF_STATE_NAME, PCWNF_TYPE_ID, PCSID, PWNF_CHANGE_STAMP, PVOID, PULONG)>(ntQueryWnfStateData)(_stateName, _typeId, _explicitScope, _changeStamp, _buffer, _bufferLength);
    }
    NTSTATUS NtqueryWnfStateNameInformation(PCWNF_STATE_NAME _stateName, WNF_STATE_NAME_INFORMATION _nameInfoClass, PCSID _explicitScope, PVOID _buffer, ULONG _bufferLength)
    {
        if (!ntQueryWnfStateNameInformation) ntQueryWnfStateNameInformation = win_::resolve_proc_address("NtQueryWnfStateNameInformation", 30);
        return reinterpret_cast<NTSTATUS(*)(PCWNF_STATE_NAME, WNF_STATE_NAME_INFORMATION, PCSID, PVOID, ULONG)>(ntQueryWnfStateNameInformation)(_stateName, _nameInfoClass, _explicitScope, _buffer, _bufferLength);
    }
    NTSTATUS NtqueueApcThread(HANDLE _threadHandle, PPS_APC_ROUTINE _apcRoutine, PVOID _apcArgument1, PVOID _apcArgument2, PVOID _apcArgument3)
    {
        if (!ntQueueApcThread) ntQueueApcThread = win_::resolve_proc_address("NtQueueApcThread", 16);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PPS_APC_ROUTINE, PVOID, PVOID, PVOID)>(ntQueueApcThread)(_threadHandle, _apcRoutine, _apcArgument1, _apcArgument2, _apcArgument3);
    }
    NTSTATUS NtqueueApcThreadEx(HANDLE _threadHandle, HANDLE _reserveHandle, PPS_APC_ROUTINE _apcRoutine, PVOID _apcArgument1, PVOID _apcArgument2, PVOID _apcArgument3)
    {
        if (!ntQueueApcThreadEx) ntQueueApcThreadEx = win_::resolve_proc_address("NtQueueApcThreadEx", 18);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE, PPS_APC_ROUTINE, PVOID, PVOID, PVOID)>(ntQueueApcThreadEx)(_threadHandle, _reserveHandle, _apcRoutine, _apcArgument1, _apcArgument2, _apcArgument3);
    }
    NTSTATUS NtqueueApcThreadEx2(HANDLE _threadHandle, HANDLE _reserveHandle, ULONG _apcFlags, PPS_APC_ROUTINE _apcRoutine, PVOID _apcArgument1, PVOID _apcArgument2, PVOID _apcArgument3)
    {
        if (!ntQueueApcThreadEx2) ntQueueApcThreadEx2 = win_::resolve_proc_address("NtQueueApcThreadEx2", 19);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE, ULONG, PPS_APC_ROUTINE, PVOID, PVOID, PVOID)>(ntQueueApcThreadEx2)(_threadHandle, _reserveHandle, _apcFlags, _apcRoutine, _apcArgument1, _apcArgument2, _apcArgument3);
    }
    NTSTATUS NtraiseException(PEXCEPTION_RECORD _exceptionRecord, PCONTEXT _contextRecord, BOOLEAN _firstChance)
    {
        if (!ntRaiseException) ntRaiseException = win_::resolve_proc_address("NtRaiseException", 16);
        return reinterpret_cast<NTSTATUS(*)(PEXCEPTION_RECORD, PCONTEXT, BOOLEAN)>(ntRaiseException)(_exceptionRecord, _contextRecord, _firstChance);
    }
    NTSTATUS NtreadFile(HANDLE _fileHandle, HANDLE _event, PIO_APC_ROUTINE _apcRoutine, PVOID _apcContext, PIO_STATUS_BLOCK _ioStatusBlock, PVOID _buffer, ULONG _length, PLARGE_INTEGER _byteOffset, PULONG _key)
    {
        if (!ntReadFile) ntReadFile = win_::resolve_proc_address("NtReadFile", 10);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE, PIO_APC_ROUTINE, PVOID, PIO_STATUS_BLOCK, PVOID, ULONG, PLARGE_INTEGER, PULONG)>(ntReadFile)(_fileHandle, _event, _apcRoutine, _apcContext, _ioStatusBlock, _buffer, _length, _byteOffset, _key);
    }
    NTSTATUS NtreadFileScatter(HANDLE _fileHandle, HANDLE _event, PIO_APC_ROUTINE _apcRoutine, PVOID _apcContext, PIO_STATUS_BLOCK _ioStatusBlock, PFILE_SEGMENT_ELEMENT _segmentArray, ULONG _length, PLARGE_INTEGER _byteOffset, PULONG _key)
    {
        if (!ntReadFileScatter) ntReadFileScatter = win_::resolve_proc_address("NtReadFileScatter", 17);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE, PIO_APC_ROUTINE, PVOID, PIO_STATUS_BLOCK, PFILE_SEGMENT_ELEMENT, ULONG, PLARGE_INTEGER, PULONG)>(ntReadFileScatter)(_fileHandle, _event, _apcRoutine, _apcContext, _ioStatusBlock, _segmentArray, _length, _byteOffset, _key);
    }
    NTSTATUS NtreadOnlyEnlistment(HANDLE _enlistmentHandle, PLARGE_INTEGER _tmVirtualClock)
    {
        if (!ntReadOnlyEnlistment) ntReadOnlyEnlistment = win_::resolve_proc_address("NtReadOnlyEnlistment", 20);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PLARGE_INTEGER)>(ntReadOnlyEnlistment)(_enlistmentHandle, _tmVirtualClock);
    }
    NTSTATUS NtreadRequestData(HANDLE _portHandle, PPORT_MESSAGE _message, ULONG _dataEntryIndex, PVOID _buffer, SIZE_T _bufferSize, PSIZE_T _numberOfBytesRead)
    {
        if (!ntReadRequestData) ntReadRequestData = win_::resolve_proc_address("NtReadRequestData", 17);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PPORT_MESSAGE, ULONG, PVOID, SIZE_T, PSIZE_T)>(ntReadRequestData)(_portHandle, _message, _dataEntryIndex, _buffer, _bufferSize, _numberOfBytesRead);
    }
    NTSTATUS NtreadVirtualMemory(HANDLE _processHandle, PVOID _baseAddress, PVOID _buffer, SIZE_T _numberOfBytesToRead, PSIZE_T _numberOfBytesRead)
    {
        if (!ntReadVirtualMemory) ntReadVirtualMemory = win_::resolve_proc_address("NtReadVirtualMemory", 19);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PVOID, PVOID, SIZE_T, PSIZE_T)>(ntReadVirtualMemory)(_processHandle, _baseAddress, _buffer, _numberOfBytesToRead, _numberOfBytesRead);
    }
    NTSTATUS NtreadVirtualMemoryEx(HANDLE _processHandle, PVOID _baseAddress, PVOID _buffer, SIZE_T _numberOfBytesToRead, PSIZE_T _numberOfBytesRead, ULONG _flags)
    {
        if (!ntReadVirtualMemoryEx) ntReadVirtualMemoryEx = win_::resolve_proc_address("NtReadVirtualMemoryEx", 21);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PVOID, PVOID, SIZE_T, PSIZE_T, ULONG)>(ntReadVirtualMemoryEx)(_processHandle, _baseAddress, _buffer, _numberOfBytesToRead, _numberOfBytesRead, _flags);
    }
    NTSTATUS NtrecoverEnlistment(HANDLE _enlistmentHandle, PVOID _enlistmentKey)
    {
        if (!ntRecoverEnlistment) ntRecoverEnlistment = win_::resolve_proc_address("NtRecoverEnlistment", 19);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PVOID)>(ntRecoverEnlistment)(_enlistmentHandle, _enlistmentKey);
    }
    NTSTATUS NtrecoverResourceManager(HANDLE _resourceManagerHandle)
    {
        if (!ntRecoverResourceManager) ntRecoverResourceManager = win_::resolve_proc_address("NtRecoverResourceManager", 24);
        return reinterpret_cast<NTSTATUS(*)(HANDLE)>(ntRecoverResourceManager)(_resourceManagerHandle);
    }
    NTSTATUS NtrecoverTransactionManager(HANDLE _transactionManagerHandle)
    {
        if (!ntRecoverTransactionManager) ntRecoverTransactionManager = win_::resolve_proc_address("NtRecoverTransactionManager", 27);
        return reinterpret_cast<NTSTATUS(*)(HANDLE)>(ntRecoverTransactionManager)(_transactionManagerHandle);
    }
    NTSTATUS NtregisterProtocolAddressInformation(HANDLE _resourceManager, PCRM_PROTOCOL_ID _protocolId, ULONG _protocolInformationSize, PVOID _protocolInformation, ULONG _createOptions)
    {
        if (!ntRegisterProtocolAddressInformation) ntRegisterProtocolAddressInformation = win_::resolve_proc_address("NtRegisterProtocolAddressInformation", 36);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PCRM_PROTOCOL_ID, ULONG, PVOID, ULONG)>(ntRegisterProtocolAddressInformation)(_resourceManager, _protocolId, _protocolInformationSize, _protocolInformation, _createOptions);
    }
    NTSTATUS NtregisterThreadTerminatePort(HANDLE _portHandle)
    {
        if (!ntRegisterThreadTerminatePort) ntRegisterThreadTerminatePort = win_::resolve_proc_address("NtRegisterThreadTerminatePort", 29);
        return reinterpret_cast<NTSTATUS(*)(HANDLE)>(ntRegisterThreadTerminatePort)(_portHandle);
    }
    NTSTATUS NtreleaseKeyedEvent(HANDLE _keyedEventHandle, PVOID _keyValue, BOOLEAN _alertable, PLARGE_INTEGER _timeout)
    {
        if (!ntReleaseKeyedEvent) ntReleaseKeyedEvent = win_::resolve_proc_address("NtReleaseKeyedEvent", 19);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PVOID, BOOLEAN, PLARGE_INTEGER)>(ntReleaseKeyedEvent)(_keyedEventHandle, _keyValue, _alertable, _timeout);
    }
    NTSTATUS NtreleaseMutant(HANDLE _mutantHandle, PLONG _previousCount)
    {
        if (!ntReleaseMutant) ntReleaseMutant = win_::resolve_proc_address("NtReleaseMutant", 15);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PLONG)>(ntReleaseMutant)(_mutantHandle, _previousCount);
    }
    NTSTATUS NtreleaseSemaphore(HANDLE _semaphoreHandle, LONG _releaseCount, PLONG _previousCount)
    {
        if (!ntReleaseSemaphore) ntReleaseSemaphore = win_::resolve_proc_address("NtReleaseSemaphore", 18);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, LONG, PLONG)>(ntReleaseSemaphore)(_semaphoreHandle, _releaseCount, _previousCount);
    }
    NTSTATUS NtreleaseWorkerFactoryWorker(HANDLE _workerFactoryHandle)
    {
        if (!ntReleaseWorkerFactoryWorker) ntReleaseWorkerFactoryWorker = win_::resolve_proc_address("NtReleaseWorkerFactoryWorker", 28);
        return reinterpret_cast<NTSTATUS(*)(HANDLE)>(ntReleaseWorkerFactoryWorker)(_workerFactoryHandle);
    }
    NTSTATUS NtremoveIoCompletion(HANDLE _ioCompletionHandle, PVOID* _keyContext, PVOID* _apcContext, PIO_STATUS_BLOCK _ioStatusBlock, PLARGE_INTEGER _timeout)
    {
        if (!ntRemoveIoCompletion) ntRemoveIoCompletion = win_::resolve_proc_address("NtRemoveIoCompletion", 20);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PVOID*, PVOID*, PIO_STATUS_BLOCK, PLARGE_INTEGER)>(ntRemoveIoCompletion)(_ioCompletionHandle, _keyContext, _apcContext, _ioStatusBlock, _timeout);
    }
    NTSTATUS NtremoveIoCompletionEx(HANDLE _ioCompletionHandle, PFILE_IO_COMPLETION_INFORMATION _ioCompletionInformation, ULONG _count, PULONG _numEntriesRemoved, PLARGE_INTEGER _timeout, BOOLEAN _alertable)
    {
        if (!ntRemoveIoCompletionEx) ntRemoveIoCompletionEx = win_::resolve_proc_address("NtRemoveIoCompletionEx", 22);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PFILE_IO_COMPLETION_INFORMATION, ULONG, PULONG, PLARGE_INTEGER, BOOLEAN)>(ntRemoveIoCompletionEx)(_ioCompletionHandle, _ioCompletionInformation, _count, _numEntriesRemoved, _timeout, _alertable);
    }
    NTSTATUS NtremoveProcessDebug(HANDLE _processHandle, HANDLE _debugObjectHandle)
    {
        if (!ntRemoveProcessDebug) ntRemoveProcessDebug = win_::resolve_proc_address("NtRemoveProcessDebug", 20);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE)>(ntRemoveProcessDebug)(_processHandle, _debugObjectHandle);
    }
    NTSTATUS NtrenameKey(HANDLE _keyHandle, PCUNICODE_STRING _newName)
    {
        if (!ntRenameKey) ntRenameKey = win_::resolve_proc_address("NtRenameKey", 11);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PCUNICODE_STRING)>(ntRenameKey)(_keyHandle, _newName);
    }
    NTSTATUS NtrenameTransactionManager(PCUNICODE_STRING _logFileName, LPGUID _existingTransactionManagerGuid)
    {
        if (!ntRenameTransactionManager) ntRenameTransactionManager = win_::resolve_proc_address("NtRenameTransactionManager", 26);
        return reinterpret_cast<NTSTATUS(*)(PCUNICODE_STRING, LPGUID)>(ntRenameTransactionManager)(_logFileName, _existingTransactionManagerGuid);
    }
    NTSTATUS NtreplaceKey(POBJECT_ATTRIBUTES _newFile, HANDLE _targetHandle, POBJECT_ATTRIBUTES _oldFile)
    {
        if (!ntReplaceKey) ntReplaceKey = win_::resolve_proc_address("NtReplaceKey", 12);
        return reinterpret_cast<NTSTATUS(*)(POBJECT_ATTRIBUTES, HANDLE, POBJECT_ATTRIBUTES)>(ntReplaceKey)(_newFile, _targetHandle, _oldFile);
    }
    NTSTATUS NtreplacePartitionUnit(PCUNICODE_STRING _targetInstancePath, PCUNICODE_STRING _spareInstancePath, ULONG _flags)
    {
        if (!ntReplacePartitionUnit) ntReplacePartitionUnit = win_::resolve_proc_address("NtReplacePartitionUnit", 22);
        return reinterpret_cast<NTSTATUS(*)(PCUNICODE_STRING, PCUNICODE_STRING, ULONG)>(ntReplacePartitionUnit)(_targetInstancePath, _spareInstancePath, _flags);
    }
    NTSTATUS NtreplyPort(HANDLE _portHandle, PPORT_MESSAGE _replyMessage)
    {
        if (!ntReplyPort) ntReplyPort = win_::resolve_proc_address("NtReplyPort", 11);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PPORT_MESSAGE)>(ntReplyPort)(_portHandle, _replyMessage);
    }
    NTSTATUS NtreplyWaitReceivePort(HANDLE _portHandle, PVOID* _portContext, PPORT_MESSAGE _replyMessage, PPORT_MESSAGE _receiveMessage)
    {
        if (!ntReplyWaitReceivePort) ntReplyWaitReceivePort = win_::resolve_proc_address("NtReplyWaitReceivePort", 22);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PVOID*, PPORT_MESSAGE, PPORT_MESSAGE)>(ntReplyWaitReceivePort)(_portHandle, _portContext, _replyMessage, _receiveMessage);
    }
    NTSTATUS NtreplyWaitReceivePortEx(HANDLE _portHandle, PVOID* _portContext, PPORT_MESSAGE _replyMessage, PPORT_MESSAGE _receiveMessage, PLARGE_INTEGER _timeout)
    {
        if (!ntReplyWaitReceivePortEx) ntReplyWaitReceivePortEx = win_::resolve_proc_address("NtReplyWaitReceivePortEx", 24);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PVOID*, PPORT_MESSAGE, PPORT_MESSAGE, PLARGE_INTEGER)>(ntReplyWaitReceivePortEx)(_portHandle, _portContext, _replyMessage, _receiveMessage, _timeout);
    }
    NTSTATUS NtreplyWaitReplyPort(HANDLE _portHandle, PPORT_MESSAGE _replyMessage)
    {
        if (!ntReplyWaitReplyPort) ntReplyWaitReplyPort = win_::resolve_proc_address("NtReplyWaitReplyPort", 20);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PPORT_MESSAGE)>(ntReplyWaitReplyPort)(_portHandle, _replyMessage);
    }
    NTSTATUS NtrequestPort(HANDLE _portHandle, PPORT_MESSAGE _requestMessage)
    {
        if (!ntRequestPort) ntRequestPort = win_::resolve_proc_address("NtRequestPort", 13);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PPORT_MESSAGE)>(ntRequestPort)(_portHandle, _requestMessage);
    }
    NTSTATUS NtrequestWaitReplyPort(HANDLE _portHandle, PPORT_MESSAGE _requestMessage, PPORT_MESSAGE _replyMessage)
    {
        if (!ntRequestWaitReplyPort) ntRequestWaitReplyPort = win_::resolve_proc_address("NtRequestWaitReplyPort", 22);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PPORT_MESSAGE, PPORT_MESSAGE)>(ntRequestWaitReplyPort)(_portHandle, _requestMessage, _replyMessage);
    }
    NTSTATUS NtresetEvent(HANDLE _eventHandle, PLONG _previousState)
    {
        if (!ntResetEvent) ntResetEvent = win_::resolve_proc_address("NtResetEvent", 12);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PLONG)>(ntResetEvent)(_eventHandle, _previousState);
    }
    NTSTATUS NtresetWriteWatch(HANDLE _processHandle, PVOID _baseAddress, SIZE_T _regionSize)
    {
        if (!ntResetWriteWatch) ntResetWriteWatch = win_::resolve_proc_address("NtResetWriteWatch", 17);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PVOID, SIZE_T)>(ntResetWriteWatch)(_processHandle, _baseAddress, _regionSize);
    }
    NTSTATUS NtrestoreKey(HANDLE _keyHandle, HANDLE _fileHandle, ULONG _flags)
    {
        if (!ntRestoreKey) ntRestoreKey = win_::resolve_proc_address("NtRestoreKey", 12);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE, ULONG)>(ntRestoreKey)(_keyHandle, _fileHandle, _flags);
    }
    NTSTATUS NtresumeProcess(HANDLE _processHandle)
    {
        if (!ntResumeProcess) ntResumeProcess = win_::resolve_proc_address("NtResumeProcess", 15);
        return reinterpret_cast<NTSTATUS(*)(HANDLE)>(ntResumeProcess)(_processHandle);
    }
    NTSTATUS NtresumeThread(HANDLE _threadHandle, PULONG _previousSuspendCount)
    {
        if (!ntResumeThread) ntResumeThread = win_::resolve_proc_address("NtResumeThread", 14);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PULONG)>(ntResumeThread)(_threadHandle, _previousSuspendCount);
    }
    NTSTATUS NtrevertContainerImpersonation()
    {
        if (!ntRevertContainerImpersonation) ntRevertContainerImpersonation = win_::resolve_proc_address("NtRevertContainerImpersonation", 30);
        return reinterpret_cast<NTSTATUS(*)()>(ntRevertContainerImpersonation)();
    }
    NTSTATUS NtrollbackComplete(HANDLE _enlistmentHandle, PLARGE_INTEGER _tmVirtualClock)
    {
        if (!ntRollbackComplete) ntRollbackComplete = win_::resolve_proc_address("NtRollbackComplete", 18);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PLARGE_INTEGER)>(ntRollbackComplete)(_enlistmentHandle, _tmVirtualClock);
    }
    NTSTATUS NtrollbackEnlistment(HANDLE _enlistmentHandle, PLARGE_INTEGER _tmVirtualClock)
    {
        if (!ntRollbackEnlistment) ntRollbackEnlistment = win_::resolve_proc_address("NtRollbackEnlistment", 20);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PLARGE_INTEGER)>(ntRollbackEnlistment)(_enlistmentHandle, _tmVirtualClock);
    }
    NTSTATUS NtrollbackRegistryTransaction(HANDLE _registryTransactionHandle, ULONG _flags)
    {
        if (!ntRollbackRegistryTransaction) ntRollbackRegistryTransaction = win_::resolve_proc_address("NtRollbackRegistryTransaction", 29);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONG)>(ntRollbackRegistryTransaction)(_registryTransactionHandle, _flags);
    }
    NTSTATUS NtrollbackTransaction(HANDLE _transactionHandle, BOOLEAN _wait)
    {
        if (!ntRollbackTransaction) ntRollbackTransaction = win_::resolve_proc_address("NtRollbackTransaction", 21);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, BOOLEAN)>(ntRollbackTransaction)(_transactionHandle, _wait);
    }
    NTSTATUS NtrollforwardTransactionManager(HANDLE _transactionManagerHandle, PLARGE_INTEGER _tmVirtualClock)
    {
        if (!ntRollforwardTransactionManager) ntRollforwardTransactionManager = win_::resolve_proc_address("NtRollforwardTransactionManager", 31);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PLARGE_INTEGER)>(ntRollforwardTransactionManager)(_transactionManagerHandle, _tmVirtualClock);
    }
    NTSTATUS NtsaveKey(HANDLE _keyHandle, HANDLE _fileHandle)
    {
        if (!ntSaveKey) ntSaveKey = win_::resolve_proc_address("NtSaveKey", 9);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE)>(ntSaveKey)(_keyHandle, _fileHandle);
    }
    NTSTATUS NtsaveKeyEx(HANDLE _keyHandle, HANDLE _fileHandle, ULONG _format)
    {
        if (!ntSaveKeyEx) ntSaveKeyEx = win_::resolve_proc_address("NtSaveKeyEx", 11);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE, ULONG)>(ntSaveKeyEx)(_keyHandle, _fileHandle, _format);
    }
    NTSTATUS NtsaveMergedKeys(HANDLE _highPrecedenceKeyHandle, HANDLE _lowPrecedenceKeyHandle, HANDLE _fileHandle)
    {
        if (!ntSaveMergedKeys) ntSaveMergedKeys = win_::resolve_proc_address("NtSaveMergedKeys", 16);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE, HANDLE)>(ntSaveMergedKeys)(_highPrecedenceKeyHandle, _lowPrecedenceKeyHandle, _fileHandle);
    }
    NTSTATUS NtsecureConnectPort(PHANDLE _portHandle, PCUNICODE_STRING _portName, PSECURITY_QUALITY_OF_SERVICE _securityQos, PPORT_VIEW _clientView, PSID _requiredServerSid, PREMOTE_PORT_VIEW _serverView, PULONG _maxMessageLength, PVOID _connectionInformation, PULONG _connectionInformationLength)
    {
        if (!ntSecureConnectPort) ntSecureConnectPort = win_::resolve_proc_address("NtSecureConnectPort", 19);
        return reinterpret_cast<NTSTATUS(*)(PHANDLE, PCUNICODE_STRING, PSECURITY_QUALITY_OF_SERVICE, PPORT_VIEW, PSID, PREMOTE_PORT_VIEW, PULONG, PVOID, PULONG)>(ntSecureConnectPort)(_portHandle, _portName, _securityQos, _clientView, _requiredServerSid, _serverView, _maxMessageLength, _connectionInformation, _connectionInformationLength);
    }
    NTSTATUS NtserializeBoot()
    {
        if (!ntSerializeBoot) ntSerializeBoot = win_::resolve_proc_address("NtSerializeBoot", 15);
        return reinterpret_cast<NTSTATUS(*)()>(ntSerializeBoot)();
    }
    NTSTATUS NtsetBootEntryOrder(PULONG _ids, ULONG _count)
    {
        if (!ntSetBootEntryOrder) ntSetBootEntryOrder = win_::resolve_proc_address("NtSetBootEntryOrder", 19);
        return reinterpret_cast<NTSTATUS(*)(PULONG, ULONG)>(ntSetBootEntryOrder)(_ids, _count);
    }
    NTSTATUS NtsetBootOptions(PBOOT_OPTIONS _bootOptions, ULONG _fieldsToChange)
    {
        if (!ntSetBootOptions) ntSetBootOptions = win_::resolve_proc_address("NtSetBootOptions", 16);
        return reinterpret_cast<NTSTATUS(*)(PBOOT_OPTIONS, ULONG)>(ntSetBootOptions)(_bootOptions, _fieldsToChange);
    }
    NTSTATUS NtsetCachedSigningLevel(ULONG _flags, SE_SIGNING_LEVEL _inputSigningLevel, PHANDLE _sourceFiles, ULONG _sourceFileCount, HANDLE _targetFile)
    {
        if (!ntSetCachedSigningLevel) ntSetCachedSigningLevel = win_::resolve_proc_address("NtSetCachedSigningLevel", 23);
        return reinterpret_cast<NTSTATUS(*)(ULONG, SE_SIGNING_LEVEL, PHANDLE, ULONG, HANDLE)>(ntSetCachedSigningLevel)(_flags, _inputSigningLevel, _sourceFiles, _sourceFileCount, _targetFile);
    }
    NTSTATUS NtsetCachedSigningLevel2(ULONG _flags, SE_SIGNING_LEVEL _inputSigningLevel, PHANDLE _sourceFiles, ULONG _sourceFileCount, HANDLE _targetFile, SE_SET_FILE_CACHE_INFORMATION* _cacheInformation)
    {
        if (!ntSetCachedSigningLevel2) ntSetCachedSigningLevel2 = win_::resolve_proc_address("NtSetCachedSigningLevel2", 24);
        return reinterpret_cast<NTSTATUS(*)(ULONG, SE_SIGNING_LEVEL, PHANDLE, ULONG, HANDLE, SE_SET_FILE_CACHE_INFORMATION*)>(ntSetCachedSigningLevel2)(_flags, _inputSigningLevel, _sourceFiles, _sourceFileCount, _targetFile, _cacheInformation);
    }
    NTSTATUS NtsetContextThread(HANDLE _threadHandle, PCONTEXT _threadContext)
    {
        if (!ntSetContextThread) ntSetContextThread = win_::resolve_proc_address("NtSetContextThread", 18);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PCONTEXT)>(ntSetContextThread)(_threadHandle, _threadContext);
    }
    NTSTATUS NtsetDebugFilterState(ULONG _componentId, ULONG _level, BOOLEAN _state)
    {
        if (!ntSetDebugFilterState) ntSetDebugFilterState = win_::resolve_proc_address("NtSetDebugFilterState", 21);
        return reinterpret_cast<NTSTATUS(*)(ULONG, ULONG, BOOLEAN)>(ntSetDebugFilterState)(_componentId, _level, _state);
    }
    NTSTATUS NtsetDefaultHardErrorPort(HANDLE _defaultHardErrorPort)
    {
        if (!ntSetDefaultHardErrorPort) ntSetDefaultHardErrorPort = win_::resolve_proc_address("NtSetDefaultHardErrorPort", 25);
        return reinterpret_cast<NTSTATUS(*)(HANDLE)>(ntSetDefaultHardErrorPort)(_defaultHardErrorPort);
    }
    NTSTATUS NtsetDefaultLocale(BOOLEAN _userProfile, LCID _defaultLocaleId)
    {
        if (!ntSetDefaultLocale) ntSetDefaultLocale = win_::resolve_proc_address("NtSetDefaultLocale", 18);
        return reinterpret_cast<NTSTATUS(*)(BOOLEAN, LCID)>(ntSetDefaultLocale)(_userProfile, _defaultLocaleId);
    }
    NTSTATUS NtsetDefaultUILanguage(LANGID _defaultUILanguageId)
    {
        if (!ntSetDefaultUILanguage) ntSetDefaultUILanguage = win_::resolve_proc_address("NtSetDefaultUILanguage", 22);
        return reinterpret_cast<NTSTATUS(*)(LANGID)>(ntSetDefaultUILanguage)(_defaultUILanguageId);
    }
    NTSTATUS NtsetDriverEntryOrder(PULONG _ids, ULONG _count)
    {
        if (!ntSetDriverEntryOrder) ntSetDriverEntryOrder = win_::resolve_proc_address("NtSetDriverEntryOrder", 21);
        return reinterpret_cast<NTSTATUS(*)(PULONG, ULONG)>(ntSetDriverEntryOrder)(_ids, _count);
    }
    NTSTATUS NtsetEaFile(HANDLE _fileHandle, PIO_STATUS_BLOCK _ioStatusBlock, PVOID _buffer, ULONG _length)
    {
        if (!ntSetEaFile) ntSetEaFile = win_::resolve_proc_address("NtSetEaFile", 11);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PIO_STATUS_BLOCK, PVOID, ULONG)>(ntSetEaFile)(_fileHandle, _ioStatusBlock, _buffer, _length);
    }
    NTSTATUS NtsetEvent(HANDLE _eventHandle, PLONG _previousState)
    {
        if (!ntSetEvent) ntSetEvent = win_::resolve_proc_address("NtSetEvent", 10);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PLONG)>(ntSetEvent)(_eventHandle, _previousState);
    }
    NTSTATUS NtsetEventBoostPriority(HANDLE _eventHandle)
    {
        if (!ntSetEventBoostPriority) ntSetEventBoostPriority = win_::resolve_proc_address("NtSetEventBoostPriority", 23);
        return reinterpret_cast<NTSTATUS(*)(HANDLE)>(ntSetEventBoostPriority)(_eventHandle);
    }
    NTSTATUS NtsetEventEx(HANDLE _threadId, PRTL_SRWLOCK _lock)
    {
        if (!ntSetEventEx) ntSetEventEx = win_::resolve_proc_address("NtSetEventEx", 12);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PRTL_SRWLOCK)>(ntSetEventEx)(_threadId, _lock);
    }
    NTSTATUS NtsetHighEventPair(HANDLE _eventPairHandle)
    {
        if (!ntSetHighEventPair) ntSetHighEventPair = win_::resolve_proc_address("NtSetHighEventPair", 18);
        return reinterpret_cast<NTSTATUS(*)(HANDLE)>(ntSetHighEventPair)(_eventPairHandle);
    }
    NTSTATUS NtsetHighWaitLowEventPair(HANDLE _eventPairHandle)
    {
        if (!ntSetHighWaitLowEventPair) ntSetHighWaitLowEventPair = win_::resolve_proc_address("NtSetHighWaitLowEventPair", 25);
        return reinterpret_cast<NTSTATUS(*)(HANDLE)>(ntSetHighWaitLowEventPair)(_eventPairHandle);
    }
    NTSTATUS NtsetIRTimer(HANDLE _timerHandle, PLARGE_INTEGER _dueTime)
    {
        if (!ntSetIRTimer) ntSetIRTimer = win_::resolve_proc_address("NtSetIRTimer", 12);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PLARGE_INTEGER)>(ntSetIRTimer)(_timerHandle, _dueTime);
    }
    NTSTATUS NtsetInformationCpuPartition(HANDLE _cpuPartitionHandle, ULONG _cpuPartitionInformationClass, PVOID _cpuPartitionInformation, ULONG _cpuPartitionInformationLength)
    {
        if (!ntSetInformationCpuPartition) ntSetInformationCpuPartition = win_::resolve_proc_address("NtSetInformationCpuPartition", 28);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONG, PVOID, ULONG)>(ntSetInformationCpuPartition)(_cpuPartitionHandle, _cpuPartitionInformationClass, _cpuPartitionInformation, _cpuPartitionInformationLength);
    }
    NTSTATUS NtsetInformationDebugObject(HANDLE _debugObjectHandle, DEBUGOBJECTINFOCLASS _debugObjectInformationClass, PVOID _debugInformation, ULONG _debugInformationLength, PULONG _returnLength)
    {
        if (!ntSetInformationDebugObject) ntSetInformationDebugObject = win_::resolve_proc_address("NtSetInformationDebugObject", 27);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, DEBUGOBJECTINFOCLASS, PVOID, ULONG, PULONG)>(ntSetInformationDebugObject)(_debugObjectHandle, _debugObjectInformationClass, _debugInformation, _debugInformationLength, _returnLength);
    }
    NTSTATUS NtsetInformationEnlistment(HANDLE _enlistmentHandle, ENLISTMENT_INFORMATION_CLASS _enlistmentInformationClass, PVOID _enlistmentInformation, ULONG _enlistmentInformationLength)
    {
        if (!ntSetInformationEnlistment) ntSetInformationEnlistment = win_::resolve_proc_address("NtSetInformationEnlistment", 26);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ENLISTMENT_INFORMATION_CLASS, PVOID, ULONG)>(ntSetInformationEnlistment)(_enlistmentHandle, _enlistmentInformationClass, _enlistmentInformation, _enlistmentInformationLength);
    }
    NTSTATUS NtsetInformationFile(HANDLE _fileHandle, PIO_STATUS_BLOCK _ioStatusBlock, PVOID _fileInformation, ULONG _length, FILE_INFORMATION_CLASS _fileInformationClass)
    {
        if (!ntSetInformationFile) ntSetInformationFile = win_::resolve_proc_address("NtSetInformationFile", 20);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PIO_STATUS_BLOCK, PVOID, ULONG, FILE_INFORMATION_CLASS)>(ntSetInformationFile)(_fileHandle, _ioStatusBlock, _fileInformation, _length, _fileInformationClass);
    }
    NTSTATUS NtsetInformationIoRing(HANDLE _ioRingHandle, ULONG _ioRingInformationClass, ULONG _ioRingInformationLength, PVOID _ioRingInformation)
    {
        if (!ntSetInformationIoRing) ntSetInformationIoRing = win_::resolve_proc_address("NtSetInformationIoRing", 22);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONG, ULONG, PVOID)>(ntSetInformationIoRing)(_ioRingHandle, _ioRingInformationClass, _ioRingInformationLength, _ioRingInformation);
    }
    NTSTATUS NtsetInformationJobObject(HANDLE _jobHandle, ULONG _jobObjectInformationClass, PVOID _jobObjectInformation, ULONG _jobObjectInformationLength)
    {
        if (!ntSetInformationJobObject) ntSetInformationJobObject = win_::resolve_proc_address("NtSetInformationJobObject", 25);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONG, PVOID, ULONG)>(ntSetInformationJobObject)(_jobHandle, _jobObjectInformationClass, _jobObjectInformation, _jobObjectInformationLength);
    }
    NTSTATUS NtsetInformationKey(HANDLE _keyHandle, KEY_SET_INFORMATION_CLASS _keySetInformationClass, PVOID _keySetInformation, ULONG _keySetInformationLength)
    {
        if (!ntSetInformationKey) ntSetInformationKey = win_::resolve_proc_address("NtSetInformationKey", 19);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, KEY_SET_INFORMATION_CLASS, PVOID, ULONG)>(ntSetInformationKey)(_keyHandle, _keySetInformationClass, _keySetInformation, _keySetInformationLength);
    }
    NTSTATUS NtsetInformationObject(HANDLE _handle, OBJECT_INFORMATION_CLASS _objectInformationClass, PVOID _objectInformation, ULONG _objectInformationLength)
    {
        if (!ntSetInformationObject) ntSetInformationObject = win_::resolve_proc_address("NtSetInformationObject", 22);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, OBJECT_INFORMATION_CLASS, PVOID, ULONG)>(ntSetInformationObject)(_handle, _objectInformationClass, _objectInformation, _objectInformationLength);
    }
    NTSTATUS NtsetInformationProcess(HANDLE _processHandle, PROCESSINFOCLASS _processInformationClass, PVOID _processInformation, ULONG _processInformationLength)
    {
        if (!ntSetInformationProcess) ntSetInformationProcess = win_::resolve_proc_address("NtSetInformationProcess", 23);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PROCESSINFOCLASS, PVOID, ULONG)>(ntSetInformationProcess)(_processHandle, _processInformationClass, _processInformation, _processInformationLength);
    }
    NTSTATUS NtsetInformationResourceManager(HANDLE _resourceManagerHandle, RESOURCEMANAGER_INFORMATION_CLASS _resourceManagerInformationClass, PVOID _resourceManagerInformation, ULONG _resourceManagerInformationLength)
    {
        if (!ntSetInformationResourceManager) ntSetInformationResourceManager = win_::resolve_proc_address("NtSetInformationResourceManager", 31);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, RESOURCEMANAGER_INFORMATION_CLASS, PVOID, ULONG)>(ntSetInformationResourceManager)(_resourceManagerHandle, _resourceManagerInformationClass, _resourceManagerInformation, _resourceManagerInformationLength);
    }
    NTSTATUS NtsetInformationSymbolicLink(HANDLE _linkHandle, SYMBOLIC_LINK_INFO_CLASS _symbolicLinkInformationClass, PVOID _symbolicLinkInformation, ULONG _symbolicLinkInformationLength)
    {
        if (!ntSetInformationSymbolicLink) ntSetInformationSymbolicLink = win_::resolve_proc_address("NtSetInformationSymbolicLink", 28);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, SYMBOLIC_LINK_INFO_CLASS, PVOID, ULONG)>(ntSetInformationSymbolicLink)(_linkHandle, _symbolicLinkInformationClass, _symbolicLinkInformation, _symbolicLinkInformationLength);
    }
    NTSTATUS NtsetInformationThread(HANDLE _threadHandle, THREADINFOCLASS _threadInformationClass, PVOID _threadInformation, ULONG _threadInformationLength)
    {
        if (!ntSetInformationThread) ntSetInformationThread = win_::resolve_proc_address("NtSetInformationThread", 22);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, THREADINFOCLASS, PVOID, ULONG)>(ntSetInformationThread)(_threadHandle, _threadInformationClass, _threadInformation, _threadInformationLength);
    }
    NTSTATUS NtsetInformationToken(HANDLE _tokenHandle, TOKEN_INFORMATION_CLASS _tokenInformationClass, PVOID _tokenInformation, ULONG _tokenInformationLength)
    {
        if (!ntSetInformationToken) ntSetInformationToken = win_::resolve_proc_address("NtSetInformationToken", 21);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, TOKEN_INFORMATION_CLASS, PVOID, ULONG)>(ntSetInformationToken)(_tokenHandle, _tokenInformationClass, _tokenInformation, _tokenInformationLength);
    }
    NTSTATUS NtsetInformationTransaction(HANDLE _transactionHandle, TRANSACTION_INFORMATION_CLASS _transactionInformationClass, PVOID _transactionInformation, ULONG _transactionInformationLength)
    {
        if (!ntSetInformationTransaction) ntSetInformationTransaction = win_::resolve_proc_address("NtSetInformationTransaction", 27);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, TRANSACTION_INFORMATION_CLASS, PVOID, ULONG)>(ntSetInformationTransaction)(_transactionHandle, _transactionInformationClass, _transactionInformation, _transactionInformationLength);
    }
    NTSTATUS NtsetInformationTransactionManager(HANDLE _tmHandle, TRANSACTIONMANAGER_INFORMATION_CLASS _transactionManagerInformationClass, PVOID _transactionManagerInformation, ULONG _transactionManagerInformationLength)
    {
        if (!ntSetInformationTransactionManager) ntSetInformationTransactionManager = win_::resolve_proc_address("NtSetInformationTransactionManager", 34);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, TRANSACTIONMANAGER_INFORMATION_CLASS, PVOID, ULONG)>(ntSetInformationTransactionManager)(_tmHandle, _transactionManagerInformationClass, _transactionManagerInformation, _transactionManagerInformationLength);
    }
    NTSTATUS NtsetInformationVirtualMemory(HANDLE _processHandle, VIRTUAL_MEMORY_INFORMATION_CLASS _vmInformationClass, SIZE_T _numberOfEntries, PMEMORY_RANGE_ENTRY _virtualAddresses, PVOID _vmInformation, ULONG _vmInformationLength)
    {
        if (!ntSetInformationVirtualMemory) ntSetInformationVirtualMemory = win_::resolve_proc_address("NtSetInformationVirtualMemory", 29);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, VIRTUAL_MEMORY_INFORMATION_CLASS, SIZE_T, PMEMORY_RANGE_ENTRY, PVOID, ULONG)>(ntSetInformationVirtualMemory)(_processHandle, _vmInformationClass, _numberOfEntries, _virtualAddresses, _vmInformation, _vmInformationLength);
    }
    NTSTATUS NtsetInformationWorkerFactory(HANDLE _workerFactoryHandle, WORKERFACTORYINFOCLASS _workerFactoryInformationClass, PVOID _workerFactoryInformation, ULONG _workerFactoryInformationLength)
    {
        if (!ntSetInformationWorkerFactory) ntSetInformationWorkerFactory = win_::resolve_proc_address("NtSetInformationWorkerFactory", 29);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, WORKERFACTORYINFOCLASS, PVOID, ULONG)>(ntSetInformationWorkerFactory)(_workerFactoryHandle, _workerFactoryInformationClass, _workerFactoryInformation, _workerFactoryInformationLength);
    }
    NTSTATUS NtsetIntervalProfile(ULONG _interval, KPROFILE_SOURCE _source)
    {
        if (!ntSetIntervalProfile) ntSetIntervalProfile = win_::resolve_proc_address("NtSetIntervalProfile", 20);
        return reinterpret_cast<NTSTATUS(*)(ULONG, KPROFILE_SOURCE)>(ntSetIntervalProfile)(_interval, _source);
    }
    NTSTATUS NtsetIoCompletion(HANDLE _ioCompletionHandle, PVOID _keyContext, PVOID _apcContext, NTSTATUS _ioStatus, ULONG_PTR _ioStatusInformation)
    {
        if (!ntSetIoCompletion) ntSetIoCompletion = win_::resolve_proc_address("NtSetIoCompletion", 17);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PVOID, PVOID, NTSTATUS, ULONG_PTR)>(ntSetIoCompletion)(_ioCompletionHandle, _keyContext, _apcContext, _ioStatus, _ioStatusInformation);
    }
    NTSTATUS NtsetIoCompletionEx(HANDLE _ioCompletionHandle, HANDLE _ioCompletionPacketHandle, PVOID _keyContext, PVOID _apcContext, NTSTATUS _ioStatus, ULONG_PTR _ioStatusInformation)
    {
        if (!ntSetIoCompletionEx) ntSetIoCompletionEx = win_::resolve_proc_address("NtSetIoCompletionEx", 19);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE, PVOID, PVOID, NTSTATUS, ULONG_PTR)>(ntSetIoCompletionEx)(_ioCompletionHandle, _ioCompletionPacketHandle, _keyContext, _apcContext, _ioStatus, _ioStatusInformation);
    }
    NTSTATUS NtsetLdtEntries(ULONG _selector0, ULONG _entry0Low, ULONG _entry0Hi, ULONG _selector1, ULONG _entry1Low, ULONG _entry1Hi)
    {
        if (!ntSetLdtEntries) ntSetLdtEntries = win_::resolve_proc_address("NtSetLdtEntries", 15);
        return reinterpret_cast<NTSTATUS(*)(ULONG, ULONG, ULONG, ULONG, ULONG, ULONG)>(ntSetLdtEntries)(_selector0, _entry0Low, _entry0Hi, _selector1, _entry1Low, _entry1Hi);
    }
    NTSTATUS NtsetLowEventPair(HANDLE _eventPairHandle)
    {
        if (!ntSetLowEventPair) ntSetLowEventPair = win_::resolve_proc_address("NtSetLowEventPair", 17);
        return reinterpret_cast<NTSTATUS(*)(HANDLE)>(ntSetLowEventPair)(_eventPairHandle);
    }
    NTSTATUS NtsetLowWaitHighEventPair(HANDLE _eventPairHandle)
    {
        if (!ntSetLowWaitHighEventPair) ntSetLowWaitHighEventPair = win_::resolve_proc_address("NtSetLowWaitHighEventPair", 25);
        return reinterpret_cast<NTSTATUS(*)(HANDLE)>(ntSetLowWaitHighEventPair)(_eventPairHandle);
    }
    NTSTATUS NtsetQuotaInformationFile(HANDLE _fileHandle, PIO_STATUS_BLOCK _ioStatusBlock, PVOID _buffer, ULONG _length)
    {
        if (!ntSetQuotaInformationFile) ntSetQuotaInformationFile = win_::resolve_proc_address("NtSetQuotaInformationFile", 25);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PIO_STATUS_BLOCK, PVOID, ULONG)>(ntSetQuotaInformationFile)(_fileHandle, _ioStatusBlock, _buffer, _length);
    }
    NTSTATUS NtsetSecurityObject(HANDLE _handle, SECURITY_INFORMATION _securityInformation, PSECURITY_DESCRIPTOR _securityDescriptor)
    {
        if (!ntSetSecurityObject) ntSetSecurityObject = win_::resolve_proc_address("NtSetSecurityObject", 19);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, SECURITY_INFORMATION, PSECURITY_DESCRIPTOR)>(ntSetSecurityObject)(_handle, _securityInformation, _securityDescriptor);
    }
    NTSTATUS NtsetSystemEnvironmentValue(PCUNICODE_STRING _variableName, PCUNICODE_STRING _variableValue)
    {
        if (!ntSetSystemEnvironmentValue) ntSetSystemEnvironmentValue = win_::resolve_proc_address("NtSetSystemEnvironmentValue", 27);
        return reinterpret_cast<NTSTATUS(*)(PCUNICODE_STRING, PCUNICODE_STRING)>(ntSetSystemEnvironmentValue)(_variableName, _variableValue);
    }
    NTSTATUS NtsetSystemEnvironmentValueEx(PCUNICODE_STRING _variableName, PCGUID _vendorGuid, PVOID _buffer, ULONG _bufferLength, ULONG _attributes)
    {
        if (!ntSetSystemEnvironmentValueEx) ntSetSystemEnvironmentValueEx = win_::resolve_proc_address("NtSetSystemEnvironmentValueEx", 29);
        return reinterpret_cast<NTSTATUS(*)(PCUNICODE_STRING, PCGUID, PVOID, ULONG, ULONG)>(ntSetSystemEnvironmentValueEx)(_variableName, _vendorGuid, _buffer, _bufferLength, _attributes);
    }
    NTSTATUS NtsetSystemInformation(SYSTEM_INFORMATION_CLASS _systemInformationClass, PVOID _systemInformation, ULONG _systemInformationLength)
    {
        if (!ntSetSystemInformation) ntSetSystemInformation = win_::resolve_proc_address("NtSetSystemInformation", 22);
        return reinterpret_cast<NTSTATUS(*)(SYSTEM_INFORMATION_CLASS, PVOID, ULONG)>(ntSetSystemInformation)(_systemInformationClass, _systemInformation, _systemInformationLength);
    }
    NTSTATUS NtsetSystemPowerState(POWER_ACTION _systemAction, SYSTEM_POWER_STATE _lightestSystemState, ULONG _flags)
    {
        if (!ntSetSystemPowerState) ntSetSystemPowerState = win_::resolve_proc_address("NtSetSystemPowerState", 21);
        return reinterpret_cast<NTSTATUS(*)(POWER_ACTION, SYSTEM_POWER_STATE, ULONG)>(ntSetSystemPowerState)(_systemAction, _lightestSystemState, _flags);
    }
    NTSTATUS NtsetSystemTime(PLARGE_INTEGER _systemTime, PLARGE_INTEGER _previousTime)
    {
        if (!ntSetSystemTime) ntSetSystemTime = win_::resolve_proc_address("NtSetSystemTime", 15);
        return reinterpret_cast<NTSTATUS(*)(PLARGE_INTEGER, PLARGE_INTEGER)>(ntSetSystemTime)(_systemTime, _previousTime);
    }
    NTSTATUS NtsetThreadExecutionState(EXECUTION_STATE _newFlags, EXECUTION_STATE* _previousFlags)
    {
        if (!ntSetThreadExecutionState) ntSetThreadExecutionState = win_::resolve_proc_address("NtSetThreadExecutionState", 25);
        return reinterpret_cast<NTSTATUS(*)(EXECUTION_STATE, EXECUTION_STATE*)>(ntSetThreadExecutionState)(_newFlags, _previousFlags);
    }
    NTSTATUS NtsetTimer(HANDLE _timerHandle, PLARGE_INTEGER _dueTime, PTIMER_APC_ROUTINE _timerApcRoutine, PVOID _timerContext, BOOLEAN _resumeTimer, LONG _period, PBOOLEAN _previousState)
    {
        if (!ntSetTimer) ntSetTimer = win_::resolve_proc_address("NtSetTimer", 10);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PLARGE_INTEGER, PTIMER_APC_ROUTINE, PVOID, BOOLEAN, LONG, PBOOLEAN)>(ntSetTimer)(_timerHandle, _dueTime, _timerApcRoutine, _timerContext, _resumeTimer, _period, _previousState);
    }
    NTSTATUS NtsetTimer2(HANDLE _timerHandle, PLARGE_INTEGER _dueTime, PLARGE_INTEGER _period, PT2_SET_PARAMETERS _parameters)
    {
        if (!ntSetTimer2) ntSetTimer2 = win_::resolve_proc_address("NtSetTimer2", 11);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PLARGE_INTEGER, PLARGE_INTEGER, PT2_SET_PARAMETERS)>(ntSetTimer2)(_timerHandle, _dueTime, _period, _parameters);
    }
    NTSTATUS NtsetTimerEx(HANDLE _timerHandle, TIMER_SET_INFORMATION_CLASS _timerSetInformationClass, PVOID _timerSetInformation, ULONG _timerSetInformationLength)
    {
        if (!ntSetTimerEx) ntSetTimerEx = win_::resolve_proc_address("NtSetTimerEx", 12);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, TIMER_SET_INFORMATION_CLASS, PVOID, ULONG)>(ntSetTimerEx)(_timerHandle, _timerSetInformationClass, _timerSetInformation, _timerSetInformationLength);
    }
    NTSTATUS NtsetTimerResolution(ULONG _desiredTime, BOOLEAN _setResolution, PULONG _actualTime)
    {
        if (!ntSetTimerResolution) ntSetTimerResolution = win_::resolve_proc_address("NtSetTimerResolution", 20);
        return reinterpret_cast<NTSTATUS(*)(ULONG, BOOLEAN, PULONG)>(ntSetTimerResolution)(_desiredTime, _setResolution, _actualTime);
    }
    NTSTATUS NtsetUuidSeed(PCHAR _seed)
    {
        if (!ntSetUuidSeed) ntSetUuidSeed = win_::resolve_proc_address("NtSetUuidSeed", 13);
        return reinterpret_cast<NTSTATUS(*)(PCHAR)>(ntSetUuidSeed)(_seed);
    }
    NTSTATUS NtsetValueKey(HANDLE _keyHandle, PCUNICODE_STRING _valueName, ULONG _titleIndex, ULONG _type, PVOID _data, ULONG _dataSize)
    {
        if (!ntSetValueKey) ntSetValueKey = win_::resolve_proc_address("NtSetValueKey", 13);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PCUNICODE_STRING, ULONG, ULONG, PVOID, ULONG)>(ntSetValueKey)(_keyHandle, _valueName, _titleIndex, _type, _data, _dataSize);
    }
    NTSTATUS NtsetVolumeInformationFile(HANDLE _fileHandle, PIO_STATUS_BLOCK _ioStatusBlock, PVOID _fsInformation, ULONG _length, FSINFOCLASS _fsInformationClass)
    {
        if (!ntSetVolumeInformationFile) ntSetVolumeInformationFile = win_::resolve_proc_address("NtSetVolumeInformationFile", 26);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PIO_STATUS_BLOCK, PVOID, ULONG, FSINFOCLASS)>(ntSetVolumeInformationFile)(_fileHandle, _ioStatusBlock, _fsInformation, _length, _fsInformationClass);
    }
    NTSTATUS NtsetWnfProcessNotificationEvent(HANDLE _notificationEvent)
    {
        if (!ntSetWnfProcessNotificationEvent) ntSetWnfProcessNotificationEvent = win_::resolve_proc_address("NtSetWnfProcessNotificationEvent", 32);
        return reinterpret_cast<NTSTATUS(*)(HANDLE)>(ntSetWnfProcessNotificationEvent)(_notificationEvent);
    }
    NTSTATUS NtshutdownSystem(SHUTDOWN_ACTION _action)
    {
        if (!ntShutdownSystem) ntShutdownSystem = win_::resolve_proc_address("NtShutdownSystem", 16);
        return reinterpret_cast<NTSTATUS(*)(SHUTDOWN_ACTION)>(ntShutdownSystem)(_action);
    }
    NTSTATUS NtshutdownWorkerFactory(HANDLE _workerFactoryHandle, LONG* _pendingWorkerCount)
    {
        if (!ntShutdownWorkerFactory) ntShutdownWorkerFactory = win_::resolve_proc_address("NtShutdownWorkerFactory", 23);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, LONG*)>(ntShutdownWorkerFactory)(_workerFactoryHandle, _pendingWorkerCount);
    }
    NTSTATUS NtsignalAndWaitForSingleObject(HANDLE _signalHandle, HANDLE _waitHandle, BOOLEAN _alertable, PLARGE_INTEGER _timeout)
    {
        if (!ntSignalAndWaitForSingleObject) ntSignalAndWaitForSingleObject = win_::resolve_proc_address("NtSignalAndWaitForSingleObject", 30);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE, BOOLEAN, PLARGE_INTEGER)>(ntSignalAndWaitForSingleObject)(_signalHandle, _waitHandle, _alertable, _timeout);
    }
    NTSTATUS NtsinglePhaseReject(HANDLE _enlistmentHandle, PLARGE_INTEGER _tmVirtualClock)
    {
        if (!ntSinglePhaseReject) ntSinglePhaseReject = win_::resolve_proc_address("NtSinglePhaseReject", 19);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PLARGE_INTEGER)>(ntSinglePhaseReject)(_enlistmentHandle, _tmVirtualClock);
    }
    NTSTATUS NtstartProfile(HANDLE _profileHandle)
    {
        if (!ntStartProfile) ntStartProfile = win_::resolve_proc_address("NtStartProfile", 14);
        return reinterpret_cast<NTSTATUS(*)(HANDLE)>(ntStartProfile)(_profileHandle);
    }
    NTSTATUS NtstopProfile(HANDLE _profileHandle)
    {
        if (!ntStopProfile) ntStopProfile = win_::resolve_proc_address("NtStopProfile", 13);
        return reinterpret_cast<NTSTATUS(*)(HANDLE)>(ntStopProfile)(_profileHandle);
    }
    NTSTATUS NtsubmitIoRing(HANDLE _ioRingHandle, ULONG _flags, ULONG _waitOperations, PLARGE_INTEGER _timeout)
    {
        if (!ntSubmitIoRing) ntSubmitIoRing = win_::resolve_proc_address("NtSubmitIoRing", 14);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONG, ULONG, PLARGE_INTEGER)>(ntSubmitIoRing)(_ioRingHandle, _flags, _waitOperations, _timeout);
    }
    NTSTATUS NtsubscribeWnfStateChange(PCWNF_STATE_NAME _stateName, WNF_CHANGE_STAMP _changeStamp, ULONG _eventMask, PULONG64 _subscriptionId)
    {
        if (!ntSubscribeWnfStateChange) ntSubscribeWnfStateChange = win_::resolve_proc_address("NtSubscribeWnfStateChange", 25);
        return reinterpret_cast<NTSTATUS(*)(PCWNF_STATE_NAME, WNF_CHANGE_STAMP, ULONG, PULONG64)>(ntSubscribeWnfStateChange)(_stateName, _changeStamp, _eventMask, _subscriptionId);
    }
    NTSTATUS NtsuspendProcess(HANDLE _processHandle)
    {
        if (!ntSuspendProcess) ntSuspendProcess = win_::resolve_proc_address("NtSuspendProcess", 16);
        return reinterpret_cast<NTSTATUS(*)(HANDLE)>(ntSuspendProcess)(_processHandle);
    }
    NTSTATUS NtsuspendThread(HANDLE _threadHandle, PULONG _previousSuspendCount)
    {
        if (!ntSuspendThread) ntSuspendThread = win_::resolve_proc_address("NtSuspendThread", 15);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PULONG)>(ntSuspendThread)(_threadHandle, _previousSuspendCount);
    }
    NTSTATUS NtsystemDebugControl(SYSDBG_COMMAND _command, PVOID _inputBuffer, ULONG _inputBufferLength, PVOID _outputBuffer, ULONG _outputBufferLength, PULONG _returnLength)
    {
        if (!ntSystemDebugControl) ntSystemDebugControl = win_::resolve_proc_address("NtSystemDebugControl", 20);
        return reinterpret_cast<NTSTATUS(*)(SYSDBG_COMMAND, PVOID, ULONG, PVOID, ULONG, PULONG)>(ntSystemDebugControl)(_command, _inputBuffer, _inputBufferLength, _outputBuffer, _outputBufferLength, _returnLength);
    }
    NTSTATUS NtterminateEnclave(PVOID _baseAddress, ULONG _flags)
    {
        if (!ntTerminateEnclave) ntTerminateEnclave = win_::resolve_proc_address("NtTerminateEnclave", 18);
        return reinterpret_cast<NTSTATUS(*)(PVOID, ULONG)>(ntTerminateEnclave)(_baseAddress, _flags);
    }
    NTSTATUS NtterminateJobObject(HANDLE _jobHandle, NTSTATUS _exitStatus)
    {
        if (!ntTerminateJobObject) ntTerminateJobObject = win_::resolve_proc_address("NtTerminateJobObject", 20);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, NTSTATUS)>(ntTerminateJobObject)(_jobHandle, _exitStatus);
    }
    NTSTATUS NtterminateProcess(HANDLE _processHandle, NTSTATUS _exitStatus)
    {
        if (!ntTerminateProcess) ntTerminateProcess = win_::resolve_proc_address("NtTerminateProcess", 18);
        if (!ntTerminateProcess) return 4;
        return reinterpret_cast<NTSTATUS(*)(HANDLE, NTSTATUS)>(ntTerminateProcess)(_processHandle, _exitStatus);
    }
    NTSTATUS NtterminateThread(HANDLE _threadHandle, NTSTATUS _exitStatus)
    {
        if (!ntTerminateThread) ntTerminateThread = win_::resolve_proc_address("NtTerminateThread", 17);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, NTSTATUS)>(ntTerminateThread)(_threadHandle, _exitStatus);
    }
    NTSTATUS NttestAlert()
    {
        if (!ntTestAlert) ntTestAlert = win_::resolve_proc_address("NtTestAlert", 11);
        return reinterpret_cast<NTSTATUS(*)()>(ntTestAlert)();
    }
    NTSTATUS NtthawRegistry()
    {
        if (!ntThawRegistry) ntThawRegistry = win_::resolve_proc_address("NtThawRegistry", 14);
        return reinterpret_cast<NTSTATUS(*)()>(ntThawRegistry)();
    }
    NTSTATUS NtthawTransactions()
    {
        if (!ntThawTransactions) ntThawTransactions = win_::resolve_proc_address("NtThawTransactions", 18);
        return reinterpret_cast<NTSTATUS(*)()>(ntThawTransactions)();
    }
    NTSTATUS NttraceControl(ETWTRACECONTROLCODE _functionCode, PVOID _inputBuffer, ULONG _inputBufferLength, PVOID _outputBuffer, ULONG _outputBufferLength, PULONG _returnLength)
    {
        if (!ntTraceControl) ntTraceControl = win_::resolve_proc_address("NtTraceControl", 14);
        return reinterpret_cast<NTSTATUS(*)(ETWTRACECONTROLCODE, PVOID, ULONG, PVOID, ULONG, PULONG)>(ntTraceControl)(_functionCode, _inputBuffer, _inputBufferLength, _outputBuffer, _outputBufferLength, _returnLength);
    }
    NTSTATUS NttraceEvent(HANDLE _traceHandle, ULONG _flags, ULONG _fieldSize, PVOID _fields)
    {
        if (!ntTraceEvent) ntTraceEvent = win_::resolve_proc_address("NtTraceEvent", 12);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONG, ULONG, PVOID)>(ntTraceEvent)(_traceHandle, _flags, _fieldSize, _fields);
    }
    NTSTATUS NttranslateFilePath(PFILE_PATH _inputFilePath, ULONG _outputType, PFILE_PATH _outputFilePath, PULONG _outputFilePathLength)
    {
        if (!ntTranslateFilePath) ntTranslateFilePath = win_::resolve_proc_address("NtTranslateFilePath", 19);
        return reinterpret_cast<NTSTATUS(*)(PFILE_PATH, ULONG, PFILE_PATH, PULONG)>(ntTranslateFilePath)(_inputFilePath, _outputType, _outputFilePath, _outputFilePathLength);
    }
    NTSTATUS NtumsThreadYield(PVOID _schedulerParam)
    {
        if (!ntUmsThreadYield) ntUmsThreadYield = win_::resolve_proc_address("NtUmsThreadYield", 16);
        return reinterpret_cast<NTSTATUS(*)(PVOID)>(ntUmsThreadYield)(_schedulerParam);
    }
    NTSTATUS NtunloadDriver(PCUNICODE_STRING _driverServiceName)
    {
        if (!ntUnloadDriver) ntUnloadDriver = win_::resolve_proc_address("NtUnloadDriver", 14);
        return reinterpret_cast<NTSTATUS(*)(PCUNICODE_STRING)>(ntUnloadDriver)(_driverServiceName);
    }
    NTSTATUS NtunloadKey(POBJECT_ATTRIBUTES _targetKey)
    {
        if (!ntUnloadKey) ntUnloadKey = win_::resolve_proc_address("NtUnloadKey", 11);
        return reinterpret_cast<NTSTATUS(*)(POBJECT_ATTRIBUTES)>(ntUnloadKey)(_targetKey);
    }
    NTSTATUS NtunloadKey2(POBJECT_ATTRIBUTES _targetKey, ULONG _flags)
    {
        if (!ntUnloadKey2) ntUnloadKey2 = win_::resolve_proc_address("NtUnloadKey2", 12);
        return reinterpret_cast<NTSTATUS(*)(POBJECT_ATTRIBUTES, ULONG)>(ntUnloadKey2)(_targetKey, _flags);
    }
    NTSTATUS NtunloadKeyEx(POBJECT_ATTRIBUTES _targetKey, HANDLE _event)
    {
        if (!ntUnloadKeyEx) ntUnloadKeyEx = win_::resolve_proc_address("NtUnloadKeyEx", 13);
        return reinterpret_cast<NTSTATUS(*)(POBJECT_ATTRIBUTES, HANDLE)>(ntUnloadKeyEx)(_targetKey, _event);
    }
    NTSTATUS NtunlockFile(HANDLE _fileHandle, PIO_STATUS_BLOCK _ioStatusBlock, PLARGE_INTEGER _byteOffset, PLARGE_INTEGER _length, ULONG _key)
    {
        if (!ntUnlockFile) ntUnlockFile = win_::resolve_proc_address("NtUnlockFile", 12);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PIO_STATUS_BLOCK, PLARGE_INTEGER, PLARGE_INTEGER, ULONG)>(ntUnlockFile)(_fileHandle, _ioStatusBlock, _byteOffset, _length, _key);
    }
    NTSTATUS NtunlockVirtualMemory(HANDLE _processHandle, PVOID* _baseAddress, PSIZE_T _regionSize, ULONG _mapType)
    {
        if (!ntUnlockVirtualMemory) ntUnlockVirtualMemory = win_::resolve_proc_address("NtUnlockVirtualMemory", 21);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PVOID*, PSIZE_T, ULONG)>(ntUnlockVirtualMemory)(_processHandle, _baseAddress, _regionSize, _mapType);
    }
    NTSTATUS NtunmapViewOfSection(HANDLE _processHandle, PVOID _baseAddress)
    {
        if (!ntUnmapViewOfSection) ntUnmapViewOfSection = win_::resolve_proc_address("NtUnmapViewOfSection", 20);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PVOID)>(ntUnmapViewOfSection)(_processHandle, _baseAddress);
    }
    NTSTATUS NtunmapViewOfSectionEx(HANDLE _processHandle, PVOID _baseAddress, ULONG _flags)
    {
        if (!ntUnmapViewOfSectionEx) ntUnmapViewOfSectionEx = win_::resolve_proc_address("NtUnmapViewOfSectionEx", 22);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PVOID, ULONG)>(ntUnmapViewOfSectionEx)(_processHandle, _baseAddress, _flags);
    }
    NTSTATUS NtunsubscribeWnfStateChange(PCWNF_STATE_NAME _stateName)
    {
        if (!ntUnsubscribeWnfStateChange) ntUnsubscribeWnfStateChange = win_::resolve_proc_address("NtUnsubscribeWnfStateChange", 27);
        return reinterpret_cast<NTSTATUS(*)(PCWNF_STATE_NAME)>(ntUnsubscribeWnfStateChange)(_stateName);
    }
    NTSTATUS NtupdateWnfStateData(PCWNF_STATE_NAME _stateName, void* _buffer, ULONG _length, PCWNF_TYPE_ID _typeId, PCSID _explicitScope, WNF_CHANGE_STAMP _matchingChangeStamp, LOGICAL _checkStamp)
    {
        if (!ntUpdateWnfStateData) ntUpdateWnfStateData = win_::resolve_proc_address("NtUpdateWnfStateData", 20);
        return reinterpret_cast<NTSTATUS(*)(PCWNF_STATE_NAME, void*, ULONG, PCWNF_TYPE_ID, PCSID, WNF_CHANGE_STAMP, LOGICAL)>(ntUpdateWnfStateData)(_stateName, _buffer, _length, _typeId, _explicitScope, _matchingChangeStamp, _checkStamp);
    }
    LOGICAL NtuserAllowForegroundActivation()
    {
        if (!ntUserAllowForegroundActivation) ntUserAllowForegroundActivation = win_::resolve_proc_address("NtUserAllowForegroundActivation", 31);
        return reinterpret_cast<LOGICAL(*)()>(ntUserAllowForegroundActivation)();
    }
    LOGICAL NtuserAllowSetForegroundWindow(ULONG _processId)
    {
        if (!ntUserAllowSetForegroundWindow) ntUserAllowSetForegroundWindow = win_::resolve_proc_address("NtUserAllowSetForegroundWindow", 30);
        return reinterpret_cast<LOGICAL(*)(ULONG)>(ntUserAllowSetForegroundWindow)(_processId);
    }
    ULONG NtuserArrangeIconicWindows(HWND _hwnd)
    {
        if (!ntUserArrangeIconicWindows) ntUserArrangeIconicWindows = win_::resolve_proc_address("NtUserArrangeIconicWindows", 26);
        return reinterpret_cast<ULONG(*)(HWND)>(ntUserArrangeIconicWindows)(_hwnd);
    }
    NTSTATUS NtuserAttachThreadInput(ULONG _idAttach, ULONG _idAttachTo, BOOL _attach)
    {
        if (!ntUserAttachThreadInput) ntUserAttachThreadInput = win_::resolve_proc_address("NtUserAttachThreadInput", 23);
        return reinterpret_cast<NTSTATUS(*)(ULONG, ULONG, BOOL)>(ntUserAttachThreadInput)(_idAttach, _idAttachTo, _attach);
    }
    HDWP NtuserBeginDeferWindowPos(ULONG _numWindowsHint)
    {
        if (!ntUserBeginDeferWindowPos) ntUserBeginDeferWindowPos = win_::resolve_proc_address("NtUserBeginDeferWindowPos", 25);
        return reinterpret_cast<HDWP(*)(ULONG)>(ntUserBeginDeferWindowPos)(_numWindowsHint);
    }
    HDC NtuserBeginPaint(HWND _windowHandle, LPPAINTSTRUCT _lpPaint)
    {
        if (!ntUserBeginPaint) ntUserBeginPaint = win_::resolve_proc_address("NtUserBeginPaint", 16);
        return reinterpret_cast<HDC(*)(HWND, LPPAINTSTRUCT)>(ntUserBeginPaint)(_windowHandle, _lpPaint);
    }
    BOOL NtuserBlockInput(BOOL _blockInput)
    {
        if (!ntUserBlockInput) ntUserBlockInput = win_::resolve_proc_address("NtUserBlockInput", 16);
        return reinterpret_cast<BOOL(*)(BOOL)>(ntUserBlockInput)(_blockInput);
    }
    BOOL NtuserBringWindowToTop(HWND _windowHandle)
    {
        if (!ntUserBringWindowToTop) ntUserBringWindowToTop = win_::resolve_proc_address("NtUserBringWindowToTop", 22);
        return reinterpret_cast<BOOL(*)(HWND)>(ntUserBringWindowToTop)(_windowHandle);
    }
    LOGICAL NtuserBroadcastImeShowStatusChange(HWND _ime, LOGICAL _show)
    {
        if (!ntUserBroadcastImeShowStatusChange) ntUserBroadcastImeShowStatusChange = win_::resolve_proc_address("NtUserBroadcastImeShowStatusChange", 34);
        return reinterpret_cast<LOGICAL(*)(HWND, LOGICAL)>(ntUserBroadcastImeShowStatusChange)(_ime, _show);
    }
    NTSTATUS NtuserBuildHwndList(HANDLE _desktopHandle, HWND _parentWindowHandle, BOOL _includeChildren, BOOL _excludeImmersive, ULONG _threadId, ULONG _hwndListInformationLength, PVOID _hwndListInformation, PULONG _returnLength)
    {
        if (!ntUserBuildHwndList) ntUserBuildHwndList = win_::resolve_proc_address("NtUserBuildHwndList", 19);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HWND, BOOL, BOOL, ULONG, ULONG, PVOID, PULONG)>(ntUserBuildHwndList)(_desktopHandle, _parentWindowHandle, _includeChildren, _excludeImmersive, _threadId, _hwndListInformationLength, _hwndListInformation, _returnLength);
    }
    NTSTATUS NtuserBuildNameList(HWINSTA _windowStationHandle, ULONG _nameListInformationLength, PVOID _nameListInformation, PULONG _returnLength)
    {
        if (!ntUserBuildNameList) ntUserBuildNameList = win_::resolve_proc_address("NtUserBuildNameList", 19);
        return reinterpret_cast<NTSTATUS(*)(HWINSTA, ULONG, PVOID, PULONG)>(ntUserBuildNameList)(_windowStationHandle, _nameListInformationLength, _nameListInformation, _returnLength);
    }
    NTSTATUS NtuserBuildPropList(HWINSTA _windowStationHandle, ULONG _propListInformationLength, PVOID _propListInformation, PULONG _returnLength)
    {
        if (!ntUserBuildPropList) ntUserBuildPropList = win_::resolve_proc_address("NtUserBuildPropList", 19);
        return reinterpret_cast<NTSTATUS(*)(HWINSTA, ULONG, PVOID, PULONG)>(ntUserBuildPropList)(_windowStationHandle, _propListInformationLength, _propListInformation, _returnLength);
    }
    BOOL NtuserCalculatePopupWindowPosition(POINT* _anchorPoint, SIZE* _windowSize, ULONG _flags, RECT* _excludeRect, RECT* _popupWindowPosition)
    {
        if (!ntUserCalculatePopupWindowPosition) ntUserCalculatePopupWindowPosition = win_::resolve_proc_address("NtUserCalculatePopupWindowPosition", 34);
        return reinterpret_cast<BOOL(*)(POINT*, SIZE*, ULONG, RECT*, RECT*)>(ntUserCalculatePopupWindowPosition)(_anchorPoint, _windowSize, _flags, _excludeRect, _popupWindowPosition);
    }
    ULONG_PTR NtuserCallHwnd(HWND _hwnd, ULONG _xpfnProc)
    {
        if (!ntUserCallHwnd) ntUserCallHwnd = win_::resolve_proc_address("NtUserCallHwnd", 14);
        return reinterpret_cast<ULONG_PTR(*)(HWND, ULONG)>(ntUserCallHwnd)(_hwnd, _xpfnProc);
    }
    ULONG_PTR NtuserCallHwndLock(HWND _hwnd, ULONG _xpfnProc)
    {
        if (!ntUserCallHwndLock) ntUserCallHwndLock = win_::resolve_proc_address("NtUserCallHwndLock", 18);
        return reinterpret_cast<ULONG_PTR(*)(HWND, ULONG)>(ntUserCallHwndLock)(_hwnd, _xpfnProc);
    }
    ULONG_PTR NtuserCallHwndLockSafe(HWND _hwnd, ULONG _xpfnProc)
    {
        if (!ntUserCallHwndLockSafe) ntUserCallHwndLockSafe = win_::resolve_proc_address("NtUserCallHwndLockSafe", 22);
        return reinterpret_cast<ULONG_PTR(*)(HWND, ULONG)>(ntUserCallHwndLockSafe)(_hwnd, _xpfnProc);
    }
    ULONG_PTR NtuserCallHwndOpt(HWND _hwnd, ULONG _xpfnProc)
    {
        if (!ntUserCallHwndOpt) ntUserCallHwndOpt = win_::resolve_proc_address("NtUserCallHwndOpt", 17);
        return reinterpret_cast<ULONG_PTR(*)(HWND, ULONG)>(ntUserCallHwndOpt)(_hwnd, _xpfnProc);
    }
    ULONG_PTR NtuserCallHwndParam(HWND _hwnd, ULONG_PTR _param, ULONG _xpfnProc)
    {
        if (!ntUserCallHwndParam) ntUserCallHwndParam = win_::resolve_proc_address("NtUserCallHwndParam", 19);
        return reinterpret_cast<ULONG_PTR(*)(HWND, ULONG_PTR, ULONG)>(ntUserCallHwndParam)(_hwnd, _param, _xpfnProc);
    }
    ULONG_PTR NtuserCallHwndParamLock(HWND _hwnd, ULONG_PTR _param, ULONG _xpfnProc)
    {
        if (!ntUserCallHwndParamLock) ntUserCallHwndParamLock = win_::resolve_proc_address("NtUserCallHwndParamLock", 23);
        return reinterpret_cast<ULONG_PTR(*)(HWND, ULONG_PTR, ULONG)>(ntUserCallHwndParamLock)(_hwnd, _param, _xpfnProc);
    }
    ULONG_PTR NtuserCallHwndParamLockSafe(HWND _hwnd, ULONG_PTR _param, ULONG _xpfnProc)
    {
        if (!ntUserCallHwndParamLockSafe) ntUserCallHwndParamLockSafe = win_::resolve_proc_address("NtUserCallHwndParamLockSafe", 27);
        return reinterpret_cast<ULONG_PTR(*)(HWND, ULONG_PTR, ULONG)>(ntUserCallHwndParamLockSafe)(_hwnd, _param, _xpfnProc);
    }
    ULONG_PTR NtuserCallHwndSafe(HWND _hwnd, ULONG _xpfnProc)
    {
        if (!ntUserCallHwndSafe) ntUserCallHwndSafe = win_::resolve_proc_address("NtUserCallHwndSafe", 18);
        return reinterpret_cast<ULONG_PTR(*)(HWND, ULONG)>(ntUserCallHwndSafe)(_hwnd, _xpfnProc);
    }
    ULONG_PTR NtuserCallNoParam(ULONG _xpfnProc)
    {
        if (!ntUserCallNoParam) ntUserCallNoParam = win_::resolve_proc_address("NtUserCallNoParam", 17);
        return reinterpret_cast<ULONG_PTR(*)(ULONG)>(ntUserCallNoParam)(_xpfnProc);
    }
    ULONG_PTR NtuserCallOneParam(ULONG_PTR _param, ULONG _xpfnProc)
    {
        if (!ntUserCallOneParam) ntUserCallOneParam = win_::resolve_proc_address("NtUserCallOneParam", 18);
        return reinterpret_cast<ULONG_PTR(*)(ULONG_PTR, ULONG)>(ntUserCallOneParam)(_param, _xpfnProc);
    }
    ULONG_PTR NtuserCallTwoParam(ULONG_PTR _param1, ULONG_PTR _param2, ULONG _xpfnProc)
    {
        if (!ntUserCallTwoParam) ntUserCallTwoParam = win_::resolve_proc_address("NtUserCallTwoParam", 18);
        return reinterpret_cast<ULONG_PTR(*)(ULONG_PTR, ULONG_PTR, ULONG)>(ntUserCallTwoParam)(_param1, _param2, _xpfnProc);
    }
    BOOL NtuserCanCurrentThreadChangeForeground()
    {
        if (!ntUserCanCurrentThreadChangeForeground) ntUserCanCurrentThreadChangeForeground = win_::resolve_proc_address("NtUserCanCurrentThreadChangeForeground", 38);
        return reinterpret_cast<BOOL(*)()>(ntUserCanCurrentThreadChangeForeground)();
    }
    LOGICAL NtuserCancelQueueEventCompletionPacket()
    {
        if (!ntUserCancelQueueEventCompletionPacket) ntUserCancelQueueEventCompletionPacket = win_::resolve_proc_address("NtUserCancelQueueEventCompletionPacket", 38);
        return reinterpret_cast<LOGICAL(*)()>(ntUserCancelQueueEventCompletionPacket)();
    }
    LOGICAL NtuserChangeWindowMessageFilter(ULONG _message, ULONG _flag)
    {
        if (!ntUserChangeWindowMessageFilter) ntUserChangeWindowMessageFilter = win_::resolve_proc_address("NtUserChangeWindowMessageFilter", 31);
        return reinterpret_cast<LOGICAL(*)(ULONG, ULONG)>(ntUserChangeWindowMessageFilter)(_message, _flag);
    }
    NTSTATUS NtuserCheckAccessForIntegrityLevel(ULONG _processIdFirst, ULONG _processIdSecond, PBOOLEAN _grantedAccess)
    {
        if (!ntUserCheckAccessForIntegrityLevel) ntUserCheckAccessForIntegrityLevel = win_::resolve_proc_address("NtUserCheckAccessForIntegrityLevel", 34);
        return reinterpret_cast<NTSTATUS(*)(ULONG, ULONG, PBOOLEAN)>(ntUserCheckAccessForIntegrityLevel)(_processIdFirst, _processIdSecond, _grantedAccess);
    }
    LOGICAL NtuserCheckImeShowStatusInThread(HWND _ime)
    {
        if (!ntUserCheckImeShowStatusInThread) ntUserCheckImeShowStatusInThread = win_::resolve_proc_address("NtUserCheckImeShowStatusInThread", 32);
        return reinterpret_cast<LOGICAL(*)(HWND)>(ntUserCheckImeShowStatusInThread)(_ime);
    }
    NTSTATUS NtuserCheckProcessForClipboardAccess(ULONG _processId, PULONG _grantedAccess)
    {
        if (!ntUserCheckProcessForClipboardAccess) ntUserCheckProcessForClipboardAccess = win_::resolve_proc_address("NtUserCheckProcessForClipboardAccess", 36);
        return reinterpret_cast<NTSTATUS(*)(ULONG, PULONG)>(ntUserCheckProcessForClipboardAccess)(_processId, _grantedAccess);
    }
    HWND NtuserChildWindowFromPointEx(HWND _windowHandle, POINT _pt, ULONG _flags)
    {
        if (!ntUserChildWindowFromPointEx) ntUserChildWindowFromPointEx = win_::resolve_proc_address("NtUserChildWindowFromPointEx", 28);
        return reinterpret_cast<HWND(*)(HWND, POINT, ULONG)>(ntUserChildWindowFromPointEx)(_windowHandle, _pt, _flags);
    }
    NTSTATUS NtuserCitSetInfo(ULONG_PTR _infoFlags, ULONG_PTR _info)
    {
        if (!ntUserCitSetInfo) ntUserCitSetInfo = win_::resolve_proc_address("NtUserCitSetInfo", 16);
        return reinterpret_cast<NTSTATUS(*)(ULONG_PTR, ULONG_PTR)>(ntUserCitSetInfo)(_infoFlags, _info);
    }
    LOGICAL NtuserClearWakeMask()
    {
        if (!ntUserClearWakeMask) ntUserClearWakeMask = win_::resolve_proc_address("NtUserClearWakeMask", 19);
        return reinterpret_cast<LOGICAL(*)()>(ntUserClearWakeMask)();
    }
    LOGICAL NtuserClearWindowState(HWND _hwnd, ULONG _flag)
    {
        if (!ntUserClearWindowState) ntUserClearWindowState = win_::resolve_proc_address("NtUserClearWindowState", 22);
        return reinterpret_cast<LOGICAL(*)(HWND, ULONG)>(ntUserClearWindowState)(_hwnd, _flag);
    }
    BOOL NtuserClipCursor(RECT* _lpRect)
    {
        if (!ntUserClipCursor) ntUserClipCursor = win_::resolve_proc_address("NtUserClipCursor", 16);
        return reinterpret_cast<BOOL(*)(RECT*)>(ntUserClipCursor)(_lpRect);
    }
    BOOL NtuserCloseDesktop(HDESK _desktopHandle)
    {
        if (!ntUserCloseDesktop) ntUserCloseDesktop = win_::resolve_proc_address("NtUserCloseDesktop", 18);
        return reinterpret_cast<BOOL(*)(HDESK)>(ntUserCloseDesktop)(_desktopHandle);
    }
    BOOL NtuserCloseWindowStation(HWINSTA _windowStationHandle)
    {
        if (!ntUserCloseWindowStation) ntUserCloseWindowStation = win_::resolve_proc_address("NtUserCloseWindowStation", 24);
        return reinterpret_cast<BOOL(*)(HWINSTA)>(ntUserCloseWindowStation)(_windowStationHandle);
    }
    NTSTATUS NtuserConsoleControl(CONSOLECONTROL _command, PVOID _consoleInformation, ULONG _consoleInformationLength)
    {
        if (!ntUserConsoleControl) ntUserConsoleControl = win_::resolve_proc_address("NtUserConsoleControl", 20);
        return reinterpret_cast<NTSTATUS(*)(CONSOLECONTROL, PVOID, ULONG)>(ntUserConsoleControl)(_command, _consoleInformation, _consoleInformationLength);
    }
    LONG NtuserCopyAcceleratorTable(HACCEL _hAccelSrc, LPACCEL _lpAccelDst, LONG _cAccelEntries)
    {
        if (!ntUserCopyAcceleratorTable) ntUserCopyAcceleratorTable = win_::resolve_proc_address("NtUserCopyAcceleratorTable", 26);
        return reinterpret_cast<LONG(*)(HACCEL, LPACCEL, LONG)>(ntUserCopyAcceleratorTable)(_hAccelSrc, _lpAccelDst, _cAccelEntries);
    }
    HACCEL NtuserCreateAcceleratorTable(LPACCEL _paccel, LONG _cAccel)
    {
        if (!ntUserCreateAcceleratorTable) ntUserCreateAcceleratorTable = win_::resolve_proc_address("NtUserCreateAcceleratorTable", 28);
        return reinterpret_cast<HACCEL(*)(LPACCEL, LONG)>(ntUserCreateAcceleratorTable)(_paccel, _cAccel);
    }
    HMENU NtuserCreateMenu()
    {
        if (!ntUserCreateMenu) ntUserCreateMenu = win_::resolve_proc_address("NtUserCreateMenu", 16);
        return reinterpret_cast<HMENU(*)()>(ntUserCreateMenu)();
    }
    HMENU NtuserCreatePopupMenu()
    {
        if (!ntUserCreatePopupMenu) ntUserCreatePopupMenu = win_::resolve_proc_address("NtUserCreatePopupMenu", 21);
        return reinterpret_cast<HMENU(*)()>(ntUserCreatePopupMenu)();
    }
    LOGICAL NtuserCreateSystemThreads()
    {
        if (!ntUserCreateSystemThreads) ntUserCreateSystemThreads = win_::resolve_proc_address("NtUserCreateSystemThreads", 25);
        return reinterpret_cast<LOGICAL(*)()>(ntUserCreateSystemThreads)();
    }
    NTSTATUS NtuserCreateWindowStation(POBJECT_ATTRIBUTES _objectAttributes, ACCESS_MASK _desiredAccess, HANDLE _keyboardLayoutHandle, PVOID _keyboardLayoutOffset, PVOID _nlsTableOffset, PVOID _keyboardDescriptor, PCUNICODE_STRING _languageIdString, ULONG _keyboardLocale)
    {
        if (!ntUserCreateWindowStation) ntUserCreateWindowStation = win_::resolve_proc_address("NtUserCreateWindowStation", 25);
        return reinterpret_cast<NTSTATUS(*)(POBJECT_ATTRIBUTES, ACCESS_MASK, HANDLE, PVOID, PVOID, PVOID, PCUNICODE_STRING, ULONG)>(ntUserCreateWindowStation)(_objectAttributes, _desiredAccess, _keyboardLayoutHandle, _keyboardLayoutOffset, _nlsTableOffset, _keyboardDescriptor, _languageIdString, _keyboardLocale);
    }
    LOGICAL NtuserCsDdeUninitialize(HANDLE _hInst)
    {
        if (!ntUserCsDdeUninitialize) ntUserCsDdeUninitialize = win_::resolve_proc_address("NtUserCsDdeUninitialize", 23);
        return reinterpret_cast<LOGICAL(*)(HANDLE)>(ntUserCsDdeUninitialize)(_hInst);
    }
    ULONG_PTR NtuserDWPGetEnabledPopupOffset(HWND _hwnd)
    {
        if (!ntUserDWP_GetEnabledPopupOffset) ntUserDWP_GetEnabledPopupOffset = win_::resolve_proc_address("NtUserDWP_GetEnabledPopupOffset", 31);
        return reinterpret_cast<ULONG_PTR(*)(HWND)>(ntUserDWP_GetEnabledPopupOffset)(_hwnd);
    }
    ULONG_PTR NtuserDeferredDesktopRotation()
    {
        if (!ntUserDeferredDesktopRotation) ntUserDeferredDesktopRotation = win_::resolve_proc_address("NtUserDeferredDesktopRotation", 29);
        return reinterpret_cast<ULONG_PTR(*)()>(ntUserDeferredDesktopRotation)();
    }
    BOOL NtuserDeleteMenu(HMENU _menuHandle, ULONG _position, ULONG _flags)
    {
        if (!ntUserDeleteMenu) ntUserDeleteMenu = win_::resolve_proc_address("NtUserDeleteMenu", 16);
        return reinterpret_cast<BOOL(*)(HMENU, ULONG, ULONG)>(ntUserDeleteMenu)(_menuHandle, _position, _flags);
    }
    LOGICAL NtuserDeregisterShellHookWindow(HWND _hwnd)
    {
        if (!ntUserDeregisterShellHookWindow) ntUserDeregisterShellHookWindow = win_::resolve_proc_address("NtUserDeregisterShellHookWindow", 31);
        return reinterpret_cast<LOGICAL(*)(HWND)>(ntUserDeregisterShellHookWindow)(_hwnd);
    }
    LOGICAL NtuserDestroyCaret()
    {
        if (!ntUserDestroyCaret) ntUserDestroyCaret = win_::resolve_proc_address("NtUserDestroyCaret", 18);
        return reinterpret_cast<LOGICAL(*)()>(ntUserDestroyCaret)();
    }
    BOOL NtuserDestroyMenu(HMENU _menuHandle)
    {
        if (!ntUserDestroyMenu) ntUserDestroyMenu = win_::resolve_proc_address("NtUserDestroyMenu", 17);
        return reinterpret_cast<BOOL(*)(HMENU)>(ntUserDestroyMenu)(_menuHandle);
    }
    BOOL NtuserDestroyWindow(HWND _windowHandle)
    {
        if (!ntUserDestroyWindow) ntUserDestroyWindow = win_::resolve_proc_address("NtUserDestroyWindow", 19);
        return reinterpret_cast<BOOL(*)(HWND)>(ntUserDestroyWindow)(_windowHandle);
    }
    BOOL NtuserDisableProcessWindowFiltering()
    {
        if (!ntUserDisableProcessWindowFiltering) ntUserDisableProcessWindowFiltering = win_::resolve_proc_address("NtUserDisableProcessWindowFiltering", 35);
        return reinterpret_cast<BOOL(*)()>(ntUserDisableProcessWindowFiltering)();
    }
    LOGICAL NtuserDisableProcessWindowsGhosting()
    {
        if (!ntUserDisableProcessWindowsGhosting) ntUserDisableProcessWindowsGhosting = win_::resolve_proc_address("NtUserDisableProcessWindowsGhosting", 35);
        return reinterpret_cast<LOGICAL(*)()>(ntUserDisableProcessWindowsGhosting)();
    }
    LOGICAL NtuserDoInitMessagePumpHook()
    {
        if (!ntUserDoInitMessagePumpHook) ntUserDoInitMessagePumpHook = win_::resolve_proc_address("NtUserDoInitMessagePumpHook", 27);
        return reinterpret_cast<LOGICAL(*)()>(ntUserDoInitMessagePumpHook)();
    }
    LOGICAL NtuserDoUninitMessagePumpHook()
    {
        if (!ntUserDoUninitMessagePumpHook) ntUserDoUninitMessagePumpHook = win_::resolve_proc_address("NtUserDoUninitMessagePumpHook", 29);
        return reinterpret_cast<LOGICAL(*)()>(ntUserDoUninitMessagePumpHook)();
    }
    BOOL NtuserDragDetect(HWND _windowHandle, POINT _pt)
    {
        if (!ntUserDragDetect) ntUserDragDetect = win_::resolve_proc_address("NtUserDragDetect", 16);
        return reinterpret_cast<BOOL(*)(HWND, POINT)>(ntUserDragDetect)(_windowHandle, _pt);
    }
    ULONG NtuserDragObject(HWND _windowHandleParent, HWND _windowHandleFrom, ULONG _fmt, ULONG_PTR _data, HCURSOR _hcur)
    {
        if (!ntUserDragObject) ntUserDragObject = win_::resolve_proc_address("NtUserDragObject", 16);
        return reinterpret_cast<ULONG(*)(HWND, HWND, ULONG, ULONG_PTR, HCURSOR)>(ntUserDragObject)(_windowHandleParent, _windowHandleFrom, _fmt, _data, _hcur);
    }
    LOGICAL NtuserDrainThreadCoreMessagingCompletions()
    {
        if (!ntUserDrainThreadCoreMessagingCompletions) ntUserDrainThreadCoreMessagingCompletions = win_::resolve_proc_address("NtUserDrainThreadCoreMessagingCompletions", 41);
        return reinterpret_cast<LOGICAL(*)()>(ntUserDrainThreadCoreMessagingCompletions)();
    }
    BOOL NtuserDrawAnimatedRects(HWND _windowHandle, int _idAni, RECT* _lprcFrom, RECT* _lprcTo)
    {
        if (!ntUserDrawAnimatedRects) ntUserDrawAnimatedRects = win_::resolve_proc_address("NtUserDrawAnimatedRects", 23);
        return reinterpret_cast<BOOL(*)(HWND, int, RECT*, RECT*)>(ntUserDrawAnimatedRects)(_windowHandle, _idAni, _lprcFrom, _lprcTo);
    }
    LOGICAL NtuserDrawMenuBar(HWND _hwnd)
    {
        if (!ntUserDrawMenuBar) ntUserDrawMenuBar = win_::resolve_proc_address("NtUserDrawMenuBar", 17);
        return reinterpret_cast<LOGICAL(*)(HWND)>(ntUserDrawMenuBar)(_hwnd);
    }
    ULONG_PTR NtuserDwmLockScreenUpdates(LOGICAL _lockUpdates)
    {
        if (!ntUserDwmLockScreenUpdates) ntUserDwmLockScreenUpdates = win_::resolve_proc_address("NtUserDwmLockScreenUpdates", 26);
        return reinterpret_cast<ULONG_PTR(*)(LOGICAL)>(ntUserDwmLockScreenUpdates)(_lockUpdates);
    }
    LOGICAL NtuserEnableModernAppWindowKeyboardIntercept(HWND _hwnd, LOGICAL _enable)
    {
        if (!ntUserEnableModernAppWindowKeyboardIntercept) ntUserEnableModernAppWindowKeyboardIntercept = win_::resolve_proc_address("NtUserEnableModernAppWindowKeyboardIntercept", 44);
        return reinterpret_cast<LOGICAL(*)(HWND, LOGICAL)>(ntUserEnableModernAppWindowKeyboardIntercept)(_hwnd, _enable);
    }
    LOGICAL NtuserEnableMouseInPointerForThread()
    {
        if (!ntUserEnableMouseInPointerForThread) ntUserEnableMouseInPointerForThread = win_::resolve_proc_address("NtUserEnableMouseInPointerForThread", 35);
        return reinterpret_cast<LOGICAL(*)()>(ntUserEnableMouseInPointerForThread)();
    }
    LOGICAL NtuserEnablePerMonitorMenuScaling()
    {
        if (!ntUserEnablePerMonitorMenuScaling) ntUserEnablePerMonitorMenuScaling = win_::resolve_proc_address("NtUserEnablePerMonitorMenuScaling", 33);
        return reinterpret_cast<LOGICAL(*)()>(ntUserEnablePerMonitorMenuScaling)();
    }
    ULONG_PTR NtuserEnableSessionForMMCSS(LOGICAL _enable)
    {
        if (!ntUserEnableSessionForMMCSS) ntUserEnableSessionForMMCSS = win_::resolve_proc_address("NtUserEnableSessionForMMCSS", 27);
        return reinterpret_cast<ULONG_PTR(*)(LOGICAL)>(ntUserEnableSessionForMMCSS)(_enable);
    }
    LOGICAL NtuserEnableShellWindowManagementBehavior(ULONG_PTR _param1, ULONG_PTR _param2)
    {
        if (!ntUserEnableShellWindowManagementBehavior) ntUserEnableShellWindowManagementBehavior = win_::resolve_proc_address("NtUserEnableShellWindowManagementBehavior", 41);
        return reinterpret_cast<LOGICAL(*)(ULONG_PTR, ULONG_PTR)>(ntUserEnableShellWindowManagementBehavior)(_param1, _param2);
    }
    LOGICAL NtuserEnableWindow(HWND _hwnd, LOGICAL _enable)
    {
        if (!ntUserEnableWindow) ntUserEnableWindow = win_::resolve_proc_address("NtUserEnableWindow", 18);
        return reinterpret_cast<LOGICAL(*)(HWND, LOGICAL)>(ntUserEnableWindow)(_hwnd, _enable);
    }
    BOOL NtuserEndMenu()
    {
        if (!ntUserEndMenu) ntUserEndMenu = win_::resolve_proc_address("NtUserEndMenu", 13);
        return reinterpret_cast<BOOL(*)()>(ntUserEndMenu)();
    }
    BOOL NtuserEndPaint(HWND _windowHandle, PAINTSTRUCT* _lpPaint)
    {
        if (!ntUserEndPaint) ntUserEndPaint = win_::resolve_proc_address("NtUserEndPaint", 14);
        return reinterpret_cast<BOOL(*)(HWND, PAINTSTRUCT*)>(ntUserEndPaint)(_windowHandle, _lpPaint);
    }
    LOGICAL NtuserEnsureDpiDepSysMetCacheForPlateau(ULONG _dpi)
    {
        if (!ntUserEnsureDpiDepSysMetCacheForPlateau) ntUserEnsureDpiDepSysMetCacheForPlateau = win_::resolve_proc_address("NtUserEnsureDpiDepSysMetCacheForPlateau", 39);
        return reinterpret_cast<LOGICAL(*)(ULONG)>(ntUserEnsureDpiDepSysMetCacheForPlateau)(_dpi);
    }
    ULONG NtuserEnumClipboardFormats(ULONG _format)
    {
        if (!ntUserEnumClipboardFormats) ntUserEnumClipboardFormats = win_::resolve_proc_address("NtUserEnumClipboardFormats", 26);
        return reinterpret_cast<ULONG(*)(ULONG)>(ntUserEnumClipboardFormats)(_format);
    }
    BOOL NtuserEnumDisplayMonitors(HDC _hdc, LPCRECT _lprcClip, MONITORENUMPROC _lpfnEnum, LPARAM _dwData)
    {
        if (!ntUserEnumDisplayMonitors) ntUserEnumDisplayMonitors = win_::resolve_proc_address("NtUserEnumDisplayMonitors", 25);
        return reinterpret_cast<BOOL(*)(HDC, LPCRECT, MONITORENUMPROC, LPARAM)>(ntUserEnumDisplayMonitors)(_hdc, _lprcClip, _lpfnEnum, _dwData);
    }
    HRGN NtuserExcludeUpdateRgn(HDC _hDC, HWND _windowHandle)
    {
        if (!ntUserExcludeUpdateRgn) ntUserExcludeUpdateRgn = win_::resolve_proc_address("NtUserExcludeUpdateRgn", 22);
        return reinterpret_cast<HRGN(*)(HDC, HWND)>(ntUserExcludeUpdateRgn)(_hDC, _windowHandle);
    }
    HWND NtuserFindWindowEx(HWND _hwndParent, HWND _hwndChild, PCUNICODE_STRING _className, PCUNICODE_STRING _windowName, ULONG _type)
    {
        if (!ntUserFindWindowEx) ntUserFindWindowEx = win_::resolve_proc_address("NtUserFindWindowEx", 18);
        return reinterpret_cast<HWND(*)(HWND, HWND, PCUNICODE_STRING, PCUNICODE_STRING, ULONG)>(ntUserFindWindowEx)(_hwndParent, _hwndChild, _className, _windowName, _type);
    }
    BOOL NtuserFlashWindowEx(PFLASHWINFO _pfwi)
    {
        if (!ntUserFlashWindowEx) ntUserFlashWindowEx = win_::resolve_proc_address("NtUserFlashWindowEx", 19);
        return reinterpret_cast<BOOL(*)(PFLASHWINFO)>(ntUserFlashWindowEx)(_pfwi);
    }
    UINT_PTR NtuserForceEnableNumpadTranslation(LOGICAL _forceNumlockTranslation)
    {
        if (!ntUserForceEnableNumpadTranslation) ntUserForceEnableNumpadTranslation = win_::resolve_proc_address("NtUserForceEnableNumpadTranslation", 34);
        return reinterpret_cast<UINT_PTR(*)(LOGICAL)>(ntUserForceEnableNumpadTranslation)(_forceNumlockTranslation);
    }
    HWND NtuserGetAncestor(HWND _windowHandle, ULONG _gaFlags)
    {
        if (!ntUserGetAncestor) ntUserGetAncestor = win_::resolve_proc_address("NtUserGetAncestor", 17);
        return reinterpret_cast<HWND(*)(HWND, ULONG)>(ntUserGetAncestor)(_windowHandle, _gaFlags);
    }
    ULONG NtuserGetCaretBlinkTime()
    {
        if (!ntUserGetCaretBlinkTime) ntUserGetCaretBlinkTime = win_::resolve_proc_address("NtUserGetCaretBlinkTime", 23);
        return reinterpret_cast<ULONG(*)()>(ntUserGetCaretBlinkTime)();
    }
    BOOL NtuserGetCaretPos(LPPOINT _lpPoint)
    {
        if (!ntUserGetCaretPos) ntUserGetCaretPos = win_::resolve_proc_address("NtUserGetCaretPos", 17);
        return reinterpret_cast<BOOL(*)(LPPOINT)>(ntUserGetCaretPos)(_lpPoint);
    }
    HCURSOR NtuserGetClassIcoCur(HWND _hwnd, ULONG _index)
    {
        if (!ntUserGetClassIcoCur) ntUserGetClassIcoCur = win_::resolve_proc_address("NtUserGetClassIcoCur", 20);
        return reinterpret_cast<HCURSOR(*)(HWND, ULONG)>(ntUserGetClassIcoCur)(_hwnd, _index);
    }
    ULONG NtuserGetClassName(HWND _windowHandle, BOOL _realClassName, PUNICODE_STRING _className)
    {
        if (!ntUserGetClassName) ntUserGetClassName = win_::resolve_proc_address("NtUserGetClassName", 18);
        return reinterpret_cast<ULONG(*)(HWND, BOOL, PUNICODE_STRING)>(ntUserGetClassName)(_windowHandle, _realClassName, _className);
    }
    BOOL NtuserGetClipCursor(LPRECT _lpRect)
    {
        if (!ntUserGetClipCursor) ntUserGetClipCursor = win_::resolve_proc_address("NtUserGetClipCursor", 19);
        return reinterpret_cast<BOOL(*)(LPRECT)>(ntUserGetClipCursor)(_lpRect);
    }
    BOOL NtuserGetComboBoxInfo(HWND _windowHandleCombo, PCOMBOBOXINFO _pcbi)
    {
        if (!ntUserGetComboBoxInfo) ntUserGetComboBoxInfo = win_::resolve_proc_address("NtUserGetComboBoxInfo", 21);
        return reinterpret_cast<BOOL(*)(HWND, PCOMBOBOXINFO)>(ntUserGetComboBoxInfo)(_windowHandleCombo, _pcbi);
    }
    BOOL NtuserGetCurrentInputMessageSource(INPUT_MESSAGE_SOURCE* _inputMessageSource)
    {
        if (!ntUserGetCurrentInputMessageSource) ntUserGetCurrentInputMessageSource = win_::resolve_proc_address("NtUserGetCurrentInputMessageSource", 34);
        return reinterpret_cast<BOOL(*)(INPUT_MESSAGE_SOURCE*)>(ntUserGetCurrentInputMessageSource)(_inputMessageSource);
    }
    HCURSOR NtuserGetCursor()
    {
        if (!ntUserGetCursor) ntUserGetCursor = win_::resolve_proc_address("NtUserGetCursor", 15);
        return reinterpret_cast<HCURSOR(*)()>(ntUserGetCursor)();
    }
    BOOL NtuserGetCursorInfo(PCURSORINFO _pci)
    {
        if (!ntUserGetCursorInfo) ntUserGetCursorInfo = win_::resolve_proc_address("NtUserGetCursorInfo", 19);
        return reinterpret_cast<BOOL(*)(PCURSORINFO)>(ntUserGetCursorInfo)(_pci);
    }
    LOGICAL NtuserGetCursorPos(PPOINT _point, ULONG _cursorPosType)
    {
        if (!ntUserGetCursorPos) ntUserGetCursorPos = win_::resolve_proc_address("NtUserGetCursorPos", 18);
        return reinterpret_cast<LOGICAL(*)(PPOINT, ULONG)>(ntUserGetCursorPos)(_point, _cursorPosType);
    }
    HDC NtuserGetDCEx(HWND _windowHandle, HRGN _hrgnClip, ULONG _flags)
    {
        if (!ntUserGetDCEx) ntUserGetDCEx = win_::resolve_proc_address("NtUserGetDCEx", 13);
        return reinterpret_cast<HDC(*)(HWND, HRGN, ULONG)>(ntUserGetDCEx)(_windowHandle, _hrgnClip, _flags);
    }
    ULONG NtuserGetDeviceChangeInfo()
    {
        if (!ntUserGetDeviceChangeInfo) ntUserGetDeviceChangeInfo = win_::resolve_proc_address("NtUserGetDeviceChangeInfo", 25);
        return reinterpret_cast<ULONG(*)()>(ntUserGetDeviceChangeInfo)();
    }
    BOOL NtuserGetDisplayAutoRotationPreferences(ORIENTATION_PREFERENCE* _pOrientation)
    {
        if (!ntUserGetDisplayAutoRotationPreferences) ntUserGetDisplayAutoRotationPreferences = win_::resolve_proc_address("NtUserGetDisplayAutoRotationPreferences", 39);
        return reinterpret_cast<BOOL(*)(ORIENTATION_PREFERENCE*)>(ntUserGetDisplayAutoRotationPreferences)(_pOrientation);
    }
    ULONG NtuserGetDoubleClickTime()
    {
        if (!ntUserGetDoubleClickTime) ntUserGetDoubleClickTime = win_::resolve_proc_address("NtUserGetDoubleClickTime", 24);
        return reinterpret_cast<ULONG(*)()>(ntUserGetDoubleClickTime)();
    }
    HWND NtuserGetForegroundWindow()
    {
        if (!ntUserGetForegroundWindow) ntUserGetForegroundWindow = win_::resolve_proc_address("NtUserGetForegroundWindow", 25);
        return reinterpret_cast<HWND(*)()>(ntUserGetForegroundWindow)();
    }
    BOOL NtuserGetGUIThreadInfo(ULONG _idThread, PGUITHREADINFO _pgui)
    {
        if (!ntUserGetGUIThreadInfo) ntUserGetGUIThreadInfo = win_::resolve_proc_address("NtUserGetGUIThreadInfo", 22);
        return reinterpret_cast<BOOL(*)(ULONG, PGUITHREADINFO)>(ntUserGetGUIThreadInfo)(_idThread, _pgui);
    }
    ULONG NtuserGetGuiResources(HANDLE _processHandle, ULONG _flags)
    {
        if (!ntUserGetGuiResources) ntUserGetGuiResources = win_::resolve_proc_address("NtUserGetGuiResources", 21);
        return reinterpret_cast<ULONG(*)(HANDLE, ULONG)>(ntUserGetGuiResources)(_processHandle, _flags);
    }
    LOGICAL NtuserGetIMEShowStatus()
    {
        if (!ntUserGetIMEShowStatus) ntUserGetIMEShowStatus = win_::resolve_proc_address("NtUserGetIMEShowStatus", 22);
        return reinterpret_cast<LOGICAL(*)()>(ntUserGetIMEShowStatus)();
    }
    BOOL NtuserGetIconInfo(HICON _iconOrCursorHandle, PICONINFO _iconinfo, PUNICODE_STRING _name, PUNICODE_STRING _resourceId, PULONG _colorBits, LOGICAL _isCursorHandle)
    {
        if (!ntUserGetIconInfo) ntUserGetIconInfo = win_::resolve_proc_address("NtUserGetIconInfo", 17);
        return reinterpret_cast<BOOL(*)(HICON, PICONINFO, PUNICODE_STRING, PUNICODE_STRING, PULONG, LOGICAL)>(ntUserGetIconInfo)(_iconOrCursorHandle, _iconinfo, _name, _resourceId, _colorBits, _isCursorHandle);
    }
    BOOL NtuserGetIconSize(HGDIOBJ _iconOrCursorHandle, LOGICAL _isCursorHandle, PULONG _xX, PULONG _yY)
    {
        if (!ntUserGetIconSize) ntUserGetIconSize = win_::resolve_proc_address("NtUserGetIconSize", 17);
        return reinterpret_cast<BOOL(*)(HGDIOBJ, LOGICAL, PULONG, PULONG)>(ntUserGetIconSize)(_iconOrCursorHandle, _isCursorHandle, _xX, _yY);
    }
    HDESK NtuserGetInputDesktop()
    {
        if (!ntUserGetInputDesktop) ntUserGetInputDesktop = win_::resolve_proc_address("NtUserGetInputDesktop", 21);
        return reinterpret_cast<HDESK(*)()>(ntUserGetInputDesktop)();
    }
    HANDLE NtuserGetInputEvent(ULONG _wakeMask)
    {
        if (!ntUserGetInputEvent) ntUserGetInputEvent = win_::resolve_proc_address("NtUserGetInputEvent", 19);
        return reinterpret_cast<HANDLE(*)(ULONG)>(ntUserGetInputEvent)(_wakeMask);
    }
    ULONG NtuserGetKeyboardType(ULONG _typeFlag)
    {
        if (!ntUserGetKeyboardType) ntUserGetKeyboardType = win_::resolve_proc_address("NtUserGetKeyboardType", 21);
        return reinterpret_cast<ULONG(*)(ULONG)>(ntUserGetKeyboardType)(_typeFlag);
    }
    BOOL NtuserGetLayeredWindowAttributes(HWND _windowHandle, COLORREF* _key, PBYTE _alpha, PULONG _flags)
    {
        if (!ntUserGetLayeredWindowAttributes) ntUserGetLayeredWindowAttributes = win_::resolve_proc_address("NtUserGetLayeredWindowAttributes", 32);
        return reinterpret_cast<BOOL(*)(HWND, COLORREF*, PBYTE, PULONG)>(ntUserGetLayeredWindowAttributes)(_windowHandle, _key, _alpha, _flags);
    }
    ULONG NtuserGetListBoxInfo(HWND _windowHandle)
    {
        if (!ntUserGetListBoxInfo) ntUserGetListBoxInfo = win_::resolve_proc_address("NtUserGetListBoxInfo", 20);
        return reinterpret_cast<ULONG(*)(HWND)>(ntUserGetListBoxInfo)(_windowHandle);
    }
    BOOL NtuserGetMenuBarInfo(HWND _windowHandle, LONG _idObject, LONG _idItem, PMENUBARINFO _pmbi)
    {
        if (!ntUserGetMenuBarInfo) ntUserGetMenuBarInfo = win_::resolve_proc_address("NtUserGetMenuBarInfo", 20);
        return reinterpret_cast<BOOL(*)(HWND, LONG, LONG, PMENUBARINFO)>(ntUserGetMenuBarInfo)(_windowHandle, _idObject, _idItem, _pmbi);
    }
    BOOL NtuserGetMenuItemRect(HWND _windowHandle, HMENU _menuHandle, ULONG _menuIndex, PRECT _menuRect)
    {
        if (!ntUserGetMenuItemRect) ntUserGetMenuItemRect = win_::resolve_proc_address("NtUserGetMenuItemRect", 21);
        return reinterpret_cast<BOOL(*)(HWND, HMENU, ULONG, PRECT)>(ntUserGetMenuItemRect)(_windowHandle, _menuHandle, _menuIndex, _menuRect);
    }
    ULONG NtuserGetMessagePos()
    {
        if (!ntUserGetMessagePos) ntUserGetMessagePos = win_::resolve_proc_address("NtUserGetMessagePos", 19);
        return reinterpret_cast<ULONG(*)()>(ntUserGetMessagePos)();
    }
    HWND NtuserGetModernAppWindow(HWND _shellFrame)
    {
        if (!ntUserGetModernAppWindow) ntUserGetModernAppWindow = win_::resolve_proc_address("NtUserGetModernAppWindow", 24);
        return reinterpret_cast<HWND(*)(HWND)>(ntUserGetModernAppWindow)(_shellFrame);
    }
    LONG NtuserGetMouseMovePointsEx(ULONG _mouseMovePointsSize, LPMOUSEMOVEPOINT _inputBuffer, LPMOUSEMOVEPOINT _outputBuffer, LONG _outputBufferCount, ULONG _resolution)
    {
        if (!ntUserGetMouseMovePointsEx) ntUserGetMouseMovePointsEx = win_::resolve_proc_address("NtUserGetMouseMovePointsEx", 26);
        return reinterpret_cast<LONG(*)(ULONG, LPMOUSEMOVEPOINT, LPMOUSEMOVEPOINT, LONG, ULONG)>(ntUserGetMouseMovePointsEx)(_mouseMovePointsSize, _inputBuffer, _outputBuffer, _outputBufferCount, _resolution);
    }
    BOOL NtuserGetObjectInformation(HANDLE _objectHandle, LONG _index, PVOID _vInfo, ULONG _length, PULONG _lengthNeeded)
    {
        if (!ntUserGetObjectInformation) ntUserGetObjectInformation = win_::resolve_proc_address("NtUserGetObjectInformation", 26);
        return reinterpret_cast<BOOL(*)(HANDLE, LONG, PVOID, ULONG, PULONG)>(ntUserGetObjectInformation)(_objectHandle, _index, _vInfo, _length, _lengthNeeded);
    }
    LOGICAL NtuserGetProcessDefaultLayout(PULONG _defaultLayout)
    {
        if (!ntUserGetProcessDefaultLayout) ntUserGetProcessDefaultLayout = win_::resolve_proc_address("NtUserGetProcessDefaultLayout", 29);
        return reinterpret_cast<LOGICAL(*)(PULONG)>(ntUserGetProcessDefaultLayout)(_defaultLayout);
    }
    NTSTATUS NtuserGetProcessUIContextInformation(HANDLE _processHandle, PPROCESS_UICONTEXT_INFORMATION _uIContext)
    {
        if (!ntUserGetProcessUIContextInformation) ntUserGetProcessUIContextInformation = win_::resolve_proc_address("NtUserGetProcessUIContextInformation", 36);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PPROCESS_UICONTEXT_INFORMATION)>(ntUserGetProcessUIContextInformation)(_processHandle, _uIContext);
    }
    HWINSTA NtuserGetProcessWindowStation()
    {
        if (!ntUserGetProcessWindowStation) ntUserGetProcessWindowStation = win_::resolve_proc_address("NtUserGetProcessWindowStation", 29);
        return reinterpret_cast<HWINSTA(*)()>(ntUserGetProcessWindowStation)();
    }
    HANDLE NtuserGetProp(HWND _windowHandle, PCWSTR _string)
    {
        if (!ntUserGetProp) ntUserGetProp = win_::resolve_proc_address("NtUserGetProp", 13);
        return reinterpret_cast<HANDLE(*)(HWND, PCWSTR)>(ntUserGetProp)(_windowHandle, _string);
    }
    HANDLE NtuserGetProp2(HWND _windowHandle, PCUNICODE_STRING _string)
    {
        if (!ntUserGetProp2) ntUserGetProp2 = win_::resolve_proc_address("NtUserGetProp2", 14);
        return reinterpret_cast<HANDLE(*)(HWND, PCUNICODE_STRING)>(ntUserGetProp2)(_windowHandle, _string);
    }
    ULONG_PTR NtuserGetQueueIocp()
    {
        if (!ntUserGetQueueIocp) ntUserGetQueueIocp = win_::resolve_proc_address("NtUserGetQueueIocp", 18);
        return reinterpret_cast<ULONG_PTR(*)()>(ntUserGetQueueIocp)();
    }
    ULONG NtuserGetRawInputData(HRAWINPUT _rawInputData, ULONG _rawInputCommand, PVOID _rawInputBuffer, PULONG _rawInputBufferSize, ULONG _rawInputHeaderSize)
    {
        if (!ntUserGetRawInputData) ntUserGetRawInputData = win_::resolve_proc_address("NtUserGetRawInputData", 21);
        return reinterpret_cast<ULONG(*)(HRAWINPUT, ULONG, PVOID, PULONG, ULONG)>(ntUserGetRawInputData)(_rawInputData, _rawInputCommand, _rawInputBuffer, _rawInputBufferSize, _rawInputHeaderSize);
    }
    ULONG NtuserGetRawInputDeviceList(PRAWINPUTDEVICELIST _rawInputDeviceList, PULONG _rawInputDeviceCount, ULONG _rawInputDeviceSize)
    {
        if (!ntUserGetRawInputDeviceList) ntUserGetRawInputDeviceList = win_::resolve_proc_address("NtUserGetRawInputDeviceList", 27);
        return reinterpret_cast<ULONG(*)(PRAWINPUTDEVICELIST, PULONG, ULONG)>(ntUserGetRawInputDeviceList)(_rawInputDeviceList, _rawInputDeviceCount, _rawInputDeviceSize);
    }
    ULONG NtuserGetRegisteredRawInputDevices(PRAWINPUTDEVICE _rawInputDevices, PULONG _rawInputDeviceCount, ULONG _rawInputDeviceSize)
    {
        if (!ntUserGetRegisteredRawInputDevices) ntUserGetRegisteredRawInputDevices = win_::resolve_proc_address("NtUserGetRegisteredRawInputDevices", 34);
        return reinterpret_cast<ULONG(*)(PRAWINPUTDEVICE, PULONG, ULONG)>(ntUserGetRegisteredRawInputDevices)(_rawInputDevices, _rawInputDeviceCount, _rawInputDeviceSize);
    }
    HWND NtuserGetSendMessageReceiver(ULONG _threadIdSender)
    {
        if (!ntUserGetSendMessageReceiver) ntUserGetSendMessageReceiver = win_::resolve_proc_address("NtUserGetSendMessageReceiver", 28);
        return reinterpret_cast<HWND(*)(ULONG)>(ntUserGetSendMessageReceiver)(_threadIdSender);
    }
    ULONG_PTR NtuserGetSysMenuOffset(HWND _hwnd)
    {
        if (!ntUserGetSysMenuOffset) ntUserGetSysMenuOffset = win_::resolve_proc_address("NtUserGetSysMenuOffset", 22);
        return reinterpret_cast<ULONG_PTR(*)(HWND)>(ntUserGetSysMenuOffset)(_hwnd);
    }
    HMENU NtuserGetSystemMenu(HWND _windowHandle, BOOL _revert)
    {
        if (!ntUserGetSystemMenu) ntUserGetSystemMenu = win_::resolve_proc_address("NtUserGetSystemMenu", 19);
        return reinterpret_cast<HMENU(*)(HWND, BOOL)>(ntUserGetSystemMenu)(_windowHandle, _revert);
    }
    HDESK NtuserGetThreadDesktop(ULONG _threadId)
    {
        if (!ntUserGetThreadDesktop) ntUserGetThreadDesktop = win_::resolve_proc_address("NtUserGetThreadDesktop", 22);
        return reinterpret_cast<HDESK(*)(ULONG)>(ntUserGetThreadDesktop)(_threadId);
    }
    ULONG_PTR NtuserGetThreadState(ULONG _userThreadState)
    {
        if (!ntUserGetThreadState) ntUserGetThreadState = win_::resolve_proc_address("NtUserGetThreadState", 20);
        return reinterpret_cast<ULONG_PTR(*)(ULONG)>(ntUserGetThreadState)(_userThreadState);
    }
    BOOL NtuserGetTitleBarInfo(HWND _windowHandle, PTITLEBARINFO _pti)
    {
        if (!ntUserGetTitleBarInfo) ntUserGetTitleBarInfo = win_::resolve_proc_address("NtUserGetTitleBarInfo", 21);
        return reinterpret_cast<BOOL(*)(HWND, PTITLEBARINFO)>(ntUserGetTitleBarInfo)(_windowHandle, _pti);
    }
    ULONG NtuserGetUnpredictedMessagePos()
    {
        if (!ntUserGetUnpredictedMessagePos) ntUserGetUnpredictedMessagePos = win_::resolve_proc_address("NtUserGetUnpredictedMessagePos", 30);
        return reinterpret_cast<ULONG(*)()>(ntUserGetUnpredictedMessagePos)();
    }
    LOGICAL NtuserGetWinStationInfo(PWSINFO _wsInfo)
    {
        if (!ntUserGetWinStationInfo) ntUserGetWinStationInfo = win_::resolve_proc_address("NtUserGetWinStationInfo", 23);
        return reinterpret_cast<LOGICAL(*)(PWSINFO)>(ntUserGetWinStationInfo)(_wsInfo);
    }
    ULONG NtuserGetWindowContextHelpId(HWND _hwnd)
    {
        if (!ntUserGetWindowContextHelpId) ntUserGetWindowContextHelpId = win_::resolve_proc_address("NtUserGetWindowContextHelpId", 28);
        return reinterpret_cast<ULONG(*)(HWND)>(ntUserGetWindowContextHelpId)(_hwnd);
    }
    HDC NtuserGetWindowDC(HWND _windowHandle)
    {
        if (!ntUserGetWindowDC) ntUserGetWindowDC = win_::resolve_proc_address("NtUserGetWindowDC", 17);
        return reinterpret_cast<HDC(*)(HWND)>(ntUserGetWindowDC)(_windowHandle);
    }
    BOOL NtuserGetWindowPlacement(HWND _windowHandle, PWINDOWPLACEMENT _windowPlacement)
    {
        if (!ntUserGetWindowPlacement) ntUserGetWindowPlacement = win_::resolve_proc_address("NtUserGetWindowPlacement", 24);
        return reinterpret_cast<BOOL(*)(HWND, PWINDOWPLACEMENT)>(ntUserGetWindowPlacement)(_windowHandle, _windowPlacement);
    }
    HANDLE NtuserGetWindowProcessHandle(HWND _windowHandle, ACCESS_MASK _desiredAccess)
    {
        if (!ntUserGetWindowProcessHandle) ntUserGetWindowProcessHandle = win_::resolve_proc_address("NtUserGetWindowProcessHandle", 28);
        return reinterpret_cast<HANDLE(*)(HWND, ACCESS_MASK)>(ntUserGetWindowProcessHandle)(_windowHandle, _desiredAccess);
    }
    ULONG_PTR NtuserGetWindowTrackInfoAsync(HWND _hwnd)
    {
        if (!ntUserGetWindowTrackInfoAsync) ntUserGetWindowTrackInfoAsync = win_::resolve_proc_address("NtUserGetWindowTrackInfoAsync", 29);
        return reinterpret_cast<ULONG_PTR(*)(HWND)>(ntUserGetWindowTrackInfoAsync)(_hwnd);
    }
    HWND NtuserGhostWindowFromHungWindow(HWND _windowHandle)
    {
        if (!ntUserGhostWindowFromHungWindow) ntUserGhostWindowFromHungWindow = win_::resolve_proc_address("NtUserGhostWindowFromHungWindow", 31);
        return reinterpret_cast<HWND(*)(HWND)>(ntUserGhostWindowFromHungWindow)(_windowHandle);
    }
    LOGICAL NtuserHandleSystemThreadCreationFailure()
    {
        if (!ntUserHandleSystemThreadCreationFailure) ntUserHandleSystemThreadCreationFailure = win_::resolve_proc_address("NtUserHandleSystemThreadCreationFailure", 39);
        return reinterpret_cast<LOGICAL(*)()>(ntUserHandleSystemThreadCreationFailure)();
    }
    ULONG_PTR NtuserHideCursorNoCapture()
    {
        if (!ntUserHideCursorNoCapture) ntUserHideCursorNoCapture = win_::resolve_proc_address("NtUserHideCursorNoCapture", 25);
        return reinterpret_cast<ULONG_PTR(*)()>(ntUserHideCursorNoCapture)();
    }
    BOOL NtuserHiliteMenuItem(HWND _windowHandle, HMENU _menuHandle, ULONG _iDHiliteItem, ULONG _hilite)
    {
        if (!ntUserHiliteMenuItem) ntUserHiliteMenuItem = win_::resolve_proc_address("NtUserHiliteMenuItem", 20);
        return reinterpret_cast<BOOL(*)(HWND, HMENU, ULONG, ULONG)>(ntUserHiliteMenuItem)(_windowHandle, _menuHandle, _iDHiliteItem, _hilite);
    }
    HWND NtuserHungWindowFromGhostWindow(HWND _windowHandle)
    {
        if (!ntUserHungWindowFromGhostWindow) ntUserHungWindowFromGhostWindow = win_::resolve_proc_address("NtUserHungWindowFromGhostWindow", 31);
        return reinterpret_cast<HWND(*)(HWND)>(ntUserHungWindowFromGhostWindow)(_windowHandle);
    }
    LOGICAL NtuserInitAnsiOem(PCHAR _oemToCharA, PCHAR _charToOemA)
    {
        if (!ntUserInitAnsiOem) ntUserInitAnsiOem = win_::resolve_proc_address("NtUserInitAnsiOem", 17);
        return reinterpret_cast<LOGICAL(*)(PCHAR, PCHAR)>(ntUserInitAnsiOem)(_oemToCharA, _charToOemA);
    }
    ULONG_PTR NtuserInitThreadCoreMessagingIocp(HWND _hwnd)
    {
        if (!ntUserInitThreadCoreMessagingIocp) ntUserInitThreadCoreMessagingIocp = win_::resolve_proc_address("NtUserInitThreadCoreMessagingIocp", 33);
        return reinterpret_cast<ULONG_PTR(*)(HWND)>(ntUserInitThreadCoreMessagingIocp)(_hwnd);
    }
    HICON NtuserInternalGetWindowIcon(HWND _windowHandle, ULONG _iconType)
    {
        if (!ntUserInternalGetWindowIcon) ntUserInternalGetWindowIcon = win_::resolve_proc_address("NtUserInternalGetWindowIcon", 27);
        return reinterpret_cast<HICON(*)(HWND, ULONG)>(ntUserInternalGetWindowIcon)(_windowHandle, _iconType);
    }
    ULONG NtuserInternalGetWindowText(HWND _windowHandle, LPWSTR _pString, ULONG _cchMaxCount)
    {
        if (!ntUserInternalGetWindowText) ntUserInternalGetWindowText = win_::resolve_proc_address("NtUserInternalGetWindowText", 27);
        return reinterpret_cast<ULONG(*)(HWND, LPWSTR, ULONG)>(ntUserInternalGetWindowText)(_windowHandle, _pString, _cchMaxCount);
    }
    BOOL NtuserInvalidateRect(HWND _windowHandle, RECT* _rect, BOOL _erase)
    {
        if (!ntUserInvalidateRect) ntUserInvalidateRect = win_::resolve_proc_address("NtUserInvalidateRect", 20);
        return reinterpret_cast<BOOL(*)(HWND, RECT*, BOOL)>(ntUserInvalidateRect)(_windowHandle, _rect, _erase);
    }
    BOOL NtuserInvalidateRgn(HWND _windowHandle, HRGN _rgnHandle, BOOL _erase)
    {
        if (!ntUserInvalidateRgn) ntUserInvalidateRgn = win_::resolve_proc_address("NtUserInvalidateRgn", 19);
        return reinterpret_cast<BOOL(*)(HWND, HRGN, BOOL)>(ntUserInvalidateRgn)(_windowHandle, _rgnHandle, _erase);
    }
    LOGICAL NtuserIsQueueAttached()
    {
        if (!ntUserIsQueueAttached) ntUserIsQueueAttached = win_::resolve_proc_address("NtUserIsQueueAttached", 21);
        return reinterpret_cast<LOGICAL(*)()>(ntUserIsQueueAttached)();
    }
    BOOL NtuserIsTouchWindow(HWND _windowHandle, PULONG _flags)
    {
        if (!ntUserIsTouchWindow) ntUserIsTouchWindow = win_::resolve_proc_address("NtUserIsTouchWindow", 19);
        return reinterpret_cast<BOOL(*)(HWND, PULONG)>(ntUserIsTouchWindow)(_windowHandle, _flags);
    }
    LOGICAL NtuserKillSystemTimer(HWND _hwnd, UINT_PTR _iDEvent)
    {
        if (!ntUserKillSystemTimer) ntUserKillSystemTimer = win_::resolve_proc_address("NtUserKillSystemTimer", 21);
        return reinterpret_cast<LOGICAL(*)(HWND, UINT_PTR)>(ntUserKillSystemTimer)(_hwnd, _iDEvent);
    }
    BOOL NtuserKillTimer(HWND _windowHandle, ULONG_PTR _iDEvent)
    {
        if (!ntUserKillTimer) ntUserKillTimer = win_::resolve_proc_address("NtUserKillTimer", 15);
        return reinterpret_cast<BOOL(*)(HWND, ULONG_PTR)>(ntUserKillTimer)(_windowHandle, _iDEvent);
    }
    LOGICAL NtuserLWLoadFonts(LOGICAL _remote)
    {
        if (!ntUserLW_LoadFonts) ntUserLW_LoadFonts = win_::resolve_proc_address("NtUserLW_LoadFonts", 18);
        return reinterpret_cast<LOGICAL(*)(LOGICAL)>(ntUserLW_LoadFonts)(_remote);
    }
    LOGICAL NtuserLoadCursorsAndIcons()
    {
        if (!ntUserLoadCursorsAndIcons) ntUserLoadCursorsAndIcons = win_::resolve_proc_address("NtUserLoadCursorsAndIcons", 25);
        return reinterpret_cast<LOGICAL(*)()>(ntUserLoadCursorsAndIcons)();
    }
    LOGICAL NtuserLoadUserApiHook()
    {
        if (!ntUserLoadUserApiHook) ntUserLoadUserApiHook = win_::resolve_proc_address("NtUserLoadUserApiHook", 21);
        return reinterpret_cast<LOGICAL(*)()>(ntUserLoadUserApiHook)();
    }
    LOGICAL NtuserLockSetForegroundWindow(ULONG _lockCode)
    {
        if (!ntUserLockSetForegroundWindow) ntUserLockSetForegroundWindow = win_::resolve_proc_address("NtUserLockSetForegroundWindow", 29);
        return reinterpret_cast<LOGICAL(*)(ULONG)>(ntUserLockSetForegroundWindow)(_lockCode);
    }
    BOOL NtuserLockWorkStation()
    {
        if (!ntUserLockWorkStation) ntUserLockWorkStation = win_::resolve_proc_address("NtUserLockWorkStation", 21);
        return reinterpret_cast<BOOL(*)()>(ntUserLockWorkStation)();
    }
    BOOL NtuserLogicalToPhysicalPoint(HWND _windowHandle, LPPOINT _lpPoint)
    {
        if (!ntUserLogicalToPhysicalPoint) ntUserLogicalToPhysicalPoint = win_::resolve_proc_address("NtUserLogicalToPhysicalPoint", 28);
        return reinterpret_cast<BOOL(*)(HWND, LPPOINT)>(ntUserLogicalToPhysicalPoint)(_windowHandle, _lpPoint);
    }
    PVOID NtuserMapDesktopObject(HANDLE _h)
    {
        if (!ntUserMapDesktopObject) ntUserMapDesktopObject = win_::resolve_proc_address("NtUserMapDesktopObject", 22);
        return reinterpret_cast<PVOID(*)(HANDLE)>(ntUserMapDesktopObject)(_h);
    }
    LONG NtuserMenuItemFromPoint(HWND _windowHandle, HMENU _menuHandle, POINT _ptScreen)
    {
        if (!ntUserMenuItemFromPoint) ntUserMenuItemFromPoint = win_::resolve_proc_address("NtUserMenuItemFromPoint", 23);
        return reinterpret_cast<LONG(*)(HWND, HMENU, POINT)>(ntUserMenuItemFromPoint)(_windowHandle, _menuHandle, _ptScreen);
    }
    LOGICAL NtuserMessageBeep(ULONG _type)
    {
        if (!ntUserMessageBeep) ntUserMessageBeep = win_::resolve_proc_address("NtUserMessageBeep", 17);
        return reinterpret_cast<LOGICAL(*)(ULONG)>(ntUserMessageBeep)(_type);
    }
    BOOL NtuserMoveWindow(HWND _windowHandle, LONG _x, LONG _y, LONG _width, LONG _height, BOOL _repaint)
    {
        if (!ntUserMoveWindow) ntUserMoveWindow = win_::resolve_proc_address("NtUserMoveWindow", 16);
        return reinterpret_cast<BOOL(*)(HWND, LONG, LONG, LONG, LONG, BOOL)>(ntUserMoveWindow)(_windowHandle, _x, _y, _width, _height, _repaint);
    }
    LOGICAL NtuserNlsKbdSendIMENotification(ULONG _imeOpen, ULONG _imeConversion)
    {
        if (!ntUserNlsKbdSendIMENotification) ntUserNlsKbdSendIMENotification = win_::resolve_proc_address("NtUserNlsKbdSendIMENotification", 31);
        return reinterpret_cast<LOGICAL(*)(ULONG, ULONG)>(ntUserNlsKbdSendIMENotification)(_imeOpen, _imeConversion);
    }
    LOGICAL NtuserNotifyOverlayWindow(HWND _hwnd, LOGICAL _enable)
    {
        if (!ntUserNotifyOverlayWindow) ntUserNotifyOverlayWindow = win_::resolve_proc_address("NtUserNotifyOverlayWindow", 25);
        return reinterpret_cast<LOGICAL(*)(HWND, LOGICAL)>(ntUserNotifyOverlayWindow)(_hwnd, _enable);
    }
    HANDLE NtuserOpenDesktop(PCOBJECT_ATTRIBUTES _objectAttributes, ULONG _flags, ACCESS_MASK _desiredAccess)
    {
        if (!ntUserOpenDesktop) ntUserOpenDesktop = win_::resolve_proc_address("NtUserOpenDesktop", 17);
        return reinterpret_cast<HANDLE(*)(PCOBJECT_ATTRIBUTES, ULONG, ACCESS_MASK)>(ntUserOpenDesktop)(_objectAttributes, _flags, _desiredAccess);
    }
    HDESK NtuserOpenInputDesktop(ULONG _flags, BOOL _inherit, ACCESS_MASK _desiredAccess)
    {
        if (!ntUserOpenInputDesktop) ntUserOpenInputDesktop = win_::resolve_proc_address("NtUserOpenInputDesktop", 22);
        return reinterpret_cast<HDESK(*)(ULONG, BOOL, ACCESS_MASK)>(ntUserOpenInputDesktop)(_flags, _inherit, _desiredAccess);
    }
    HWINSTA NtuserOpenWindowStation(POBJECT_ATTRIBUTES _objectAttributes, ACCESS_MASK _desiredAccess)
    {
        if (!ntUserOpenWindowStation) ntUserOpenWindowStation = win_::resolve_proc_address("NtUserOpenWindowStation", 23);
        return reinterpret_cast<HWINSTA(*)(POBJECT_ATTRIBUTES, ACCESS_MASK)>(ntUserOpenWindowStation)(_objectAttributes, _desiredAccess);
    }
    BOOL NtuserPhysicalToLogicalPoint(HWND _windowHandle, LPPOINT _point)
    {
        if (!ntUserPhysicalToLogicalPoint) ntUserPhysicalToLogicalPoint = win_::resolve_proc_address("NtUserPhysicalToLogicalPoint", 28);
        return reinterpret_cast<BOOL(*)(HWND, LPPOINT)>(ntUserPhysicalToLogicalPoint)(_windowHandle, _point);
    }
    LOGICAL NtuserPlayEventSound(ULONG _idSound)
    {
        if (!ntUserPlayEventSound) ntUserPlayEventSound = win_::resolve_proc_address("NtUserPlayEventSound", 20);
        return reinterpret_cast<LOGICAL(*)(ULONG)>(ntUserPlayEventSound)(_idSound);
    }
    LOGICAL NtuserPostQuitMessage(LONG _exitCode)
    {
        if (!ntUserPostQuitMessage) ntUserPostQuitMessage = win_::resolve_proc_address("NtUserPostQuitMessage", 21);
        return reinterpret_cast<LOGICAL(*)(LONG)>(ntUserPostQuitMessage)(_exitCode);
    }
    LOGICAL NtuserPrepareForLogoff()
    {
        if (!ntUserPrepareForLogoff) ntUserPrepareForLogoff = win_::resolve_proc_address("NtUserPrepareForLogoff", 22);
        return reinterpret_cast<LOGICAL(*)()>(ntUserPrepareForLogoff)();
    }
    BOOL NtuserPrintWindow(HWND _windowHandle, HDC _hdc, ULONG _flags)
    {
        if (!ntUserPrintWindow) ntUserPrintWindow = win_::resolve_proc_address("NtUserPrintWindow", 17);
        return reinterpret_cast<BOOL(*)(HWND, HDC, ULONG)>(ntUserPrintWindow)(_windowHandle, _hdc, _flags);
    }
    NTSTATUS NtuserQueryInformationThread(HANDLE _threadHandle, USERTHREADINFOCLASS _threadInformationClass, PVOID _threadInformation, PULONG _returnLength)
    {
        if (!ntUserQueryInformationThread) ntUserQueryInformationThread = win_::resolve_proc_address("NtUserQueryInformationThread", 28);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, USERTHREADINFOCLASS, PVOID, PULONG)>(ntUserQueryInformationThread)(_threadHandle, _threadInformationClass, _threadInformation, _returnLength);
    }
    BOOL NtuserQuerySendMessage(PMSG _message)
    {
        if (!ntUserQuerySendMessage) ntUserQuerySendMessage = win_::resolve_proc_address("NtUserQuerySendMessage", 22);
        return reinterpret_cast<BOOL(*)(PMSG)>(ntUserQuerySendMessage)(_message);
    }
    ULONG_PTR NtuserQueryWindow(HWND _windowHandle, WINDOWINFOCLASS _windowInfo)
    {
        if (!ntUserQueryWindow) ntUserQueryWindow = win_::resolve_proc_address("NtUserQueryWindow", 17);
        return reinterpret_cast<ULONG_PTR(*)(HWND, WINDOWINFOCLASS)>(ntUserQueryWindow)(_windowHandle, _windowInfo);
    }
    NTSTATUS NtuserRaiseLowerShellWindow(HWND _windowHandle, BOOLEAN _setWithOptions)
    {
        if (!ntUserRaiseLowerShellWindow) ntUserRaiseLowerShellWindow = win_::resolve_proc_address("NtUserRaiseLowerShellWindow", 27);
        return reinterpret_cast<NTSTATUS(*)(HWND, BOOLEAN)>(ntUserRaiseLowerShellWindow)(_windowHandle, _setWithOptions);
    }
    HWND NtuserRealChildWindowFromPoint(HWND _windowHandleParent, POINT _ptParentClientCoords)
    {
        if (!ntUserRealChildWindowFromPoint) ntUserRealChildWindowFromPoint = win_::resolve_proc_address("NtUserRealChildWindowFromPoint", 30);
        return reinterpret_cast<HWND(*)(HWND, POINT)>(ntUserRealChildWindowFromPoint)(_windowHandleParent, _ptParentClientCoords);
    }
    ULONG NtuserRealizePalette(HDC _hdc)
    {
        if (!ntUserRealizePalette) ntUserRealizePalette = win_::resolve_proc_address("NtUserRealizePalette", 20);
        return reinterpret_cast<ULONG(*)(HDC)>(ntUserRealizePalette)(_hdc);
    }
    LOGICAL NtuserReassociateQueueEventCompletionPacket()
    {
        if (!ntUserReassociateQueueEventCompletionPacket) ntUserReassociateQueueEventCompletionPacket = win_::resolve_proc_address("NtUserReassociateQueueEventCompletionPacket", 43);
        return reinterpret_cast<LOGICAL(*)()>(ntUserReassociateQueueEventCompletionPacket)();
    }
    LOGICAL NtuserRedrawFrame(HWND _hwnd)
    {
        if (!ntUserRedrawFrame) ntUserRedrawFrame = win_::resolve_proc_address("NtUserRedrawFrame", 17);
        return reinterpret_cast<LOGICAL(*)(HWND)>(ntUserRedrawFrame)(_hwnd);
    }
    LOGICAL NtuserRedrawFrameAndHook(HWND _hwnd)
    {
        if (!ntUserRedrawFrameAndHook) ntUserRedrawFrameAndHook = win_::resolve_proc_address("NtUserRedrawFrameAndHook", 24);
        return reinterpret_cast<LOGICAL(*)(HWND)>(ntUserRedrawFrameAndHook)(_hwnd);
    }
    LOGICAL NtuserRedrawTitle(HWND _hwnd, ULONG _flags)
    {
        if (!ntUserRedrawTitle) ntUserRedrawTitle = win_::resolve_proc_address("NtUserRedrawTitle", 17);
        return reinterpret_cast<LOGICAL(*)(HWND, ULONG)>(ntUserRedrawTitle)(_hwnd, _flags);
    }
    BOOL NtuserRedrawWindow(HWND _windowHandle, PRECT _lprcUpdate, HRGN _hrgnUpdate, ULONG _flags)
    {
        if (!ntUserRedrawWindow) ntUserRedrawWindow = win_::resolve_proc_address("NtUserRedrawWindow", 18);
        return reinterpret_cast<BOOL(*)(HWND, PRECT, HRGN, ULONG)>(ntUserRedrawWindow)(_windowHandle, _lprcUpdate, _hrgnUpdate, _flags);
    }
    BOOL NtuserRegisterCloakedNotification(HWND _windowHandle, BOOL _register)
    {
        if (!ntUserRegisterCloakedNotification) ntUserRegisterCloakedNotification = win_::resolve_proc_address("NtUserRegisterCloakedNotification", 33);
        return reinterpret_cast<BOOL(*)(HWND, BOOL)>(ntUserRegisterCloakedNotification)(_windowHandle, _register);
    }
    LOGICAL NtuserRegisterGhostWindow(HWND _ghost, HWND _hung)
    {
        if (!ntUserRegisterGhostWindow) ntUserRegisterGhostWindow = win_::resolve_proc_address("NtUserRegisterGhostWindow", 25);
        return reinterpret_cast<LOGICAL(*)(HWND, HWND)>(ntUserRegisterGhostWindow)(_ghost, _hung);
    }
    BOOL NtuserRegisterHotKey(HWND _windowHandle, LONG _id, ULONG _fsModifiers, ULONG _vk)
    {
        if (!ntUserRegisterHotKey) ntUserRegisterHotKey = win_::resolve_proc_address("NtUserRegisterHotKey", 20);
        return reinterpret_cast<BOOL(*)(HWND, LONG, ULONG, ULONG)>(ntUserRegisterHotKey)(_windowHandle, _id, _fsModifiers, _vk);
    }
    LOGICAL NtuserRegisterLPK(ULONG _lpkEntryPoints)
    {
        if (!ntUserRegisterLPK) ntUserRegisterLPK = win_::resolve_proc_address("NtUserRegisterLPK", 17);
        return reinterpret_cast<LOGICAL(*)(ULONG)>(ntUserRegisterLPK)(_lpkEntryPoints);
    }
    LOGICAL NtuserRegisterLogonProcess(ULONG _processId, PLUID _luidConnect)
    {
        if (!ntUserRegisterLogonProcess) ntUserRegisterLogonProcess = win_::resolve_proc_address("NtUserRegisterLogonProcess", 26);
        return reinterpret_cast<LOGICAL(*)(ULONG, PLUID)>(ntUserRegisterLogonProcess)(_processId, _luidConnect);
    }
    LOGICAL NtuserRegisterShellHookWindow(HWND _hwnd)
    {
        if (!ntUserRegisterShellHookWindow) ntUserRegisterShellHookWindow = win_::resolve_proc_address("NtUserRegisterShellHookWindow", 29);
        return reinterpret_cast<LOGICAL(*)(HWND)>(ntUserRegisterShellHookWindow)(_hwnd);
    }
    LOGICAL NtuserRegisterSiblingFrostWindow(HWND _hwndFrost, HWND _hwnd)
    {
        if (!ntUserRegisterSiblingFrostWindow) ntUserRegisterSiblingFrostWindow = win_::resolve_proc_address("NtUserRegisterSiblingFrostWindow", 32);
        return reinterpret_cast<LOGICAL(*)(HWND, HWND)>(ntUserRegisterSiblingFrostWindow)(_hwndFrost, _hwnd);
    }
    LOGICAL NtuserRegisterSystemThread(ULONG _flags)
    {
        if (!ntUserRegisterSystemThread) ntUserRegisterSystemThread = win_::resolve_proc_address("NtUserRegisterSystemThread", 26);
        return reinterpret_cast<LOGICAL(*)(ULONG)>(ntUserRegisterSystemThread)(_flags);
    }
    LOGICAL NtuserRegisterUserHungAppHandlers(PFNW32ET _w32EndTask, HANDLE _eventWowExec)
    {
        if (!ntUserRegisterUserHungAppHandlers) ntUserRegisterUserHungAppHandlers = win_::resolve_proc_address("NtUserRegisterUserHungAppHandlers", 33);
        return reinterpret_cast<LOGICAL(*)(PFNW32ET, HANDLE)>(ntUserRegisterUserHungAppHandlers)(_w32EndTask, _eventWowExec);
    }
    LOGICAL NtuserRegisterWindowArrangementCallout(HWND _hwnd, LOGICAL _register)
    {
        if (!ntUserRegisterWindowArrangementCallout) ntUserRegisterWindowArrangementCallout = win_::resolve_proc_address("NtUserRegisterWindowArrangementCallout", 38);
        return reinterpret_cast<LOGICAL(*)(HWND, LOGICAL)>(ntUserRegisterWindowArrangementCallout)(_hwnd, _register);
    }
    LOGICAL NtuserReleaseCapture()
    {
        if (!ntUserReleaseCapture) ntUserReleaseCapture = win_::resolve_proc_address("NtUserReleaseCapture", 20);
        return reinterpret_cast<LOGICAL(*)()>(ntUserReleaseCapture)();
    }
    ULONG NtuserRemoteConnectState()
    {
        if (!ntUserRemoteConnectState) ntUserRemoteConnectState = win_::resolve_proc_address("NtUserRemoteConnectState", 24);
        return reinterpret_cast<ULONG(*)()>(ntUserRemoteConnectState)();
    }
    NTSTATUS NtuserRemoteConsoleShadowStop()
    {
        if (!ntUserRemoteConsoleShadowStop) ntUserRemoteConsoleShadowStop = win_::resolve_proc_address("NtUserRemoteConsoleShadowStop", 29);
        return reinterpret_cast<NTSTATUS(*)()>(ntUserRemoteConsoleShadowStop)();
    }
    NTSTATUS NtuserRemoteDisconnect()
    {
        if (!ntUserRemoteDisconnect) ntUserRemoteDisconnect = win_::resolve_proc_address("NtUserRemoteDisconnect", 22);
        return reinterpret_cast<NTSTATUS(*)()>(ntUserRemoteDisconnect)();
    }
    NTSTATUS NtuserRemoteNotify(_DONOTIFYDATA* _doNotifyData)
    {
        if (!ntUserRemoteNotify) ntUserRemoteNotify = win_::resolve_proc_address("NtUserRemoteNotify", 18);
        return reinterpret_cast<NTSTATUS(*)(_DONOTIFYDATA*)>(ntUserRemoteNotify)(_doNotifyData);
    }
    NTSTATUS NtuserRemotePassthruDisable()
    {
        if (!ntUserRemotePassthruDisable) ntUserRemotePassthruDisable = win_::resolve_proc_address("NtUserRemotePassthruDisable", 27);
        return reinterpret_cast<NTSTATUS(*)()>(ntUserRemotePassthruDisable)();
    }
    NTSTATUS NtuserRemotePassthruEnable()
    {
        if (!ntUserRemotePassthruEnable) ntUserRemotePassthruEnable = win_::resolve_proc_address("NtUserRemotePassthruEnable", 26);
        return reinterpret_cast<NTSTATUS(*)()>(ntUserRemotePassthruEnable)();
    }
    NTSTATUS NtuserRemoteReconnect(_DOCONNECTDATA* _doConnectData)
    {
        if (!ntUserRemoteReconnect) ntUserRemoteReconnect = win_::resolve_proc_address("NtUserRemoteReconnect", 21);
        return reinterpret_cast<NTSTATUS(*)(_DOCONNECTDATA*)>(ntUserRemoteReconnect)(_doConnectData);
    }
    NTSTATUS NtuserRemoteShadowCleanup(PVOID _thinwireData, ULONG _thinwireDataLength)
    {
        if (!ntUserRemoteShadowCleanup) ntUserRemoteShadowCleanup = win_::resolve_proc_address("NtUserRemoteShadowCleanup", 25);
        return reinterpret_cast<NTSTATUS(*)(PVOID, ULONG)>(ntUserRemoteShadowCleanup)(_thinwireData, _thinwireDataLength);
    }
    NTSTATUS NtuserRemoteShadowSetup()
    {
        if (!ntUserRemoteShadowSetup) ntUserRemoteShadowSetup = win_::resolve_proc_address("NtUserRemoteShadowSetup", 23);
        return reinterpret_cast<NTSTATUS(*)()>(ntUserRemoteShadowSetup)();
    }
    NTSTATUS NtuserRemoteShadowStart(PVOID _thinwireData, ULONG _thinwireDataLength)
    {
        if (!ntUserRemoteShadowStart) ntUserRemoteShadowStart = win_::resolve_proc_address("NtUserRemoteShadowStart", 23);
        return reinterpret_cast<NTSTATUS(*)(PVOID, ULONG)>(ntUserRemoteShadowStart)(_thinwireData, _thinwireDataLength);
    }
    NTSTATUS NtuserRemoteShadowStop()
    {
        if (!ntUserRemoteShadowStop) ntUserRemoteShadowStop = win_::resolve_proc_address("NtUserRemoteShadowStop", 22);
        return reinterpret_cast<NTSTATUS(*)()>(ntUserRemoteShadowStop)();
    }
    NTSTATUS NtuserRemoteThinwireStats(CACHE_STATISTICS* _stats)
    {
        if (!ntUserRemoteThinwireStats) ntUserRemoteThinwireStats = win_::resolve_proc_address("NtUserRemoteThinwireStats", 25);
        return reinterpret_cast<NTSTATUS(*)(CACHE_STATISTICS*)>(ntUserRemoteThinwireStats)(_stats);
    }
    BOOL NtuserRemoveMenu(HMENU _menuHandle, ULONG _position, ULONG _flags)
    {
        if (!ntUserRemoveMenu) ntUserRemoveMenu = win_::resolve_proc_address("NtUserRemoveMenu", 16);
        return reinterpret_cast<BOOL(*)(HMENU, ULONG, ULONG)>(ntUserRemoveMenu)(_menuHandle, _position, _flags);
    }
    LOGICAL NtuserRemoveQueueCompletion()
    {
        if (!ntUserRemoveQueueCompletion) ntUserRemoveQueueCompletion = win_::resolve_proc_address("NtUserRemoveQueueCompletion", 27);
        return reinterpret_cast<LOGICAL(*)()>(ntUserRemoveQueueCompletion)();
    }
    LOGICAL NtuserReplyMessage(LRESULT _result)
    {
        if (!ntUserReplyMessage) ntUserReplyMessage = win_::resolve_proc_address("NtUserReplyMessage", 18);
        return reinterpret_cast<LOGICAL(*)(LRESULT)>(ntUserReplyMessage)(_result);
    }
    LOGICAL NtuserResetDblClk()
    {
        if (!ntUserResetDblClk) ntUserResetDblClk = win_::resolve_proc_address("NtUserResetDblClk", 17);
        return reinterpret_cast<LOGICAL(*)()>(ntUserResetDblClk)();
    }
    ULONG_PTR NtuserScaleSystemMetricForDPIWithoutCache(ULONG _metric, ULONG _toDpi)
    {
        if (!ntUserScaleSystemMetricForDPIWithoutCache) ntUserScaleSystemMetricForDPIWithoutCache = win_::resolve_proc_address("NtUserScaleSystemMetricForDPIWithoutCache", 41);
        return reinterpret_cast<ULONG_PTR(*)(ULONG, ULONG)>(ntUserScaleSystemMetricForDPIWithoutCache)(_metric, _toDpi);
    }
    LOGICAL NtuserScheduleDispatchNotification(HWND _hwnd)
    {
        if (!ntUserScheduleDispatchNotification) ntUserScheduleDispatchNotification = win_::resolve_proc_address("NtUserScheduleDispatchNotification", 34);
        return reinterpret_cast<LOGICAL(*)(HWND)>(ntUserScheduleDispatchNotification)(_hwnd);
    }
    ULONG NtuserSendInput(ULONG _count, LPINPUT _inputs, LONG _size)
    {
        if (!ntUserSendInput) ntUserSendInput = win_::resolve_proc_address("NtUserSendInput", 15);
        return reinterpret_cast<ULONG(*)(ULONG, LPINPUT, LONG)>(ntUserSendInput)(_count, _inputs, _size);
    }
    HWND NtuserSetActiveWindow(HWND _windowHandle)
    {
        if (!ntUserSetActiveWindow) ntUserSetActiveWindow = win_::resolve_proc_address("NtUserSetActiveWindow", 21);
        return reinterpret_cast<HWND(*)(HWND)>(ntUserSetActiveWindow)(_windowHandle);
    }
    ULONG NtuserSetAdditionalForegroundBoostProcesses(HWND _windowHandle)
    {
        if (!ntUserSetAdditionalForegroundBoostProcesses) ntUserSetAdditionalForegroundBoostProcesses = win_::resolve_proc_address("NtUserSetAdditionalForegroundBoostProcesses", 43);
        return reinterpret_cast<ULONG(*)(HWND)>(ntUserSetAdditionalForegroundBoostProcesses)(_windowHandle);
    }
    ULONG NtuserSetAdditionalPowerThrottlingProcess(HWND _windowHandle, ULONG _processHandlesCount, PHANDLE _processHandles)
    {
        if (!ntUserSetAdditionalPowerThrottlingProcess) ntUserSetAdditionalPowerThrottlingProcess = win_::resolve_proc_address("NtUserSetAdditionalPowerThrottlingProcess", 41);
        return reinterpret_cast<ULONG(*)(HWND, ULONG, PHANDLE)>(ntUserSetAdditionalPowerThrottlingProcess)(_windowHandle, _processHandlesCount, _processHandles);
    }
    LOGICAL NtuserSetCancelRotationDelayHintWindow(HWND _hwnd)
    {
        if (!ntUserSetCancelRotationDelayHintWindow) ntUserSetCancelRotationDelayHintWindow = win_::resolve_proc_address("NtUserSetCancelRotationDelayHintWindow", 38);
        return reinterpret_cast<LOGICAL(*)(HWND)>(ntUserSetCancelRotationDelayHintWindow)(_hwnd);
    }
    HWND NtuserSetCapture(HWND _windowHandle)
    {
        if (!ntUserSetCapture) ntUserSetCapture = win_::resolve_proc_address("NtUserSetCapture", 16);
        return reinterpret_cast<HWND(*)(HWND)>(ntUserSetCapture)(_windowHandle);
    }
    LOGICAL NtuserSetCaretBlinkTime(ULONG _milliseconds)
    {
        if (!ntUserSetCaretBlinkTime) ntUserSetCaretBlinkTime = win_::resolve_proc_address("NtUserSetCaretBlinkTime", 23);
        return reinterpret_cast<LOGICAL(*)(ULONG)>(ntUserSetCaretBlinkTime)(_milliseconds);
    }
    LOGICAL NtuserSetCaretPos(LONG _x, LONG _y)
    {
        if (!ntUserSetCaretPos) ntUserSetCaretPos = win_::resolve_proc_address("NtUserSetCaretPos", 17);
        return reinterpret_cast<LOGICAL(*)(LONG, LONG)>(ntUserSetCaretPos)(_x, _y);
    }
    NTSTATUS NtuserSetChildWindowNoActivate(HWND _windowHandle)
    {
        if (!ntUserSetChildWindowNoActivate) ntUserSetChildWindowNoActivate = win_::resolve_proc_address("NtUserSetChildWindowNoActivate", 30);
        return reinterpret_cast<NTSTATUS(*)(HWND)>(ntUserSetChildWindowNoActivate)(_windowHandle);
    }
    USHORT NtuserSetClassWord(HWND _windowHandle, LONG _index, USHORT _newWord)
    {
        if (!ntUserSetClassWord) ntUserSetClassWord = win_::resolve_proc_address("NtUserSetClassWord", 18);
        return reinterpret_cast<USHORT(*)(HWND, LONG, USHORT)>(ntUserSetClassWord)(_windowHandle, _index, _newWord);
    }
    BOOL NtuserSetCursorPos(LONG _x, LONG _y)
    {
        if (!ntUserSetCursorPos) ntUserSetCursorPos = win_::resolve_proc_address("NtUserSetCursorPos", 18);
        return reinterpret_cast<BOOL(*)(LONG, LONG)>(ntUserSetCursorPos)(_x, _y);
    }
    LOGICAL NtuserSetDialogPointer(HWND _hwnd, ULONG_PTR _ptr)
    {
        if (!ntUserSetDialogPointer) ntUserSetDialogPointer = win_::resolve_proc_address("NtUserSetDialogPointer", 22);
        return reinterpret_cast<LOGICAL(*)(HWND, ULONG_PTR)>(ntUserSetDialogPointer)(_hwnd, _ptr);
    }
    LOGICAL NtuserSetDialogSystemMenu(HWND _hwnd)
    {
        if (!ntUserSetDialogSystemMenu) ntUserSetDialogSystemMenu = win_::resolve_proc_address("NtUserSetDialogSystemMenu", 25);
        return reinterpret_cast<LOGICAL(*)(HWND)>(ntUserSetDialogSystemMenu)(_hwnd);
    }
    LOGICAL NtuserSetDoubleClickTime(ULONG _milliseconds)
    {
        if (!ntUserSetDoubleClickTime) ntUserSetDoubleClickTime = win_::resolve_proc_address("NtUserSetDoubleClickTime", 24);
        return reinterpret_cast<LOGICAL(*)(ULONG)>(ntUserSetDoubleClickTime)(_milliseconds);
    }
    HWND NtuserSetFocus(HWND _windowHandle)
    {
        if (!ntUserSetFocus) ntUserSetFocus = win_::resolve_proc_address("NtUserSetFocus", 14);
        return reinterpret_cast<HWND(*)(HWND)>(ntUserSetFocus)(_windowHandle);
    }
    LOGICAL NtuserSetForegroundWindow(HWND _hwnd)
    {
        if (!ntUserSetForegroundWindow) ntUserSetForegroundWindow = win_::resolve_proc_address("NtUserSetForegroundWindow", 25);
        return reinterpret_cast<LOGICAL(*)(HWND)>(ntUserSetForegroundWindow)(_hwnd);
    }
    NTSTATUS NtuserSetForegroundWindowForApplication(HWND _windowHandle)
    {
        if (!ntUserSetForegroundWindowForApplication) ntUserSetForegroundWindowForApplication = win_::resolve_proc_address("NtUserSetForegroundWindowForApplication", 39);
        return reinterpret_cast<NTSTATUS(*)(HWND)>(ntUserSetForegroundWindowForApplication)(_windowHandle);
    }
    NTSTATUS NtuserSetInformationThread(HANDLE _threadHandle, USERTHREADINFOCLASS _threadInformationClass, PVOID _threadInformation, ULONG _threadInformationLength)
    {
        if (!ntUserSetInformationThread) ntUserSetInformationThread = win_::resolve_proc_address("NtUserSetInformationThread", 26);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, USERTHREADINFOCLASS, PVOID, ULONG)>(ntUserSetInformationThread)(_threadHandle, _threadInformationClass, _threadInformation, _threadInformationLength);
    }
    BOOL NtuserSetLayeredWindowAttributes(HWND _windowHandle, COLORREF _key, BYTE _alpha, ULONG _flags)
    {
        if (!ntUserSetLayeredWindowAttributes) ntUserSetLayeredWindowAttributes = win_::resolve_proc_address("NtUserSetLayeredWindowAttributes", 32);
        return reinterpret_cast<BOOL(*)(HWND, COLORREF, BYTE, ULONG)>(ntUserSetLayeredWindowAttributes)(_windowHandle, _key, _alpha, _flags);
    }
    LPARAM NtuserSetMessageExtraInfo(LPARAM _param)
    {
        if (!ntUserSetMessageExtraInfo) ntUserSetMessageExtraInfo = win_::resolve_proc_address("NtUserSetMessageExtraInfo", 25);
        return reinterpret_cast<LPARAM(*)(LPARAM)>(ntUserSetMessageExtraInfo)(_param);
    }
    LOGICAL NtuserSetModernAppWindow(HWND _shellFrame, HWND _app)
    {
        if (!ntUserSetModernAppWindow) ntUserSetModernAppWindow = win_::resolve_proc_address("NtUserSetModernAppWindow", 24);
        return reinterpret_cast<LOGICAL(*)(HWND, HWND)>(ntUserSetModernAppWindow)(_shellFrame, _app);
    }
    LOGICAL NtuserSetMsgBox(HWND _hwnd)
    {
        if (!ntUserSetMsgBox) ntUserSetMsgBox = win_::resolve_proc_address("NtUserSetMsgBox", 15);
        return reinterpret_cast<LOGICAL(*)(HWND)>(ntUserSetMsgBox)(_hwnd);
    }
    LOGICAL NtuserSetProcessDefaultLayout(ULONG _defaultLayout)
    {
        if (!ntUserSetProcessDefaultLayout) ntUserSetProcessDefaultLayout = win_::resolve_proc_address("NtUserSetProcessDefaultLayout", 29);
        return reinterpret_cast<LOGICAL(*)(ULONG)>(ntUserSetProcessDefaultLayout)(_defaultLayout);
    }
    NTSTATUS NtuserSetProcessRestrictionExemption(BOOL _enableExemption)
    {
        if (!ntUserSetProcessRestrictionExemption) ntUserSetProcessRestrictionExemption = win_::resolve_proc_address("NtUserSetProcessRestrictionExemption", 36);
        return reinterpret_cast<NTSTATUS(*)(BOOL)>(ntUserSetProcessRestrictionExemption)(_enableExemption);
    }
    NTSTATUS NtuserSetProcessUIAccessZorder()
    {
        if (!ntUserSetProcessUIAccessZorder) ntUserSetProcessUIAccessZorder = win_::resolve_proc_address("NtUserSetProcessUIAccessZorder", 30);
        return reinterpret_cast<NTSTATUS(*)()>(ntUserSetProcessUIAccessZorder)();
    }
    NTSTATUS NtuserSetProcessWin32_capabilities(USER_PROCESS_CAP_ENTRY* _capabilities, ULONG _count)
    {
        if (!ntUserSetProcessWin32Capabilities) ntUserSetProcessWin32Capabilities = win_::resolve_proc_address("NtUserSetProcessWin32Capabilities", 33);
        return reinterpret_cast<NTSTATUS(*)(USER_PROCESS_CAP_ENTRY*, ULONG)>(ntUserSetProcessWin32Capabilities)(_capabilities, _count);
    }
    BOOL NtuserSetProcessWindowStation(HWINSTA _windowStationHandle)
    {
        if (!ntUserSetProcessWindowStation) ntUserSetProcessWindowStation = win_::resolve_proc_address("NtUserSetProcessWindowStation", 29);
        return reinterpret_cast<BOOL(*)(HWINSTA)>(ntUserSetProcessWindowStation)(_windowStationHandle);
    }
    LOGICAL NtuserSetProgmanWindow(HWND _hwnd)
    {
        if (!ntUserSetProgmanWindow) ntUserSetProgmanWindow = win_::resolve_proc_address("NtUserSetProgmanWindow", 22);
        return reinterpret_cast<LOGICAL(*)(HWND)>(ntUserSetProgmanWindow)(_hwnd);
    }
    LOGICAL NtuserSetShellChangeNotifyHWND(HWND _hwnd)
    {
        if (!ntUserSetShellChangeNotifyHWND) ntUserSetShellChangeNotifyHWND = win_::resolve_proc_address("NtUserSetShellChangeNotifyHWND", 30);
        return reinterpret_cast<LOGICAL(*)(HWND)>(ntUserSetShellChangeNotifyHWND)(_hwnd);
    }
    LOGICAL NtuserSetSysMenu(HWND _hwnd)
    {
        if (!ntUserSetSysMenu) ntUserSetSysMenu = win_::resolve_proc_address("NtUserSetSysMenu", 16);
        return reinterpret_cast<LOGICAL(*)(HWND)>(ntUserSetSysMenu)(_hwnd);
    }
    LOGICAL NtuserSetTSFEventState(ULONG _stateFlags)
    {
        if (!ntUserSetTSFEventState) ntUserSetTSFEventState = win_::resolve_proc_address("NtUserSetTSFEventState", 22);
        return reinterpret_cast<LOGICAL(*)(ULONG)>(ntUserSetTSFEventState)(_stateFlags);
    }
    LOGICAL NtuserSetTaskmanWindow(HWND _hwnd)
    {
        if (!ntUserSetTaskmanWindow) ntUserSetTaskmanWindow = win_::resolve_proc_address("NtUserSetTaskmanWindow", 22);
        return reinterpret_cast<LOGICAL(*)(HWND)>(ntUserSetTaskmanWindow)(_hwnd);
    }
    BOOL NtuserSetThreadDesktop(HDESK _desktopHandle)
    {
        if (!ntUserSetThreadDesktop) ntUserSetThreadDesktop = win_::resolve_proc_address("NtUserSetThreadDesktop", 22);
        return reinterpret_cast<BOOL(*)(HDESK)>(ntUserSetThreadDesktop)(_desktopHandle);
    }
    LOGICAL NtuserSetThreadQueueMergeSetting(ULONG _threadId, ULONG _flags)
    {
        if (!ntUserSetThreadQueueMergeSetting) ntUserSetThreadQueueMergeSetting = win_::resolve_proc_address("NtUserSetThreadQueueMergeSetting", 32);
        return reinterpret_cast<LOGICAL(*)(ULONG, ULONG)>(ntUserSetThreadQueueMergeSetting)(_threadId, _flags);
    }
    ULONG_PTR NtuserSetTimer(HWND _windowHandle, ULONG_PTR _iDEvent, ULONG _elapse, TIMERPROC _timerFunc, ULONG _toleranceDelay)
    {
        if (!ntUserSetTimer) ntUserSetTimer = win_::resolve_proc_address("NtUserSetTimer", 14);
        return reinterpret_cast<ULONG_PTR(*)(HWND, ULONG_PTR, ULONG, TIMERPROC, ULONG)>(ntUserSetTimer)(_windowHandle, _iDEvent, _elapse, _timerFunc, _toleranceDelay);
    }
    LOGICAL NtuserSetVisible(HWND _hwnd, ULONG _flags)
    {
        if (!ntUserSetVisible) ntUserSetVisible = win_::resolve_proc_address("NtUserSetVisible", 16);
        return reinterpret_cast<LOGICAL(*)(HWND, ULONG)>(ntUserSetVisible)(_hwnd, _flags);
    }
    LOGICAL NtuserSetWaitForQueueAttach(LOGICAL _waiting)
    {
        if (!ntUserSetWaitForQueueAttach) ntUserSetWaitForQueueAttach = win_::resolve_proc_address("NtUserSetWaitForQueueAttach", 27);
        return reinterpret_cast<LOGICAL(*)(LOGICAL)>(ntUserSetWaitForQueueAttach)(_waiting);
    }
    LOGICAL NtuserSetWatermarkStrings(PCUNICODE_STRING _stringTable)
    {
        if (!ntUserSetWatermarkStrings) ntUserSetWatermarkStrings = win_::resolve_proc_address("NtUserSetWatermarkStrings", 25);
        return reinterpret_cast<LOGICAL(*)(PCUNICODE_STRING)>(ntUserSetWatermarkStrings)(_stringTable);
    }
    LOGICAL NtuserSetWindowContextHelpId(HWND _hwnd, ULONG _contextId)
    {
        if (!ntUserSetWindowContextHelpId) ntUserSetWindowContextHelpId = win_::resolve_proc_address("NtUserSetWindowContextHelpId", 28);
        return reinterpret_cast<LOGICAL(*)(HWND, ULONG)>(ntUserSetWindowContextHelpId)(_hwnd, _contextId);
    }
    BOOL NtuserSetWindowPlacement(HWND _windowHandle, WINDOWPLACEMENT* _lpwndpl)
    {
        if (!ntUserSetWindowPlacement) ntUserSetWindowPlacement = win_::resolve_proc_address("NtUserSetWindowPlacement", 24);
        return reinterpret_cast<BOOL(*)(HWND, WINDOWPLACEMENT*)>(ntUserSetWindowPlacement)(_windowHandle, _lpwndpl);
    }
    BOOL NtuserSetWindowPos(HWND _windowHandle, HWND _windowHandleInsertAfter, LONG _x, LONG _y, LONG _cx, LONG _cy, ULONG _flags)
    {
        if (!ntUserSetWindowPos) ntUserSetWindowPos = win_::resolve_proc_address("NtUserSetWindowPos", 18);
        return reinterpret_cast<BOOL(*)(HWND, HWND, LONG, LONG, LONG, LONG, ULONG)>(ntUserSetWindowPos)(_windowHandle, _windowHandleInsertAfter, _x, _y, _cx, _cy, _flags);
    }
    LOGICAL NtuserSetWindowState(HWND _hwnd, ULONG _flag)
    {
        if (!ntUserSetWindowState) ntUserSetWindowState = win_::resolve_proc_address("NtUserSetWindowState", 20);
        return reinterpret_cast<LOGICAL(*)(HWND, ULONG)>(ntUserSetWindowState)(_hwnd, _flag);
    }
    BOOL NtuserSetWindowStationUser(HWINSTA _windowStationHandle, PLUID _userLogonId, PSID _userSid, ULONG _userSidLength)
    {
        if (!ntUserSetWindowStationUser) ntUserSetWindowStationUser = win_::resolve_proc_address("NtUserSetWindowStationUser", 26);
        return reinterpret_cast<BOOL(*)(HWINSTA, PLUID, PSID, ULONG)>(ntUserSetWindowStationUser)(_windowStationHandle, _userLogonId, _userSid, _userSidLength);
    }
    USHORT NtuserSetWindowWord(HWND _windowHandle, LONG _index, USHORT _newWord)
    {
        if (!ntUserSetWindowWord) ntUserSetWindowWord = win_::resolve_proc_address("NtUserSetWindowWord", 19);
        return reinterpret_cast<USHORT(*)(HWND, LONG, USHORT)>(ntUserSetWindowWord)(_windowHandle, _index, _newWord);
    }
    HWND NtuserShellForegroundBoostProcess(HANDLE _processHandle, HWND _windowHandle)
    {
        if (!ntUserShellForegroundBoostProcess) ntUserShellForegroundBoostProcess = win_::resolve_proc_address("NtUserShellForegroundBoostProcess", 33);
        return reinterpret_cast<HWND(*)(HANDLE, HWND)>(ntUserShellForegroundBoostProcess)(_processHandle, _windowHandle);
    }
    LONG NtuserShowCursor(BOOL _show)
    {
        if (!ntUserShowCursor) ntUserShowCursor = win_::resolve_proc_address("NtUserShowCursor", 16);
        return reinterpret_cast<LONG(*)(BOOL)>(ntUserShowCursor)(_show);
    }
    LOGICAL NtuserShowOwnedPopups(HWND _owner, LOGICAL _show)
    {
        if (!ntUserShowOwnedPopups) ntUserShowOwnedPopups = win_::resolve_proc_address("NtUserShowOwnedPopups", 21);
        return reinterpret_cast<LOGICAL(*)(HWND, LOGICAL)>(ntUserShowOwnedPopups)(_owner, _show);
    }
    LOGICAL NtuserShowStartGlass(ULONG _timeout)
    {
        if (!ntUserShowStartGlass) ntUserShowStartGlass = win_::resolve_proc_address("NtUserShowStartGlass", 20);
        return reinterpret_cast<LOGICAL(*)(ULONG)>(ntUserShowStartGlass)(_timeout);
    }
    BOOL NtuserShowWindow(HWND _windowHandle, LONG _cmdShow)
    {
        if (!ntUserShowWindow) ntUserShowWindow = win_::resolve_proc_address("NtUserShowWindow", 16);
        return reinterpret_cast<BOOL(*)(HWND, LONG)>(ntUserShowWindow)(_windowHandle, _cmdShow);
    }
    BOOL NtuserShowWindowAsync(HWND _windowHandle, LONG _cmdShow)
    {
        if (!ntUserShowWindowAsync) ntUserShowWindowAsync = win_::resolve_proc_address("NtUserShowWindowAsync", 21);
        return reinterpret_cast<BOOL(*)(HWND, LONG)>(ntUserShowWindowAsync)(_windowHandle, _cmdShow);
    }
    BOOL NtuserShutdownBlockReasonQuery(HWND _windowHandle, PWSTR _buffer, PULONG _bufferCount)
    {
        if (!ntUserShutdownBlockReasonQuery) ntUserShutdownBlockReasonQuery = win_::resolve_proc_address("NtUserShutdownBlockReasonQuery", 30);
        return reinterpret_cast<BOOL(*)(HWND, PWSTR, PULONG)>(ntUserShutdownBlockReasonQuery)(_windowHandle, _buffer, _bufferCount);
    }
    BOOL NtuserShutdownReasonDestroy(HWND _windowHandle)
    {
        if (!ntUserShutdownReasonDestroy) ntUserShutdownReasonDestroy = win_::resolve_proc_address("NtUserShutdownReasonDestroy", 27);
        return reinterpret_cast<BOOL(*)(HWND)>(ntUserShutdownReasonDestroy)(_windowHandle);
    }
    LOGICAL NtuserSwapMouseButton(LOGICAL _swapButtons)
    {
        if (!ntUserSwapMouseButton) ntUserSwapMouseButton = win_::resolve_proc_address("NtUserSwapMouseButton", 21);
        return reinterpret_cast<LOGICAL(*)(LOGICAL)>(ntUserSwapMouseButton)(_swapButtons);
    }
    BOOL NtuserSwitchDesktop(HDESK _desktopHandle, ULONG _flags, ULONG _fadeTime)
    {
        if (!ntUserSwitchDesktop) ntUserSwitchDesktop = win_::resolve_proc_address("NtUserSwitchDesktop", 19);
        return reinterpret_cast<BOOL(*)(HDESK, ULONG, ULONG)>(ntUserSwitchDesktop)(_desktopHandle, _flags, _fadeTime);
    }
    LOGICAL NtuserSwitchToThisWindow(HWND _hwnd, LOGICAL _altTab)
    {
        if (!ntUserSwitchToThisWindow) ntUserSwitchToThisWindow = win_::resolve_proc_address("NtUserSwitchToThisWindow", 24);
        return reinterpret_cast<LOGICAL(*)(HWND, LOGICAL)>(ntUserSwitchToThisWindow)(_hwnd, _altTab);
    }
    NTSTATUS NtuserTestForInteractiveUser(PLUID _authenticationId)
    {
        if (!ntUserTestForInteractiveUser) ntUserTestForInteractiveUser = win_::resolve_proc_address("NtUserTestForInteractiveUser", 28);
        return reinterpret_cast<NTSTATUS(*)(PLUID)>(ntUserTestForInteractiveUser)(_authenticationId);
    }
    LOGICAL NtuserThreadMessageQueueAttached(ULONG _threadId)
    {
        if (!ntUserThreadMessageQueueAttached) ntUserThreadMessageQueueAttached = win_::resolve_proc_address("NtUserThreadMessageQueueAttached", 32);
        return reinterpret_cast<LOGICAL(*)(ULONG)>(ntUserThreadMessageQueueAttached)(_threadId);
    }
    BOOL NtuserTrackMouseEvent(LPTRACKMOUSEEVENT _eventTrack)
    {
        if (!ntUserTrackMouseEvent) ntUserTrackMouseEvent = win_::resolve_proc_address("NtUserTrackMouseEvent", 21);
        return reinterpret_cast<BOOL(*)(LPTRACKMOUSEEVENT)>(ntUserTrackMouseEvent)(_eventTrack);
    }
    BOOL NtuserTrackPopupMenuEx(HMENU _menuHandle, ULONG _flags, LONG _x, LONG _y, HWND _windowHandle, LPTPMPARAMS _lptpm)
    {
        if (!ntUserTrackPopupMenuEx) ntUserTrackPopupMenuEx = win_::resolve_proc_address("NtUserTrackPopupMenuEx", 22);
        return reinterpret_cast<BOOL(*)(HMENU, ULONG, LONG, LONG, HWND, LPTPMPARAMS)>(ntUserTrackPopupMenuEx)(_menuHandle, _flags, _x, _y, _windowHandle, _lptpm);
    }
    BOOL NtuserUnhookWinEvent(HWINEVENTHOOK _winEventHookHandle)
    {
        if (!ntUserUnhookWinEvent) ntUserUnhookWinEvent = win_::resolve_proc_address("NtUserUnhookWinEvent", 20);
        return reinterpret_cast<BOOL(*)(HWINEVENTHOOK)>(ntUserUnhookWinEvent)(_winEventHookHandle);
    }
    LOGICAL NtuserUnhookWindowsHook(LONG _filterType, HOOKPROC _filterProc)
    {
        if (!ntUserUnhookWindowsHook) ntUserUnhookWindowsHook = win_::resolve_proc_address("NtUserUnhookWindowsHook", 23);
        return reinterpret_cast<LOGICAL(*)(LONG, HOOKPROC)>(ntUserUnhookWindowsHook)(_filterType, _filterProc);
    }
    BOOL NtuserUnregisterHotKey(HWND _windowHandle, LONG _id)
    {
        if (!ntUserUnregisterHotKey) ntUserUnregisterHotKey = win_::resolve_proc_address("NtUserUnregisterHotKey", 22);
        return reinterpret_cast<BOOL(*)(HWND, LONG)>(ntUserUnregisterHotKey)(_windowHandle, _id);
    }
    LOGICAL NtuserUpdateClientRect(HWND _hwnd)
    {
        if (!ntUserUpdateClientRect) ntUserUpdateClientRect = win_::resolve_proc_address("NtUserUpdateClientRect", 22);
        return reinterpret_cast<LOGICAL(*)(HWND)>(ntUserUpdateClientRect)(_hwnd);
    }
    LOGICAL NtuserUpdatePerUserImmEnabling()
    {
        if (!ntUserUpdatePerUserImmEnabling) ntUserUpdatePerUserImmEnabling = win_::resolve_proc_address("NtUserUpdatePerUserImmEnabling", 30);
        return reinterpret_cast<LOGICAL(*)()>(ntUserUpdatePerUserImmEnabling)();
    }
    LOGICAL NtuserUpdateWindow(HWND _hwnd)
    {
        if (!ntUserUpdateWindow) ntUserUpdateWindow = win_::resolve_proc_address("NtUserUpdateWindow", 18);
        return reinterpret_cast<LOGICAL(*)(HWND)>(ntUserUpdateWindow)(_hwnd);
    }
    LOGICAL NtuserUpdateWindows(HWND _hwnd, HRGN _hrgn)
    {
        if (!ntUserUpdateWindows) ntUserUpdateWindows = win_::resolve_proc_address("NtUserUpdateWindows", 19);
        return reinterpret_cast<LOGICAL(*)(HWND, HRGN)>(ntUserUpdateWindows)(_hwnd, _hrgn);
    }
    BOOL NtuserUserHandleGrantAccess(HANDLE _userHandle, HANDLE _job, BOOL _grant)
    {
        if (!ntUserUserHandleGrantAccess) ntUserUserHandleGrantAccess = win_::resolve_proc_address("NtUserUserHandleGrantAccess", 27);
        return reinterpret_cast<BOOL(*)(HANDLE, HANDLE, BOOL)>(ntUserUserHandleGrantAccess)(_userHandle, _job, _grant);
    }
    LOGICAL NtuserUserPowerCalloutWorker()
    {
        if (!ntUserUserPowerCalloutWorker) ntUserUserPowerCalloutWorker = win_::resolve_proc_address("NtUserUserPowerCalloutWorker", 28);
        return reinterpret_cast<LOGICAL(*)()>(ntUserUserPowerCalloutWorker)();
    }
    BOOL NtuserValidateRect(HWND _windowHandle, RECT* _rect)
    {
        if (!ntUserValidateRect) ntUserValidateRect = win_::resolve_proc_address("NtUserValidateRect", 18);
        return reinterpret_cast<BOOL(*)(HWND, RECT*)>(ntUserValidateRect)(_windowHandle, _rect);
    }
    LOGICAL NtuserValidateRgn(HWND _hwnd, HRGN _hrgn)
    {
        if (!ntUserValidateRgn) ntUserValidateRgn = win_::resolve_proc_address("NtUserValidateRgn", 17);
        return reinterpret_cast<LOGICAL(*)(HWND, HRGN)>(ntUserValidateRgn)(_hwnd, _hrgn);
    }
    LOGICAL NtuserWOWModuleUnload(HANDLE _module)
    {
        if (!ntUserWOWModuleUnload) ntUserWOWModuleUnload = win_::resolve_proc_address("NtUserWOWModuleUnload", 21);
        return reinterpret_cast<LOGICAL(*)(HANDLE)>(ntUserWOWModuleUnload)(_module);
    }
    NTSTATUS NtuserWakeRITForShutdown()
    {
        if (!ntUserWakeRITForShutdown) ntUserWakeRITForShutdown = win_::resolve_proc_address("NtUserWakeRITForShutdown", 24);
        return reinterpret_cast<NTSTATUS(*)()>(ntUserWakeRITForShutdown)();
    }
    HWND NtuserWindowFromDC(HDC _hdc)
    {
        if (!ntUserWindowFromDC) ntUserWindowFromDC = win_::resolve_proc_address("NtUserWindowFromDC", 18);
        return reinterpret_cast<HWND(*)(HDC)>(ntUserWindowFromDC)(_hdc);
    }
    HWND NtuserWindowFromPhysicalPoint(POINT _point)
    {
        if (!ntUserWindowFromPhysicalPoint) ntUserWindowFromPhysicalPoint = win_::resolve_proc_address("NtUserWindowFromPhysicalPoint", 29);
        return reinterpret_cast<HWND(*)(POINT)>(ntUserWindowFromPhysicalPoint)(_point);
    }
    HWND NtuserWindowFromPoint(POINT _point)
    {
        if (!ntUserWindowFromPoint) ntUserWindowFromPoint = win_::resolve_proc_address("NtUserWindowFromPoint", 21);
        return reinterpret_cast<HWND(*)(POINT)>(ntUserWindowFromPoint)(_point);
    }
    LOGICAL NtuserZapActiveAndFocus()
    {
        if (!ntUserZapActiveAndFocus) ntUserZapActiveAndFocus = win_::resolve_proc_address("NtUserZapActiveAndFocus", 23);
        return reinterpret_cast<LOGICAL(*)()>(ntUserZapActiveAndFocus)();
    }
    NTSTATUS NtvdmControl(VDMSERVICECLASS _service, PVOID _serviceData)
    {
        if (!ntVdmControl) ntVdmControl = win_::resolve_proc_address("NtVdmControl", 12);
        return reinterpret_cast<NTSTATUS(*)(VDMSERVICECLASS, PVOID)>(ntVdmControl)(_service, _serviceData);
    }
    NTSTATUS NtwaitForAlertByThreadId(PVOID _address, PLARGE_INTEGER _timeout)
    {
        if (!ntWaitForAlertByThreadId) ntWaitForAlertByThreadId = win_::resolve_proc_address("NtWaitForAlertByThreadId", 24);
        return reinterpret_cast<NTSTATUS(*)(PVOID, PLARGE_INTEGER)>(ntWaitForAlertByThreadId)(_address, _timeout);
    }
    NTSTATUS NtwaitForDebugEvent(HANDLE _debugObjectHandle, BOOLEAN _alertable, PLARGE_INTEGER _timeout, PDBGUI_WAIT_STATE_CHANGE _waitStateChange)
    {
        if (!ntWaitForDebugEvent) ntWaitForDebugEvent = win_::resolve_proc_address("NtWaitForDebugEvent", 19);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, BOOLEAN, PLARGE_INTEGER, PDBGUI_WAIT_STATE_CHANGE)>(ntWaitForDebugEvent)(_debugObjectHandle, _alertable, _timeout, _waitStateChange);
    }
    NTSTATUS NtwaitForKeyedEvent(HANDLE _keyedEventHandle, PVOID _keyValue, BOOLEAN _alertable, PLARGE_INTEGER _timeout)
    {
        if (!ntWaitForKeyedEvent) ntWaitForKeyedEvent = win_::resolve_proc_address("NtWaitForKeyedEvent", 19);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PVOID, BOOLEAN, PLARGE_INTEGER)>(ntWaitForKeyedEvent)(_keyedEventHandle, _keyValue, _alertable, _timeout);
    }
    NTSTATUS NtwaitForMultipleObjects(ULONG _count, HANDLE _handles[], WAIT_TYPE _waitType, BOOLEAN _alertable, PLARGE_INTEGER _timeout)
    {
        if (!ntWaitForMultipleObjects) ntWaitForMultipleObjects = win_::resolve_proc_address("NtWaitForMultipleObjects", 24);
        return reinterpret_cast<NTSTATUS(*)(ULONG, HANDLE[], WAIT_TYPE, BOOLEAN, PLARGE_INTEGER)>(ntWaitForMultipleObjects)(_count, _handles, _waitType, _alertable, _timeout);
    }
    NTSTATUS NtwaitForMultipleObjects32(ULONG _count, LONG _handles[], WAIT_TYPE _waitType, BOOLEAN _alertable, PLARGE_INTEGER _timeout)
    {
        if (!ntWaitForMultipleObjects32) ntWaitForMultipleObjects32 = win_::resolve_proc_address("NtWaitForMultipleObjects32", 26);
        return reinterpret_cast<NTSTATUS(*)(ULONG, LONG[], WAIT_TYPE, BOOLEAN, PLARGE_INTEGER)>(ntWaitForMultipleObjects32)(_count, _handles, _waitType, _alertable, _timeout);
    }
    NTSTATUS NtwaitForSingleObject(HANDLE _handle, BOOLEAN _alertable, PLARGE_INTEGER _timeout)
    {
        if (!ntWaitForSingleObject) ntWaitForSingleObject = win_::resolve_proc_address("NtWaitForSingleObject", 21);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, BOOLEAN, PLARGE_INTEGER)>(ntWaitForSingleObject)(_handle, _alertable, _timeout);
    }
    NTSTATUS NtwaitForWorkViaWorkerFactory(HANDLE _workerFactoryHandle, PFILE_IO_COMPLETION_INFORMATION _miniPackets, ULONG _count, PULONG _packetsReturned, PVOID _deferredWork)
    {
        if (!ntWaitForWorkViaWorkerFactory) ntWaitForWorkViaWorkerFactory = win_::resolve_proc_address("NtWaitForWorkViaWorkerFactory", 29);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PFILE_IO_COMPLETION_INFORMATION, ULONG, PULONG, PVOID)>(ntWaitForWorkViaWorkerFactory)(_workerFactoryHandle, _miniPackets, _count, _packetsReturned, _deferredWork);
    }
    NTSTATUS NtwaitHighEventPair(HANDLE _eventPairHandle)
    {
        if (!ntWaitHighEventPair) ntWaitHighEventPair = win_::resolve_proc_address("NtWaitHighEventPair", 19);
        return reinterpret_cast<NTSTATUS(*)(HANDLE)>(ntWaitHighEventPair)(_eventPairHandle);
    }
    NTSTATUS NtwaitLowEventPair(HANDLE _eventPairHandle)
    {
        if (!ntWaitLowEventPair) ntWaitLowEventPair = win_::resolve_proc_address("NtWaitLowEventPair", 18);
        return reinterpret_cast<NTSTATUS(*)(HANDLE)>(ntWaitLowEventPair)(_eventPairHandle);
    }
    NTSTATUS NtworkerFactoryWorkerReady(HANDLE _workerFactoryHandle)
    {
        if (!ntWorkerFactoryWorkerReady) ntWorkerFactoryWorkerReady = win_::resolve_proc_address("NtWorkerFactoryWorkerReady", 26);
        return reinterpret_cast<NTSTATUS(*)(HANDLE)>(ntWorkerFactoryWorkerReady)(_workerFactoryHandle);
    }
    NTSTATUS Ntwow64_get_native_system_information(SYSTEM_INFORMATION_CLASS _systemInformationClass, PVOID _nativeSystemInformation, ULONG _informationLength, PULONG _returnLength)
    {
        if (!ntWow64GetNativeSystemInformation) ntWow64GetNativeSystemInformation = win_::resolve_proc_address("NtWow64GetNativeSystemInformation", 33);
        return reinterpret_cast<NTSTATUS(*)(SYSTEM_INFORMATION_CLASS, PVOID, ULONG, PULONG)>(ntWow64GetNativeSystemInformation)(_systemInformationClass, _nativeSystemInformation, _informationLength, _returnLength);
    }
    NTSTATUS Ntwow64_query_information_process64(HANDLE _processHandle, PROCESSINFOCLASS _processInformationClass, PVOID _processInformation, ULONG _processInformationLength, PULONG _returnLength)
    {
        if (!ntWow64QueryInformationProcess64) ntWow64QueryInformationProcess64 = win_::resolve_proc_address("NtWow64QueryInformationProcess64", 32);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PROCESSINFOCLASS, PVOID, ULONG, PULONG)>(ntWow64QueryInformationProcess64)(_processHandle, _processInformationClass, _processInformation, _processInformationLength, _returnLength);
    }
    NTSTATUS Ntwow64_query_virtual_memory64(HANDLE _processHandle, ULONGLONG _baseAddress, MEMORY_INFORMATION_CLASS _memoryInformationClass, PVOID _memoryInformation, ULONGLONG _memoryInformationLength, PULONGLONG _returnLength)
    {
        if (!ntWow64QueryVirtualMemory64) ntWow64QueryVirtualMemory64 = win_::resolve_proc_address("NtWow64QueryVirtualMemory64", 27);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONGLONG, MEMORY_INFORMATION_CLASS, PVOID, ULONGLONG, PULONGLONG)>(ntWow64QueryVirtualMemory64)(_processHandle, _baseAddress, _memoryInformationClass, _memoryInformation, _memoryInformationLength, _returnLength);
    }
    NTSTATUS Ntwow64_read_virtual_memory64(HANDLE _processHandle, ULONGLONG _baseAddress, PVOID _buffer, ULONGLONG _numberOfBytesToRead, PULONGLONG _numberOfBytesRead)
    {
        if (!ntWow64ReadVirtualMemory64) ntWow64ReadVirtualMemory64 = win_::resolve_proc_address("NtWow64ReadVirtualMemory64", 26);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONGLONG, PVOID, ULONGLONG, PULONGLONG)>(ntWow64ReadVirtualMemory64)(_processHandle, _baseAddress, _buffer, _numberOfBytesToRead, _numberOfBytesRead);
    }
    NTSTATUS Ntwow64_write_virtual_memory64(HANDLE _processHandle, ULONGLONG _baseAddress, PVOID _buffer, ULONGLONG _numberOfBytesToWrite, PULONGLONG _numberOfBytesWritten)
    {
        if (!ntWow64WriteVirtualMemory64) ntWow64WriteVirtualMemory64 = win_::resolve_proc_address("NtWow64WriteVirtualMemory64", 27);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, ULONGLONG, PVOID, ULONGLONG, PULONGLONG)>(ntWow64WriteVirtualMemory64)(_processHandle, _baseAddress, _buffer, _numberOfBytesToWrite, _numberOfBytesWritten);
    }
    NTSTATUS NtwriteFile(HANDLE _fileHandle, HANDLE _event, PIO_APC_ROUTINE _apcRoutine, PVOID _apcContext, PIO_STATUS_BLOCK _ioStatusBlock, PVOID _buffer, ULONG _length, PLARGE_INTEGER _byteOffset, PULONG _key)
    {
        if (!ntWriteFile) ntWriteFile = win_::resolve_proc_address("NtWriteFile", 11);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE, PIO_APC_ROUTINE, PVOID, PIO_STATUS_BLOCK, PVOID, ULONG, PLARGE_INTEGER, PULONG)>(ntWriteFile)(_fileHandle, _event, _apcRoutine, _apcContext, _ioStatusBlock, _buffer, _length, _byteOffset, _key);
    }
    NTSTATUS NtwriteFileGather(HANDLE _fileHandle, HANDLE _event, PIO_APC_ROUTINE _apcRoutine, PVOID _apcContext, PIO_STATUS_BLOCK _ioStatusBlock, PFILE_SEGMENT_ELEMENT _segmentArray, ULONG _length, PLARGE_INTEGER _byteOffset, PULONG _key)
    {
        if (!ntWriteFileGather) ntWriteFileGather = win_::resolve_proc_address("NtWriteFileGather", 17);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, HANDLE, PIO_APC_ROUTINE, PVOID, PIO_STATUS_BLOCK, PFILE_SEGMENT_ELEMENT, ULONG, PLARGE_INTEGER, PULONG)>(ntWriteFileGather)(_fileHandle, _event, _apcRoutine, _apcContext, _ioStatusBlock, _segmentArray, _length, _byteOffset, _key);
    }
    NTSTATUS NtwriteRequestData(HANDLE _portHandle, PPORT_MESSAGE _message, ULONG _dataEntryIndex, PVOID _buffer, SIZE_T _bufferSize, PSIZE_T _numberOfBytesWritten)
    {
        if (!ntWriteRequestData) ntWriteRequestData = win_::resolve_proc_address("NtWriteRequestData", 18);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PPORT_MESSAGE, ULONG, PVOID, SIZE_T, PSIZE_T)>(ntWriteRequestData)(_portHandle, _message, _dataEntryIndex, _buffer, _bufferSize, _numberOfBytesWritten);
    }
    NTSTATUS NtwriteVirtualMemory(HANDLE _processHandle, PVOID _baseAddress, PVOID _buffer, SIZE_T _numberOfBytesToWrite, PSIZE_T _numberOfBytesWritten)
    {
        if (!ntWriteVirtualMemory) ntWriteVirtualMemory = win_::resolve_proc_address("NtWriteVirtualMemory", 20);
        return reinterpret_cast<NTSTATUS(*)(HANDLE, PVOID, PVOID, SIZE_T, PSIZE_T)>(ntWriteVirtualMemory)(_processHandle, _baseAddress, _buffer, _numberOfBytesToWrite, _numberOfBytesWritten);
    }
    NTSTATUS NtyieldExecution()
    {
        if (!ntYieldExecution) ntYieldExecution = win_::resolve_proc_address("NtYieldExecution", 16);
        return reinterpret_cast<NTSTATUS(*)()>(ntYieldExecution)();
    }
}