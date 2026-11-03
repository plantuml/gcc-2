#include "GC.h"
#include "../../../j/l/Object.h"
#include "../../../../heaptrace.h"
#include "FreeChunk.h"
#include "ExceptionHandling.h"
#include "FreeChunkHolder.h"
#include <string.h>
#include "GC@dRegion.h"
#include "MarkQueue.h"
#include "RuntimeClass.h"
#include "RuntimeReference.h"
#include "RuntimeReferenceQueue.h"
#include "RuntimeArray.h"
#include "RuntimeObject.h"
#include "RuntimeBuffer.h"
#include "../../../../stringhash.h"
#include "RelocationBlock.h"
#include "Relocation.h"
#include "../i/Address.h"
#include <stdlib.h>
#include "../../../../strings.h"

void* sfld_otr_GC_currentChunkLimit;
void* sfld_otr_GC_currentChunk;
void* sfld_otr_GC_currentChunkPointer;
int32_t sfld_otr_GC_freeChunks;
int32_t sfld_otr_GC_totalChunks;
int32_t sfld_otr_GC_freeMemory;
void* sfld_otr_GC_firstWeakReference;
void* sfld_otr_GC_lastChunk;
void* sfld_otr_GC_lastRelocationBlock;
int8_t sfld_otr_GC_isFullGC;
int32_t sfld_otr_GC_youngGCCount;
void* sfld_otr_GC_firstDirectBuffer;
int32_t meth_otr_GC_getRegionCount() {
    return (((int32_t) (teavm_gc_availableBytes / ((int64_t) teavm_gc_regionSize))) + INT32_C(1));
}
void* meth_otr_GC_alloc(int32_t teavm_local_1) {
    void* teavm_local_2;
    void* teavm_local_3;
    teavm_local_2 = sfld_otr_GC_currentChunk;
    teavm_local_3 = TEAVM_ADDRESS_ADD(teavm_local_2, teavm_local_1);
    if ((!((uintptr_t) TEAVM_ADDRESS_ADD(teavm_local_3, sizeof(cls_otr_FreeChunk)) < (uintptr_t) sfld_otr_GC_currentChunkLimit))) {
        meth_otr_GC_getNextChunk(teavm_local_1);
        teavm_local_2 = sfld_otr_GC_currentChunk;
        teavm_local_3 = TEAVM_ADDRESS_ADD(teavm_local_2, teavm_local_1);
    }
    sfld_otr_GC_currentChunk = teavm_local_3;
    sfld_otr_GC_freeMemory = (sfld_otr_GC_freeMemory - teavm_local_1);
    teavm_gc_allocate(teavm_local_2, teavm_local_1);
    return teavm_local_2;
}
void meth_otr_GC_getNextChunk(int32_t teavm_local_1) {
    if ((!meth_otr_GC_getNextChunkIfPossible(teavm_local_1))) {
        meth_otr_GC_collectGarbageImpl(teavm_local_1);
        if ((!meth_otr_GC_hasAvailableMemory(teavm_local_1))) {
            meth_otr_GC_collectGarbageFullImpl(teavm_local_1);
            if ((!meth_otr_GC_hasAvailableMemory(teavm_local_1))) {
                meth_otr_ExceptionHandling_printStack();
                teavm_outOfMemory();
            }
        }
        return;
    }
}
int32_t meth_otr_GC_hasAvailableMemory(int32_t teavm_local_1) {
    int32_t teavm_local_2;
    teavm_local_2 = TEAVM_FIELD(sfld_otr_GC_currentChunk, cls_otr_FreeChunk, fld_size);
    return ((!((teavm_local_2 != teavm_local_1) && ((teavm_local_2 <= (teavm_local_1 + INT32_C(8))) && (!meth_otr_GC_getNextChunkIfPossible(teavm_local_1))))) ? INT32_C(1) : INT32_C(0));
}
int32_t meth_otr_GC_getNextChunkIfPossible(int32_t teavm_local_1) {
    int32_t teavm_local_2;
    void* teavm_local_3;
    int32_t teavm_local_4;
    void* teavm_local_5;
    teavm_local_2 = (teavm_local_1 + INT32_C(8));
    while (1) {
        if (((uintptr_t) sfld_otr_GC_currentChunk < (uintptr_t) sfld_otr_GC_currentChunkLimit)) {
            teavm_local_3 = sfld_otr_GC_currentChunk;
            TEAVM_FIELD(teavm_local_3, cls_otr_FreeChunk, fld_classReference) = INT32_C(0);
            TEAVM_FIELD(teavm_local_3, cls_otr_FreeChunk, fld_size) = ((int32_t) (((int64_t) (intptr_t) sfld_otr_GC_currentChunkLimit) - ((int64_t) (intptr_t) sfld_otr_GC_currentChunk)));
        }
        teavm_local_4 = (sfld_otr_GC_freeChunks - INT32_C(1));
        sfld_otr_GC_freeChunks = teavm_local_4;
        if ((!teavm_local_4)) {
            goto teavm_label_2;
        }
        teavm_local_5 = TEAVM_STRUCTURE_ADD(cls_otr_FreeChunkHolder, sfld_otr_GC_currentChunkPointer, INT32_C(1));
        sfld_otr_GC_currentChunkPointer = teavm_local_5;
        teavm_local_5 = TEAVM_FIELD(teavm_local_5, cls_otr_FreeChunkHolder, fld_value);
        sfld_otr_GC_currentChunk = teavm_local_5;
        teavm_local_4 = TEAVM_FIELD(teavm_local_5, cls_otr_FreeChunk, fld_size);
        if ((teavm_local_4 >= teavm_local_2)) {
            goto teavm_label_1;
        }
        if ((teavm_local_4 == teavm_local_1)) {
            goto teavm_label_1;
        }
        sfld_otr_GC_freeMemory = (sfld_otr_GC_freeMemory - teavm_local_4);
    }
teavm_label_2:;
    return INT32_C(0);
teavm_label_1:;
    sfld_otr_GC_currentChunkLimit = TEAVM_ADDRESS_ADD(teavm_local_5, TEAVM_FIELD(sfld_otr_GC_currentChunk, cls_otr_FreeChunk, fld_size));
    return INT32_C(1);
}
void teavm_gc_collect() {
    teavm_gc_fixHeap();
    meth_otr_GC_collectGarbageImpl(INT32_C(0));
}
void teavm_gc_collectFull() {
    teavm_gc_fixHeap();
    meth_otr_GC_collectGarbageFullImpl(INT32_C(0));
}
void meth_otr_GC_collectGarbageFullImpl(int32_t teavm_local_1) {
    meth_otr_GC_triggerFullGC();
    meth_otr_GC_collectGarbageImpl(teavm_local_1);
}
void meth_otr_GC_triggerFullGC() {
    int32_t teavm_local_1;
    sfld_otr_GC_isFullGC = INT32_C(1);
    teavm_local_1 = meth_otr_GC_getRegionCount();
    memset(teavm_gc_cardTable, INT32_C(0), meth_otr_GC_getRegionCount());
    memset(teavm_gc_regionsAddress, INT32_C(0), (teavm_local_1 * sizeof(cls_otr_GC_Region)));
}
void meth_otr_GC_collectGarbageImpl(int32_t teavm_local_1) {
    int64_t teavm_local_2;
    int32_t teavm_local_3;
    void* teavm_local_4;
    meth_otr_GC_doCollectGarbage();
    teavm_local_2 = INT64_C(0);
    if ((!meth_otr_GC_hasAvailableChunk(teavm_local_1))) {
        teavm_local_2 = meth_otr_GC_computeMinRequestedSize(teavm_local_1);
    }
    if (sfld_otr_GC_isFullGC) {
        sfld_otr_GC_youngGCCount = INT32_C(0);
    } else {
        teavm_local_3 = ((!1) ? INT32_C(8) : INT32_C(2));
        teavm_local_1 = (sfld_otr_GC_youngGCCount + INT32_C(1));
        sfld_otr_GC_youngGCCount = teavm_local_1;
        if (((teavm_local_1 >= teavm_local_3) && meth_otr_GC_isAboutToExpand(teavm_local_2))) {
            meth_otr_GC_triggerFullGC();
            meth_otr_GC_doCollectGarbage();
            sfld_otr_GC_youngGCCount = INT32_C(0);
        }
    }
    sfld_otr_GC_isFullGC = INT32_C(0);
    meth_otr_GC_resizeHeapIfNecessary(teavm_local_2);
    teavm_local_4 = TEAVM_FIELD(sfld_otr_GC_currentChunkPointer, cls_otr_FreeChunkHolder, fld_value);
    sfld_otr_GC_currentChunk = teavm_local_4;
    sfld_otr_GC_currentChunkLimit = TEAVM_ADDRESS_ADD(teavm_local_4, TEAVM_FIELD(sfld_otr_GC_currentChunk, cls_otr_FreeChunk, fld_size));
    memset(teavm_gc_cardTable, INT32_C(1), meth_otr_GC_getRegionCount());
}
void meth_otr_GC_doCollectGarbage() {
    teavm_gc_gcStarted(sfld_otr_GC_isFullGC);
    if ((!sfld_otr_GC_isFullGC)) {
        meth_otr_GC_storeGapsInCardTable();
    }
    meth_otr_GC_mark();
    meth_otr_GC_processReferences();
    meth_otr_GC_processDirectBuffers();
    meth_otr_GC_processStringPool();
    meth_otr_GC_sweep();
    meth_otr_GC_defragment();
    meth_otr_GC_updateFreeMemory();
    teavm_gc_gcCompleted();
    sfld_otr_GC_totalChunks = sfld_otr_GC_freeChunks;
}
int32_t meth_otr_GC_hasAvailableChunk(int32_t teavm_local_1) {
    void* teavm_local_2;
    int32_t teavm_local_3;
    int32_t teavm_local_4;
    int32_t teavm_local_5;
    if (teavm_local_1) {
        teavm_local_2 = sfld_otr_GC_currentChunkPointer;
        teavm_local_3 = INT32_C(0);
        teavm_local_4 = (teavm_local_1 + INT32_C(8));
        while (1) {
            if (!(teavm_local_3 < sfld_otr_GC_freeChunks)) break;
            teavm_local_5 = TEAVM_FIELD(TEAVM_FIELD(teavm_local_2, cls_otr_FreeChunkHolder, fld_value), cls_otr_FreeChunk, fld_size);
            if ((teavm_local_1 == teavm_local_5)) {
                goto teavm_label_1;
            }
            if ((teavm_local_4 <= teavm_local_5)) {
                goto teavm_label_1;
            }
            teavm_local_2 = TEAVM_STRUCTURE_ADD(cls_otr_FreeChunkHolder, teavm_local_2, INT32_C(1));
            teavm_local_3 = (teavm_local_3 + INT32_C(1));
        }
        return INT32_C(0);
    teavm_label_1:;
        return INT32_C(1);
    }
    return INT32_C(1);
}
int64_t meth_otr_GC_computeMinRequestedSize(int32_t teavm_local_1) {
    void* teavm_local_2;
    teavm_local_2 = sfld_otr_GC_lastChunk;
    if ((!TEAVM_FIELD(teavm_local_2, cls_otr_FreeChunk, fld_classReference))) {
        teavm_local_1 = (teavm_local_1 - TEAVM_FIELD(teavm_local_2, cls_otr_FreeChunk, fld_size));
    }
    return (teavm_gc_availableBytes + ((int64_t) teavm_local_1));
}
void teavm_gc_fixHeap() {
    void* teavm_local_1;
    if ((sfld_otr_GC_freeChunks > INT32_C(0))) {
        teavm_local_1 = sfld_otr_GC_currentChunk;
        TEAVM_FIELD(teavm_local_1, cls_otr_FreeChunk, fld_classReference) = INT32_C(0);
        TEAVM_FIELD(teavm_local_1, cls_otr_FreeChunk, fld_size) = ((int32_t) (((int64_t) (intptr_t) sfld_otr_GC_currentChunkLimit) - ((int64_t) (intptr_t) sfld_otr_GC_currentChunk)));
    }
}
void teavm_gc_tryShrink() {
    int64_t teavm_local_1;
    teavm_local_1 = teavm_gc_availableBytes;
    if (((teavm_local_1 - ((int64_t) sfld_otr_GC_freeMemory)) < (teavm_local_1 / INT64_C(4)))) {
        teavm_gc_collectFull();
    }
}
void meth_otr_GC_mark() {
    teavm_gc_markStarted();
    sfld_otr_GC_firstWeakReference = NULL;
    meth_otr_GC_markFromStaticFields();
    meth_otr_GC_markFromClasses();
    meth_otr_GC_markFromStack();
    if ((!sfld_otr_GC_isFullGC)) {
        meth_otr_GC_markFromOldGeneration();
    }
    teavm_gc_markCompleted();
}
void meth_otr_GC_markFromStaticFields() {
    void* teavm_local_1;
    int32_t teavm_local_2;
    int32_t teavm_local_3;
    void* teavm_local_4;
    teavm_local_1 = teavm_gc_staticRoots;
    teavm_local_2 = (*(int32_t*) teavm_local_1);
    teavm_local_1 = TEAVM_ADDRESS_ADD(teavm_local_1, sizeof(void*));
    while (1) {
        teavm_local_3 = (teavm_local_2 + -INT32_C(1));
        if ((teavm_local_2 <= INT32_C(0))) {
            goto teavm_label_1;
        }
        teavm_local_4 = (*(void**) (*(void**) teavm_local_1));
        if ((teavm_local_4 != NULL)) {
            meth_otr_GC_mark_0(teavm_local_4);
        }
        teavm_local_1 = TEAVM_ADDRESS_ADD(teavm_local_1, sizeof(void*));
        teavm_local_2 = teavm_local_3;
    }
teavm_label_1:;
}
void meth_otr_GC_markFromClasses() {
    void* teavm_local_1;
    teavm_local_1 = teavm_firstClass;
    while (1) {
        if (!(teavm_local_1 != NULL)) break;
        meth_otr_GC_markFromClass(teavm_local_1);
        teavm_local_1 = TEAVM_FIELD(teavm_local_1, TeaVM_Class, next);
    }
}
void meth_otr_GC_markFromClass(void* teavm_local_1) {
    teavm_local_1 = TEAVM_FIELD(teavm_local_1, TeaVM_Class, classObject);
    if ((teavm_local_1 != NULL)) {
        meth_otr_GC_mark_0(teavm_local_1);
    }
}
void meth_otr_GC_markFromStack() {
    void* teavm_local_1;
    int32_t teavm_local_2;
    void* teavm_local_3;
    int32_t teavm_local_4;
    teavm_local_1 = teavm_stackTop;
    while (1) {
        if (!(teavm_local_1 != NULL)) break;
        teavm_local_2 = TEAVM_GC_ROOTS_COUNT(teavm_local_1);
        teavm_local_3 = TEAVM_GET_GC_ROOTS(teavm_local_1);
        while (1) {
            teavm_local_4 = (teavm_local_2 + -INT32_C(1));
            if ((teavm_local_2 <= INT32_C(0))) {
                goto teavm_label_2;
            }
            meth_otr_GC_mark_0((*(void**) teavm_local_3));
            teavm_local_3 = TEAVM_ADDRESS_ADD(teavm_local_3, sizeof(void*));
            teavm_local_2 = teavm_local_4;
        }
    teavm_label_2:;
        teavm_local_1 = TEAVM_GET_NEXT_FRAME(teavm_local_1);
    }
}
void meth_otr_GC_markFromOldGeneration() {
    int32_t teavm_local_1;
    int32_t teavm_local_2;
    void* teavm_local_3;
    void* teavm_local_4;
    int32_t teavm_local_5;
    int32_t teavm_local_6;
    int32_t teavm_local_7;
    int32_t teavm_local_8;
    teavm_local_1 = meth_otr_GC_getRegionCount();
    teavm_local_2 = teavm_gc_regionSize;
    teavm_local_3 = teavm_gc_cardTable;
    teavm_local_4 = teavm_gc_heapAddress;
    teavm_local_5 = INT32_C(0);
    teavm_local_6 = (teavm_local_1 - INT32_C(3));
    teavm_local_7 = (INT32_C(4) * teavm_local_2);
    while (1) {
        if (!(teavm_local_5 < teavm_local_6)) break;
        if ((((*(int32_t*) teavm_local_3) & INT32_C(16843009)) != INT32_C(16843009))) {
            teavm_local_8 = INT32_C(0);
            while (1) {
                if ((teavm_local_8 >= INT32_C(4))) {
                    goto teavm_label_2;
                }
                if ((!(((int32_t) *(int8_t*) TEAVM_ADDRESS_ADD(teavm_local_3, teavm_local_8)) & INT32_C(1)))) {
                    meth_otr_GC_markFromRegion((teavm_local_5 + teavm_local_8));
                }
                teavm_local_8 = (teavm_local_8 + INT32_C(1));
            }
        }
    teavm_label_2:;
        teavm_local_3 = TEAVM_ADDRESS_ADD(teavm_local_3, INT32_C(4));
        teavm_local_4 = TEAVM_ADDRESS_ADD(teavm_local_4, teavm_local_7);
        teavm_local_5 = (teavm_local_5 + INT32_C(4));
    }
    while (1) {
        if (!(teavm_local_5 < teavm_local_1)) break;
        if ((!(((int32_t) *(int8_t*) teavm_local_3) & INT32_C(1)))) {
            meth_otr_GC_markFromRegion(teavm_local_5);
        }
        teavm_local_3 = TEAVM_ADDRESS_ADD(teavm_local_3, INT32_C(1));
        teavm_local_5 = (teavm_local_5 + INT32_C(1));
    }
}
void meth_otr_GC_markFromRegion(int32_t teavm_local_1) {
    void* teavm_local_2;
    int32_t teavm_local_3;
    int32_t teavm_local_4;
    void* teavm_local_5;
    void* teavm_local_6;
    void* teavm_local_7;
    void* teavm_local_8;
    int32_t teavm_local_9;
    int32_t teavm_local_10;
    teavm_local_2 = TEAVM_ADDRESS_ADD(teavm_gc_cardTable, teavm_local_1);
    teavm_local_3 = TEAVM_FIELD(TEAVM_STRUCTURE_ADD(cls_otr_GC_Region, teavm_gc_regionsAddress, teavm_local_1), cls_otr_GC_Region, fld_start);
    if (teavm_local_3) {
        teavm_local_3 = (teavm_local_3 + -INT32_C(1));
        teavm_local_4 = teavm_gc_regionSize;
        teavm_local_5 = TEAVM_ADDRESS_ADD(teavm_gc_heapAddress, (teavm_local_1 * teavm_local_4));
        teavm_gc_reportDirtyRegion(teavm_local_5);
        teavm_local_6 = TEAVM_ADDRESS_ADD(teavm_local_5, teavm_local_4);
        teavm_local_7 = TEAVM_ADDRESS_ADD(teavm_local_5, teavm_local_3);
        teavm_local_8 = TEAVM_ADDRESS_ADD(teavm_gc_heapAddress, teavm_gc_availableBytes);
        if ((!((uintptr_t) teavm_local_8 < (uintptr_t) teavm_local_6))) {
            teavm_local_8 = teavm_local_6;
        }
        teavm_local_9 = INT32_C(0);
        while (1) {
            if (!((uintptr_t) teavm_local_7 < (uintptr_t) teavm_local_8)) break;
            teavm_local_10 = TEAVM_FIELD(teavm_local_7, cls_otr_FreeChunk, fld_classReference);
            if ((teavm_local_10 && (teavm_local_10 & INT32_C(1073741824)))) {
                teavm_local_9 = (teavm_local_9 | meth_otr_GC_doMarkOldGeneration(teavm_local_7));
            }
            teavm_local_7 = TEAVM_ADDRESS_ADD(teavm_local_7, meth_otr_GC_objectSize(teavm_local_7));
        }
        if ((!teavm_local_9)) {
            (*(int8_t*) teavm_local_2 = (int8_t) TEAVM_TO_BYTE((((int32_t) *(int8_t*) teavm_local_2) | INT32_C(1))));
        }
        return;
    }
    (*(int8_t*) teavm_local_2 = (int8_t) TEAVM_TO_BYTE((((int32_t) *(int8_t*) teavm_local_2) | INT32_C(1))));
}
void meth_otr_GC_mark_0(void* teavm_local_1) {
    if (((teavm_local_1 != NULL) && (!meth_otr_GC_isMarked(teavm_local_1)))) {
        meth_otr_MarkQueue_init();
        meth_otr_GC_enqueueMark(teavm_local_1);
        meth_otr_GC_doProcessMarkQueue();
        return;
    }
}
int32_t meth_otr_GC_doMarkOldGeneration(void* teavm_local_1) {
    int32_t teavm_local_2;
    meth_otr_MarkQueue_init();
    teavm_local_2 = meth_otr_GC_markObjectData(teavm_local_1);
    meth_otr_GC_doProcessMarkQueue();
    return teavm_local_2;
}
void meth_otr_GC_doProcessMarkQueue() {
    void* teavm_local_1;
    int64_t teavm_local_2;
    void* teavm_local_3;
    int32_t teavm_local_4;
    int32_t teavm_local_5;
    void* teavm_local_6;
    while (1) {
        if (!(!meth_otr_MarkQueue_isEmpty())) break;
        teavm_local_1 = meth_otr_MarkQueue_dequeue();
        teavm_gc_mark(teavm_local_1);
        teavm_local_2 = (((int64_t) (intptr_t) teavm_local_1) - ((int64_t) (intptr_t) teavm_gc_heapAddress));
        teavm_local_3 = TEAVM_STRUCTURE_ADD(cls_otr_GC_Region, teavm_gc_regionsAddress, ((int32_t) (teavm_local_2 / ((int64_t) teavm_gc_regionSize))));
        teavm_local_4 = TEAVM_TO_SHORT(((int32_t) ((teavm_local_2 % ((int64_t) teavm_gc_regionSize)) + INT64_C(1))));
        teavm_local_5 = TEAVM_FIELD(teavm_local_3, cls_otr_GC_Region, fld_start);
        if ((!(teavm_local_5 && (teavm_local_5 <= teavm_local_4)))) {
            TEAVM_FIELD(teavm_local_3, cls_otr_GC_Region, fld_start) = teavm_local_4;
        }
        teavm_local_6 = TEAVM_ADDRESS_ADD(teavm_gc_cardTable, (teavm_local_2 / ((int64_t) teavm_gc_regionSize)));
        (*(int8_t*) teavm_local_6 = (int8_t) TEAVM_TO_BYTE((((int32_t) *(int8_t*) teavm_local_6) | INT32_C(2))));
        meth_otr_GC_markObjectData(teavm_local_1);
    }
}
int32_t meth_otr_GC_markObjectData(void* teavm_local_1) {
    void* teavm_local_2;
    teavm_local_2 = meth_otr_RuntimeClass_getClass(teavm_local_1);
    if ((TEAVM_FIELD(teavm_local_2, TeaVM_Class, itemType) != NULL)) {
        return meth_otr_GC_markArray(teavm_local_2, teavm_local_1);
    }
    return meth_otr_GC_markObject(teavm_local_2, teavm_local_1);
}
int32_t meth_otr_GC_markObject(void* teavm_local_1, void* teavm_local_2) {
    int32_t teavm_local_3;
    teavm_local_3 = INT32_C(0);
    while (1) {
        if (!(teavm_local_1 != NULL)) break;
        switch (((TEAVM_FIELD(teavm_local_1, TeaVM_Class, flags) >> INT32_C(1)) & INT32_C(7))) {
            case 1:
                goto teavm_label_4;
            case 2:
                goto teavm_label_3;
            case 3:
                goto teavm_label_6;
            default:
                goto teavm_label_5;
        }
    teavm_label_6:;
        goto teavm_label_2;
    teavm_label_5:;
        teavm_local_3 = (teavm_local_3 | meth_otr_GC_markFields(teavm_local_1, teavm_local_2));
        goto teavm_label_2;
    teavm_label_4:;
        teavm_local_3 = (teavm_local_3 | meth_otr_GC_markWeakReference(teavm_local_2));
        goto teavm_label_2;
    teavm_label_3:;
        teavm_local_3 = (teavm_local_3 | meth_otr_GC_markReferenceQueue(teavm_local_2));
    teavm_label_2:;
        teavm_local_1 = TEAVM_FIELD(teavm_local_1, TeaVM_Class, superclass);
    }
    return teavm_local_3;
}
int32_t meth_otr_GC_markWeakReference(void* teavm_local_1) {
    int32_t teavm_local_2;
    void* teavm_local_3;
    teavm_local_2 = INT32_C(0);
    teavm_local_3 = TEAVM_FIELD(teavm_local_1, TeaVM_Reference, queue);
    if ((teavm_local_3 != NULL)) {
        teavm_local_2 = (teavm_local_2 | meth_otr_GC_enqueueMark(teavm_local_3));
        if ((TEAVM_FIELD(teavm_local_1, TeaVM_Reference, next) != NULL)) {
            teavm_local_3 = TEAVM_FIELD(teavm_local_1, TeaVM_Reference, object);
            if ((teavm_local_3 != NULL)) {
                teavm_local_2 = (teavm_local_2 | meth_otr_GC_enqueueMark(teavm_local_3));
            }
        }
    }
    teavm_local_3 = TEAVM_FIELD(teavm_local_1, TeaVM_Reference, next);
    if ((teavm_local_3 != NULL)) {
        teavm_local_2 = (teavm_local_2 | meth_otr_GC_enqueueMark(teavm_local_3));
    } else if ((TEAVM_FIELD(teavm_local_1, TeaVM_Reference, object) != NULL)) {
        TEAVM_FIELD(teavm_local_1, TeaVM_Reference, next) = sfld_otr_GC_firstWeakReference;
        sfld_otr_GC_firstWeakReference = teavm_local_1;
    }
    return teavm_local_2;
}
int32_t meth_otr_GC_markReferenceQueue(void* teavm_local_1) {
    void* teavm_local_2;
    int32_t teavm_local_3;
    teavm_local_2 = TEAVM_FIELD(teavm_local_1, TeaVM_ReferenceQueue, first);
    teavm_local_3 = INT32_C(0);
    if ((teavm_local_2 != NULL)) {
        teavm_local_3 = (teavm_local_3 | meth_otr_GC_enqueueMark(teavm_local_2));
    }
    return teavm_local_3;
}
int32_t meth_otr_GC_markFields(void* teavm_local_1, void* teavm_local_2) {
    void* teavm_local_3;
    int32_t teavm_local_4;
    int32_t teavm_local_5;
    int32_t teavm_local_6;
    int32_t teavm_local_7;
    teavm_local_3 = TEAVM_FIELD(teavm_local_1, TeaVM_Class, layout);
    if ((teavm_local_3 != NULL)) {
        teavm_local_4 = INT32_C(0);
        teavm_local_5 = ((int32_t) *(int16_t*) teavm_local_3);
        while (1) {
            teavm_local_6 = TEAVM_TO_SHORT((teavm_local_5 - INT32_C(1)));
            if ((teavm_local_5 <= INT32_C(0))) {
                goto teavm_label_1;
            }
            teavm_local_3 = TEAVM_ADDRESS_ADD(teavm_local_3, INT32_C(2));
            teavm_local_7 = ((int32_t) *(int16_t*) teavm_local_3);
            teavm_local_4 = (teavm_local_4 | meth_otr_GC_enqueueMark((*(void**) TEAVM_ADDRESS_ADD(teavm_local_2, teavm_local_7))));
            teavm_local_5 = teavm_local_6;
        }
    teavm_label_1:;
        return teavm_local_4;
    }
    return INT32_C(0);
}
int32_t meth_otr_GC_markArray(void* teavm_local_1, void* teavm_local_2) {
    void* teavm_local_3;
    int32_t teavm_local_4;
    int32_t teavm_local_5;
    if ((!meth_otr_RuntimeClass_isPrimitive(TEAVM_FIELD(teavm_local_1, TeaVM_Class, itemType)))) {
        teavm_local_3 = TEAVM_ALIGN(TEAVM_ADDRESS_ADD(teavm_local_2, INT32_C(1) * sizeof(TeaVM_Array)), sizeof(void*));
        teavm_local_4 = INT32_C(0);
        teavm_local_5 = INT32_C(0);
        while (1) {
            if (!(teavm_local_5 < TEAVM_FIELD(teavm_local_2, TeaVM_Array, size))) break;
            teavm_local_4 = (teavm_local_4 | meth_otr_GC_enqueueMark((*(void**) teavm_local_3)));
            teavm_local_3 = TEAVM_ADDRESS_ADD(teavm_local_3, sizeof(void*));
            teavm_local_5 = (teavm_local_5 + INT32_C(1));
        }
        return teavm_local_4;
    }
    return INT32_C(0);
}
int32_t meth_otr_GC_enqueueMark(void* teavm_local_1) {
    if ((teavm_local_1 != NULL)) {
        if (meth_otr_GC_isMarked(teavm_local_1)) {
            return ((TEAVM_FIELD(teavm_local_1, TeaVM_Object, header) & INT32_C(1073741824)) ? INT32_C(0) : INT32_C(1));
        }
        meth_otr_GC_doEnqueueMark(teavm_local_1);
        return INT32_C(1);
    }
    return INT32_C(0);
}
void meth_otr_GC_doEnqueueMark(void* teavm_local_1) {
    if ((!sfld_otr_GC_isFullGC)) {
        TEAVM_FIELD(teavm_local_1, TeaVM_Object, header) = (TEAVM_FIELD(teavm_local_1, TeaVM_Object, header) | (int32_t) INT32_C(0x80000000));
    } else {
        TEAVM_FIELD(teavm_local_1, TeaVM_Object, header) = (TEAVM_FIELD(teavm_local_1, TeaVM_Object, header) | -INT32_C(1073741824));
    }
    meth_otr_MarkQueue_enqueue(teavm_local_1);
}
void meth_otr_GC_processReferences() {
    void* teavm_local_1;
    void* teavm_local_2;
    void* teavm_local_3;
    void* teavm_local_4;
    teavm_local_1 = sfld_otr_GC_firstWeakReference;
    while (1) {
        if (!(teavm_local_1 != NULL)) break;
        teavm_local_2 = TEAVM_FIELD(teavm_local_1, TeaVM_Reference, next);
        TEAVM_FIELD(teavm_local_1, TeaVM_Reference, next) = NULL;
        if ((!meth_otr_GC_isMarked(TEAVM_FIELD(teavm_local_1, TeaVM_Reference, object)))) {
            TEAVM_FIELD(teavm_local_1, TeaVM_Reference, object) = NULL;
            teavm_local_3 = TEAVM_FIELD(teavm_local_1, TeaVM_Reference, queue);
            if ((teavm_local_3 != NULL)) {
                if ((TEAVM_FIELD(teavm_local_3, TeaVM_ReferenceQueue, first) == NULL)) {
                    TEAVM_FIELD(teavm_local_3, TeaVM_ReferenceQueue, first) = teavm_local_1;
                } else {
                    teavm_local_4 = TEAVM_FIELD(teavm_local_3, TeaVM_ReferenceQueue, last);
                    TEAVM_FIELD(teavm_local_4, TeaVM_Reference, next) = teavm_local_1;
                    meth_otr_GC_makeInvalid(teavm_local_4);
                }
                TEAVM_FIELD(teavm_local_3, TeaVM_ReferenceQueue, last) = teavm_local_1;
                meth_otr_GC_makeInvalid(teavm_local_3);
            }
        }
        teavm_local_1 = teavm_local_2;
    }
}
void meth_otr_GC_makeInvalid(void* teavm_local_1) {
    int64_t teavm_local_2;
    void* teavm_local_3;
    teavm_local_2 = (((int64_t) (intptr_t) teavm_local_1) - ((int64_t) (intptr_t) teavm_gc_heapAddress));
    teavm_local_3 = TEAVM_ADDRESS_ADD(teavm_gc_cardTable, (teavm_local_2 / ((int64_t) teavm_gc_regionSize)));
    (*(int8_t*) teavm_local_3 = (int8_t) TEAVM_TO_BYTE((((int32_t) *(int8_t*) teavm_local_3) & -INT32_C(2))));
}
void meth_otr_GC_processDirectBuffers() {
    void* teavm_local_1;
    void* teavm_local_2;
    void* teavm_local_3;
    teavm_local_1 = sfld_otr_GC_firstDirectBuffer;
    teavm_local_2 = NULL;
    while (1) {
        if (!(teavm_local_1 != NULL)) break;
        teavm_local_3 = TEAVM_FIELD(teavm_local_1, cls_otr_RuntimeBuffer, fld_nextRef);
        if ((!(TEAVM_FIELD(teavm_local_1, TeaVM_Object, header) & (int32_t) INT32_C(0x80000000)))) {
            meth_otr_GC_freeBufferContent(teavm_local_1);
        } else {
            if ((teavm_local_2 != NULL)) {
                TEAVM_FIELD(teavm_local_2, cls_otr_RuntimeBuffer, fld_nextRef) = teavm_local_1;
            } else {
                sfld_otr_GC_firstDirectBuffer = teavm_local_1;
            }
            teavm_local_2 = teavm_local_1;
        }
        teavm_local_1 = teavm_local_3;
    }
    if ((teavm_local_2 != NULL)) {
        TEAVM_FIELD(teavm_local_2, cls_otr_RuntimeBuffer, fld_nextRef) = NULL;
    } else {
        sfld_otr_GC_firstDirectBuffer = NULL;
    }
}
void meth_otr_GC_freeBufferContent(void* teavm_local_1) {
    void* teavm_local_2;
    void* teavm_local_3;
    int32_t teavm_local_4;
    void* teavm_local_5;
    teavm_local_2 = meth_otr_RuntimeClass_getClass(teavm_local_1);
    while (1) {
        if (!(teavm_local_2 != NULL)) break;
        teavm_local_3 = TEAVM_FIELD(teavm_local_2, TeaVM_Class, enumValues);
        if ((teavm_local_3 != NULL)) {
            teavm_local_4 = ((int32_t) (intptr_t) teavm_local_3);
            teavm_local_5 = (*(void**) TEAVM_ADDRESS_ADD(TEAVM_ADDRESS_ADD(teavm_local_1, teavm_local_4), sizeof(void*)));
            if ((teavm_local_5 == NULL)) {
                meth_otr_GC_free(teavm_local_5);
            }
            return;
        }
        teavm_local_2 = TEAVM_FIELD(teavm_local_2, TeaVM_Class, superclass);
    }
}
void meth_otr_GC_processStringPool() {
    void* teavm_local_1;
    teavm_stringHashtableRewind();
    while (1) {
        teavm_local_1 = teavm_stringHashtableCurrent();
        if ((teavm_local_1 == NULL)) {
            goto teavm_label_1;
        }
        if (meth_otr_GC_isMarked(teavm_local_1)) {
            teavm_stringHashtableNext();
        } else {
            teavm_stringHashtableDelete();
        }
    }
teavm_label_1:;
}
void meth_otr_GC_sweep() {
    void* teavm_local_1;
    void* teavm_local_2;
    int64_t teavm_local_3;
    int32_t teavm_local_4;
    void* teavm_local_5;
    void* teavm_local_6;
    int32_t teavm_local_7;
    int32_t teavm_local_8;
    int32_t teavm_local_9;
    void* teavm_local_10;
    void* teavm_local_11;
    int32_t teavm_local_12;
    int32_t teavm_local_13;
    teavm_gc_sweepStarted();
    sfld_otr_GC_currentChunkPointer = teavm_gc_gcStorageAddress;
    sfld_otr_GC_freeChunks = INT32_C(0);
    sfld_otr_GC_totalChunks = INT32_C(0);
    teavm_local_1 = teavm_gc_heapAddress;
    teavm_local_2 = NULL;
    teavm_local_3 = teavm_gc_availableBytes;
    teavm_local_4 = meth_otr_GC_getRegionCount();
    teavm_local_5 = NULL;
    teavm_local_6 = TEAVM_ADDRESS_ADD(teavm_gc_heapAddress, teavm_local_3);
    while (1) {
        if (!((uintptr_t) teavm_local_1 < (uintptr_t) teavm_local_6)) break;
        teavm_local_7 = TEAVM_FIELD(teavm_local_1, cls_otr_FreeChunk, fld_classReference);
        if ((!teavm_local_7)) {
            teavm_local_8 = INT32_C(1);
        } else {
            teavm_local_8 = ((teavm_local_7 & (int32_t) INT32_C(0x80000000)) ? INT32_C(0) : INT32_C(1));
            if ((teavm_local_8 && ((!sfld_otr_GC_isFullGC) && (teavm_local_7 & INT32_C(1073741824))))) {
                teavm_local_8 = INT32_C(0);
            }
            if ((!teavm_local_8)) {
                teavm_local_7 = (teavm_local_7 & INT32_C(2147483647));
            }
            TEAVM_FIELD(teavm_local_1, cls_otr_FreeChunk, fld_classReference) = teavm_local_7;
        }
        if (teavm_local_8) {
            if ((teavm_local_2 == NULL)) {
                teavm_local_2 = teavm_local_1;
            }
            if (((uintptr_t) teavm_local_1 < (uintptr_t) teavm_local_5)) {
                goto teavm_label_4;
            }
            teavm_local_9 = ((int32_t) ((((int64_t) (intptr_t) teavm_local_1) - ((int64_t) (intptr_t) teavm_gc_heapAddress)) / ((int64_t) teavm_gc_regionSize)));
            teavm_local_10 = TEAVM_STRUCTURE_ADD(cls_otr_GC_Region, teavm_gc_regionsAddress, teavm_local_9);
            teavm_local_5 = TEAVM_ADDRESS_ADD(teavm_gc_heapAddress, ((teavm_local_9 + INT32_C(1)) * teavm_gc_regionSize));
            if (TEAVM_FIELD(teavm_local_10, cls_otr_GC_Region, fld_start)) {
                goto teavm_label_4;
            }
            while (1) {
                teavm_local_9 = (teavm_local_9 + INT32_C(1));
                if ((teavm_local_9 == teavm_local_4)) {
                    goto teavm_label_2;
                }
                teavm_local_10 = TEAVM_STRUCTURE_ADD(cls_otr_GC_Region, teavm_gc_regionsAddress, teavm_local_9);
                if (TEAVM_FIELD(teavm_local_10, cls_otr_GC_Region, fld_start)) {
                    goto teavm_label_5;
                }
            }
        teavm_label_5:;
            teavm_local_11 = TEAVM_ADDRESS_ADD(teavm_gc_heapAddress, (teavm_local_9 * teavm_gc_regionSize));
            teavm_local_1 = TEAVM_ADDRESS_ADD(teavm_local_11, (TEAVM_FIELD(teavm_local_10, cls_otr_GC_Region, fld_start) - INT32_C(1)));
            teavm_local_5 = TEAVM_ADDRESS_ADD(teavm_local_11, teavm_gc_regionSize);
            goto teavm_cnt_3;
        }
        if ((teavm_local_2 != NULL)) {
            meth_otr_GC_freeMemory(teavm_local_2, teavm_local_1);
            teavm_local_2 = NULL;
        }
        if ((!((uintptr_t) teavm_local_1 < (uintptr_t) teavm_local_5))) {
            teavm_local_12 = ((int32_t) ((((int64_t) (intptr_t) teavm_local_1) - ((int64_t) (intptr_t) teavm_gc_heapAddress)) / ((int64_t) teavm_gc_regionSize)));
            teavm_local_5 = TEAVM_ADDRESS_ADD(teavm_gc_heapAddress, ((teavm_local_12 + INT32_C(1)) * teavm_gc_regionSize));
            if (((!sfld_otr_GC_isFullGC) && ((!(((int32_t) *(int8_t*) TEAVM_ADDRESS_ADD(teavm_gc_cardTable, teavm_local_12)) & INT32_C(2))) && (!(((int32_t) *(int8_t*) TEAVM_ADDRESS_ADD(teavm_gc_cardTable, teavm_local_12)) & INT32_C(4)))))) {
                while (1) {
                    teavm_local_12 = (teavm_local_12 + INT32_C(1));
                    if ((teavm_local_12 == teavm_local_4)) {
                        goto teavm_label_7;
                    }
                    if ((!TEAVM_FIELD(TEAVM_STRUCTURE_ADD(cls_otr_GC_Region, teavm_gc_regionsAddress, teavm_local_12), cls_otr_GC_Region, fld_start))) {
                        goto teavm_label_6;
                    }
                    if ((((int32_t) *(int8_t*) TEAVM_ADDRESS_ADD(teavm_gc_cardTable, teavm_local_12)) & INT32_C(2))) {
                        goto teavm_label_6;
                    }
                    if ((((int32_t) *(int8_t*) TEAVM_ADDRESS_ADD(teavm_gc_cardTable, teavm_local_12)) & INT32_C(4))) {
                        goto teavm_label_6;
                    }
                }
            teavm_label_7:;
            teavm_label_6:;
                teavm_local_9 = (teavm_local_12 + -INT32_C(1));
                teavm_local_10 = TEAVM_STRUCTURE_ADD(cls_otr_GC_Region, teavm_gc_regionsAddress, teavm_local_9);
                teavm_local_11 = TEAVM_ADDRESS_ADD(teavm_gc_heapAddress, (teavm_local_9 * teavm_gc_regionSize));
                teavm_local_10 = TEAVM_ADDRESS_ADD(teavm_local_11, (TEAVM_FIELD(teavm_local_10, cls_otr_GC_Region, fld_start) - INT32_C(1)));
                teavm_local_5 = TEAVM_ADDRESS_ADD(teavm_local_11, teavm_gc_regionSize);
                if (((uintptr_t) teavm_local_1 < (uintptr_t) teavm_local_10)) {
                    teavm_local_1 = teavm_local_10;
                    goto teavm_cnt_3;
                }
                teavm_local_1 = teavm_local_10;
            }
        }
    teavm_label_4:;
        teavm_local_13 = meth_otr_GC_objectSize(teavm_local_1);
        teavm_local_1 = TEAVM_ADDRESS_ADD(teavm_local_1, teavm_local_13);
    teavm_cnt_3:;
    }
    goto teavm_label_1;
teavm_label_2:;
    teavm_local_1 = teavm_local_6;
teavm_label_1:;
    if ((teavm_local_2 != NULL)) {
        meth_otr_GC_freeMemory(teavm_local_2, teavm_local_1);
    }
    sfld_otr_GC_currentChunkPointer = teavm_gc_gcStorageAddress;
    teavm_gc_sweepCompleted();
}
void meth_otr_GC_storeGapsInCardTable() {
    int32_t teavm_local_1;
    void* teavm_local_2;
    int64_t teavm_local_3;
    int64_t teavm_local_4;
    int32_t teavm_local_5;
    int32_t teavm_local_6;
    void* teavm_local_7;
    teavm_local_1 = INT32_C(0);
    while (1) {
        if (!(teavm_local_1 < sfld_otr_GC_totalChunks)) break;
        teavm_local_2 = TEAVM_FIELD(TEAVM_STRUCTURE_ADD(cls_otr_FreeChunkHolder, teavm_gc_gcStorageAddress, teavm_local_1), cls_otr_FreeChunkHolder, fld_value);
        teavm_local_3 = (((int64_t) (intptr_t) teavm_local_2) - ((int64_t) (intptr_t) teavm_gc_heapAddress));
        teavm_local_4 = (teavm_local_3 + ((int64_t) TEAVM_FIELD(teavm_local_2, cls_otr_FreeChunk, fld_size)));
        teavm_local_5 = ((int32_t) (teavm_local_3 / ((int64_t) teavm_gc_regionSize)));
        teavm_local_6 = ((int32_t) (teavm_local_4 / ((int64_t) teavm_gc_regionSize)));
        while (1) {
            if (!(teavm_local_5 <= teavm_local_6)) break;
            teavm_local_7 = TEAVM_ADDRESS_ADD(teavm_gc_cardTable, teavm_local_5);
            (*(int8_t*) teavm_local_7 = (int8_t) TEAVM_TO_BYTE((((int32_t) *(int8_t*) teavm_local_7) | INT32_C(4))));
            teavm_local_5 = (teavm_local_5 + INT32_C(1));
        }
        teavm_local_1 = (teavm_local_1 + INT32_C(1));
    }
}
void meth_otr_GC_clearGapsFromCardTable() {
    int32_t teavm_local_1;
    void* teavm_local_2;
    int32_t teavm_local_3;
    int32_t teavm_local_4;
    teavm_local_1 = meth_otr_GC_getRegionCount();
    teavm_local_2 = teavm_gc_cardTable;
    teavm_local_3 = INT32_C(0);
    teavm_local_4 = (teavm_local_1 - INT32_C(3));
    while (1) {
        if (!(teavm_local_3 < teavm_local_4)) break;
        (*(int32_t*) teavm_local_2 = ((*(int32_t*) teavm_local_2) & -INT32_C(67372037)));
        teavm_local_2 = TEAVM_ADDRESS_ADD(teavm_local_2, INT32_C(4));
        teavm_local_3 = (teavm_local_3 + INT32_C(4));
    }
    while (1) {
        if (!(teavm_local_3 < teavm_local_1)) break;
        (*(int8_t*) teavm_local_2 = (int8_t) TEAVM_TO_BYTE((((int32_t) *(int8_t*) teavm_local_2) & -INT32_C(5))));
        teavm_local_2 = TEAVM_ADDRESS_ADD(teavm_local_2, INT32_C(1));
        teavm_local_3 = (teavm_local_3 + INT32_C(1));
    }
}
void meth_otr_GC_freeMemory(void* teavm_local_1, void* teavm_local_2) {
    TEAVM_FIELD(teavm_local_1, cls_otr_FreeChunk, fld_classReference) = INT32_C(0);
    TEAVM_FIELD(teavm_local_1, cls_otr_FreeChunk, fld_size) = ((int32_t) (((int64_t) (intptr_t) teavm_local_2) - ((int64_t) (intptr_t) teavm_local_1)));
    teavm_gc_free(teavm_local_1, TEAVM_FIELD(teavm_local_1, cls_otr_FreeChunk, fld_size));
    teavm_local_2 = sfld_otr_GC_currentChunkPointer;
    TEAVM_FIELD(teavm_local_2, cls_otr_FreeChunkHolder, fld_value) = teavm_local_1;
    sfld_otr_GC_currentChunkPointer = TEAVM_STRUCTURE_ADD(cls_otr_FreeChunkHolder, teavm_local_2, INT32_C(1));
    sfld_otr_GC_freeChunks = (sfld_otr_GC_freeChunks + INT32_C(1));
    sfld_otr_GC_totalChunks = (sfld_otr_GC_totalChunks + INT32_C(1));
}
void meth_otr_GC_defragment() {
    teavm_gc_defragStarted();
    meth_otr_GC_clearGapsFromCardTable();
    meth_otr_GC_storeGapsInCardTable();
    meth_otr_GC_markStackRoots();
    meth_otr_GC_moveNonRelocatableObjectsToOldGeneration();
    meth_otr_GC_calculateRelocationTargets();
    meth_otr_GC_updatePointersFromStaticRoots();
    meth_otr_GC_updatePointersFromClasses();
    meth_otr_GC_updatePointersFromObjects();
    meth_otr_GC_updatePointersFromStringPool();
    meth_otr_GC_restoreObjectHeaders();
    meth_otr_GC_relocateObjects();
    meth_otr_GC_putNewFreeChunks();
    teavm_gc_defragCompleted();
}
void meth_otr_GC_markStackRoots() {
    void* teavm_local_1;
    void* teavm_local_2;
    int32_t teavm_local_3;
    void* teavm_local_4;
    int32_t teavm_local_5;
    void* teavm_local_6;
    teavm_local_1 = TEAVM_FIELD(sfld_otr_GC_currentChunkPointer, cls_otr_FreeChunkHolder, fld_value);
    teavm_local_2 = teavm_stackTop;
    while (1) {
        if (!(teavm_local_2 != NULL)) break;
        teavm_local_3 = TEAVM_GC_ROOTS_COUNT(teavm_local_2);
        teavm_local_4 = TEAVM_GET_GC_ROOTS(teavm_local_2);
        while (1) {
            teavm_local_5 = (teavm_local_3 + -INT32_C(1));
            if ((teavm_local_3 <= INT32_C(0))) {
                goto teavm_label_2;
            }
            teavm_local_6 = (*(void**) teavm_local_4);
            if (((!((uintptr_t) teavm_local_6 < (uintptr_t) teavm_local_1)) && (!((!sfld_otr_GC_isFullGC) && (TEAVM_FIELD(teavm_local_6, TeaVM_Object, header) & INT32_C(1073741824)))))) {
                TEAVM_FIELD(teavm_local_6, TeaVM_Object, header) = (TEAVM_FIELD(teavm_local_6, TeaVM_Object, header) | (int32_t) INT32_C(0x80000000));
            }
            teavm_local_4 = TEAVM_ADDRESS_ADD(teavm_local_4, sizeof(void*));
            teavm_local_3 = teavm_local_5;
        }
    teavm_label_2:;
        teavm_local_2 = TEAVM_GET_NEXT_FRAME(teavm_local_2);
    }
}
void meth_otr_GC_moveNonRelocatableObjectsToOldGeneration() {
    void* teavm_local_1;
    int64_t teavm_local_2;
    int32_t teavm_local_3;
    teavm_local_1 = TEAVM_FIELD(sfld_otr_GC_currentChunkPointer, cls_otr_FreeChunkHolder, fld_value);
    teavm_local_2 = (((int64_t) (intptr_t) teavm_local_1) - ((int64_t) (intptr_t) teavm_gc_heapAddress));
    teavm_local_3 = INT32_C(0);
    while (1) {
        if (!((((int64_t) teavm_local_3) * ((int64_t) teavm_gc_regionSize)) < teavm_local_2)) break;
        if ((((int32_t) *(int8_t*) TEAVM_ADDRESS_ADD(teavm_gc_cardTable, teavm_local_3)) & INT32_C(2))) {
            meth_otr_GC_moveObjectsToOldGenerationInRegion(teavm_local_3, teavm_local_1);
        }
        teavm_local_3 = (teavm_local_3 + INT32_C(1));
    }
}
void meth_otr_GC_moveObjectsToOldGenerationInRegion(int32_t teavm_local_1, void* teavm_local_2) {
    int32_t teavm_local_3;
    int32_t teavm_local_4;
    void* teavm_local_5;
    void* teavm_local_6;
    void* teavm_local_7;
    int32_t teavm_local_8;
    int32_t teavm_local_9;
    teavm_local_3 = (TEAVM_FIELD(TEAVM_STRUCTURE_ADD(cls_otr_GC_Region, teavm_gc_regionsAddress, teavm_local_1), cls_otr_GC_Region, fld_start) - INT32_C(1));
    teavm_local_4 = teavm_gc_regionSize;
    teavm_local_5 = TEAVM_ADDRESS_ADD(teavm_gc_heapAddress, (teavm_local_1 * teavm_local_4));
    teavm_local_6 = TEAVM_ADDRESS_ADD(teavm_local_5, teavm_local_4);
    teavm_local_7 = TEAVM_ADDRESS_ADD(teavm_local_5, teavm_local_3);
    if ((!((uintptr_t) teavm_local_2 < (uintptr_t) teavm_local_6))) {
        teavm_local_2 = teavm_local_6;
    }
    while (1) {
        if (!((uintptr_t) teavm_local_7 < (uintptr_t) teavm_local_2)) break;
        teavm_local_8 = TEAVM_FIELD(teavm_local_7, cls_otr_FreeChunk, fld_classReference);
        if ((teavm_local_8 && (!(teavm_local_8 & INT32_C(1073741824))))) {
            TEAVM_FIELD(teavm_local_7, cls_otr_FreeChunk, fld_classReference) = (teavm_local_8 | INT32_C(1073741824));
        }
        teavm_local_9 = meth_otr_GC_objectSize(teavm_local_7);
        teavm_local_7 = TEAVM_ADDRESS_ADD(teavm_local_7, teavm_local_9);
    }
}
void meth_otr_GC_calculateRelocationTargets() {
    void* teavm_local_1;
    void* teavm_local_2;
    int32_t teavm_local_3;
    void* teavm_local_4;
    void* teavm_local_5;
    void* teavm_local_6;
    void* teavm_local_7;
    int32_t teavm_local_8;
    void* teavm_local_9;
    void* teavm_local_10;
    void* teavm_local_11;
    int32_t teavm_local_12;
    int32_t teavm_local_13;
    void* teavm_local_14;
    int32_t teavm_local_15;
    void* teavm_local_16;
    void* teavm_local_17;
    void* teavm_local_18;
    int64_t teavm_local_19;
    int32_t teavm_local_20;
    void* teavm_local_21;
    int32_t teavm_local_22;
    int32_t teavm_local_23;
    int32_t teavm_local_24;
    teavm_local_1 = TEAVM_ADDRESS_ADD(teavm_gc_heapAddress, teavm_gc_availableBytes);
    teavm_local_2 = sfld_otr_GC_currentChunkPointer;
    teavm_local_3 = sfld_otr_GC_freeChunks;
    teavm_local_4 = TEAVM_FIELD(teavm_local_2, cls_otr_FreeChunkHolder, fld_value);
    teavm_local_5 = TEAVM_ADDRESS_ADD(teavm_local_4, TEAVM_FIELD(teavm_local_4, cls_otr_FreeChunk, fld_size));
    teavm_local_6 = TEAVM_STRUCTURE_ADD(cls_otr_FreeChunkHolder, sfld_otr_GC_currentChunkPointer, teavm_local_3);
    teavm_local_7 = teavm_local_4;
    TEAVM_FIELD(teavm_local_6, cls_otr_RelocationBlock, fld_start) = teavm_local_7;
    TEAVM_FIELD(teavm_local_6, cls_otr_RelocationBlock, fld_end) = teavm_local_1;
    TEAVM_FIELD(teavm_local_6, cls_otr_RelocationBlock, fld_count) = INT32_C(0);
    teavm_local_8 = INT32_C(0);
    teavm_local_9 = TEAVM_STRUCTURE_ADD(cls_otr_FreeChunk, teavm_local_4, INT32_C(1));
    teavm_local_10 = TEAVM_ADDRESS_ADD(teavm_local_4, TEAVM_FIELD(teavm_local_4, cls_otr_FreeChunk, fld_size));
    teavm_local_11 = NULL;
    sfld_otr_GC_lastChunk = teavm_gc_heapAddress;
    teavm_local_12 = INT32_C(0);
    teavm_local_4 = teavm_local_6;
    while (1) {
        if (!((uintptr_t) teavm_local_5 < (uintptr_t) teavm_local_1)) break;
        teavm_local_13 = meth_otr_GC_objectSize(teavm_local_5);
        if ((!TEAVM_FIELD(teavm_local_5, cls_otr_FreeChunk, fld_classReference))) {
            teavm_local_12 = INT32_C(0);
        } else {
            teavm_local_14 = NULL;
            teavm_local_15 = meth_otr_GC_shouldRelocateObject(teavm_local_5);
            TEAVM_FIELD(teavm_local_5, cls_otr_FreeChunk, fld_classReference) = (TEAVM_FIELD(teavm_local_5, cls_otr_FreeChunk, fld_classReference) | INT32_C(1073741824));
            if (teavm_local_15) {
                while (1) {
                    teavm_local_14 = TEAVM_ADDRESS_ADD(teavm_local_7, teavm_local_13);
                    if ((teavm_local_14 == TEAVM_FIELD(teavm_local_4, cls_otr_RelocationBlock, fld_end))) {
                        goto teavm_label_7;
                    }
                    if (((uintptr_t) TEAVM_ADDRESS_ADD(teavm_local_14, INT32_C(7)) < (uintptr_t) TEAVM_FIELD(teavm_local_4, cls_otr_RelocationBlock, fld_end))) {
                        goto teavm_label_6;
                    }
                    teavm_local_16 = TEAVM_STRUCTURE_ADD(cls_otr_RelocationBlock, teavm_local_4, INT32_C(1));
                    if ((TEAVM_FIELD(teavm_local_16, cls_otr_RelocationBlock, fld_start) == teavm_local_5)) {
                        goto teavm_label_5;
                    }
                    TEAVM_FIELD(teavm_local_4, cls_otr_RelocationBlock, fld_count) = teavm_local_8;
                    teavm_local_8 = INT32_C(0);
                    teavm_local_7 = TEAVM_FIELD(teavm_local_16, cls_otr_RelocationBlock, fld_start);
                    teavm_local_4 = teavm_local_16;
                }
            teavm_label_7:;
                goto teavm_label_4;
            teavm_label_6:;
                goto teavm_label_4;
            teavm_label_5:;
                teavm_local_15 = INT32_C(0);
            }
        teavm_label_4:;
            if (teavm_local_15) {
                teavm_local_12 = INT32_C(0);
                while (1) {
                    if (!(!((uintptr_t) TEAVM_ADDRESS_ADD(teavm_local_9, sizeof(cls_otr_Relocation)) < (uintptr_t) teavm_local_10))) break;
                    teavm_local_3 = (teavm_local_3 + -INT32_C(1));
                    if ((!teavm_local_3)) {
                        goto teavm_label_2;
                    }
                    teavm_local_2 = TEAVM_STRUCTURE_ADD(cls_otr_FreeChunkHolder, teavm_local_2, INT32_C(1));
                    teavm_local_17 = TEAVM_FIELD(teavm_local_2, cls_otr_FreeChunkHolder, fld_value);
                    teavm_local_9 = TEAVM_STRUCTURE_ADD(cls_otr_FreeChunk, teavm_local_17, INT32_C(1));
                    teavm_local_10 = TEAVM_ADDRESS_ADD(teavm_local_17, TEAVM_FIELD(teavm_local_17, cls_otr_FreeChunk, fld_size));
                }
                teavm_local_18 = teavm_local_9;
                TEAVM_FIELD(teavm_local_18, cls_otr_Relocation, fld_classBackup) = TEAVM_FIELD(teavm_local_5, cls_otr_FreeChunk, fld_classReference);
                TEAVM_FIELD(teavm_local_18, cls_otr_Relocation, fld_sizeBackup) = TEAVM_FIELD(teavm_local_5, cls_otr_FreeChunk, fld_size);
                TEAVM_FIELD(teavm_local_18, cls_otr_Relocation, fld_newAddress) = teavm_local_7;
                teavm_local_8 = (teavm_local_8 + INT32_C(1));
                teavm_local_9 = TEAVM_ADDRESS_ADD(teavm_local_9, sizeof(cls_otr_Relocation));
                teavm_local_19 = ((int64_t) (intptr_t) teavm_local_18);
                TEAVM_FIELD(teavm_local_5, cls_otr_FreeChunk, fld_classReference) = (((int32_t) ((int64_t) ((uint64_t) teavm_local_19 >> INT32_C(33)))) | (int32_t) INT32_C(0x80000000));
                TEAVM_FIELD(teavm_local_5, cls_otr_FreeChunk, fld_size) = ((int32_t) (teavm_local_19 >> INT32_C(1)));
                teavm_local_20 = ((int32_t) ((((int64_t) (intptr_t) teavm_local_5) - ((int64_t) (intptr_t) teavm_gc_heapAddress)) / ((int64_t) teavm_gc_regionSize)));
                teavm_local_21 = TEAVM_ADDRESS_ADD(teavm_gc_cardTable, teavm_local_20);
                (*(int8_t*) teavm_local_21 = (int8_t) TEAVM_TO_BYTE((((int32_t) *(int8_t*) teavm_local_21) | INT32_C(8))));
                teavm_local_7 = teavm_local_14;
            } else {
                if ((!teavm_local_12)) {
                    TEAVM_FIELD(teavm_local_6, cls_otr_RelocationBlock, fld_end) = teavm_local_5;
                    teavm_local_6 = TEAVM_STRUCTURE_ADD(cls_otr_RelocationBlock, teavm_local_6, INT32_C(1));
                    TEAVM_FIELD(teavm_local_6, cls_otr_RelocationBlock, fld_end) = teavm_local_1;
                    teavm_local_12 = INT32_C(1);
                }
                if (((!sfld_otr_GC_isFullGC) && (!((uintptr_t) teavm_local_5 < (uintptr_t) teavm_local_11)))) {
                    teavm_local_20 = ((int32_t) ((((int64_t) (intptr_t) teavm_local_5) - ((int64_t) (intptr_t) teavm_gc_heapAddress)) / ((int64_t) teavm_gc_regionSize)));
                    teavm_local_11 = TEAVM_ADDRESS_ADD(teavm_gc_heapAddress, (((int64_t) teavm_gc_regionSize) * ((int64_t) (teavm_local_20 + INT32_C(1)))));
                    teavm_local_22 = ((int32_t) *(int8_t*) TEAVM_ADDRESS_ADD(teavm_gc_cardTable, teavm_local_20));
                    if (((!(teavm_local_22 & INT32_C(2))) && (!(teavm_local_22 & INT32_C(4))))) {
                        while (1) {
                            teavm_local_20 = (teavm_local_20 + INT32_C(1));
                            teavm_local_22 = ((int32_t) *(int8_t*) TEAVM_ADDRESS_ADD(teavm_gc_cardTable, teavm_local_20));
                            if ((teavm_local_22 & INT32_C(2))) {
                                goto teavm_label_9;
                            }
                            if ((teavm_local_22 & INT32_C(4))) {
                                goto teavm_label_10;
                            }
                            if ((!TEAVM_FIELD(TEAVM_STRUCTURE_ADD(cls_otr_GC_Region, teavm_gc_regionsAddress, teavm_local_20), cls_otr_GC_Region, fld_start))) {
                                goto teavm_label_11;
                            }
                        }
                    teavm_label_11:;
                        goto teavm_label_9;
                    teavm_label_10:;
                    teavm_label_9:;
                        teavm_local_22 = (teavm_local_20 + -INT32_C(1));
                        teavm_local_11 = TEAVM_ADDRESS_ADD(teavm_gc_heapAddress, (((int64_t) teavm_gc_regionSize) * ((int64_t) (teavm_local_22 + INT32_C(1)))));
                        teavm_local_23 = (TEAVM_FIELD(TEAVM_STRUCTURE_ADD(cls_otr_GC_Region, teavm_gc_regionsAddress, teavm_local_22), cls_otr_GC_Region, fld_start) - INT32_C(1));
                        teavm_local_5 = TEAVM_ADDRESS_ADD(TEAVM_ADDRESS_ADD(teavm_gc_heapAddress, (((int64_t) teavm_gc_regionSize) * ((int64_t) teavm_local_22))), teavm_local_23);
                        teavm_local_13 = meth_otr_GC_objectSize(teavm_local_5);
                    }
                }
                TEAVM_FIELD(teavm_local_6, cls_otr_RelocationBlock, fld_start) = TEAVM_ADDRESS_ADD(teavm_local_5, teavm_local_13);
                TEAVM_FIELD(teavm_local_6, cls_otr_RelocationBlock, fld_count) = INT32_C(0);
                TEAVM_FIELD(teavm_local_5, cls_otr_FreeChunk, fld_classReference) = (TEAVM_FIELD(teavm_local_5, cls_otr_FreeChunk, fld_classReference) & INT32_C(2147483647));
                sfld_otr_GC_lastChunk = teavm_local_5;
            }
        }
        teavm_local_5 = TEAVM_ADDRESS_ADD(teavm_local_5, teavm_local_13);
    }
    goto teavm_label_1;
teavm_label_2:;
    TEAVM_FIELD(teavm_local_6, cls_otr_RelocationBlock, fld_end) = teavm_local_5;
teavm_label_1:;
    TEAVM_FIELD(teavm_local_4, cls_otr_RelocationBlock, fld_count) = teavm_local_8;
    while (1) {
        if (!((uintptr_t) teavm_local_5 < (uintptr_t) teavm_local_1)) break;
        teavm_local_13 = meth_otr_GC_objectSize(teavm_local_5);
        teavm_local_24 = TEAVM_FIELD(teavm_local_5, cls_otr_FreeChunk, fld_classReference);
        if (teavm_local_24) {
            TEAVM_FIELD(teavm_local_5, cls_otr_FreeChunk, fld_classReference) = ((teavm_local_24 & INT32_C(2147483647)) | INT32_C(1073741824));
        } else {
            teavm_local_6 = TEAVM_STRUCTURE_ADD(cls_otr_RelocationBlock, teavm_local_6, INT32_C(1));
            teavm_local_17 = teavm_local_5;
            TEAVM_FIELD(teavm_local_6, cls_otr_RelocationBlock, fld_start) = teavm_local_17;
            TEAVM_FIELD(teavm_local_6, cls_otr_RelocationBlock, fld_count) = INT32_C(0);
            TEAVM_FIELD(teavm_local_6, cls_otr_RelocationBlock, fld_end) = TEAVM_ADDRESS_ADD(teavm_local_17, teavm_local_13);
        }
        teavm_local_5 = TEAVM_ADDRESS_ADD(teavm_local_5, teavm_local_13);
    }
    sfld_otr_GC_lastRelocationBlock = teavm_local_6;
}
int32_t meth_otr_GC_shouldRelocateObject(void* teavm_local_1) {
    int32_t teavm_local_2;
    int32_t teavm_local_3;
    teavm_local_2 = TEAVM_FIELD(teavm_local_1, cls_otr_FreeChunk, fld_classReference);
    if ((!(teavm_local_2 & (int32_t) INT32_C(0x80000000)))) {
        if (sfld_otr_GC_isFullGC) {
            goto teavm_label_2;
        }
        if ((!(teavm_local_2 & INT32_C(1073741824)))) {
            goto teavm_label_2;
        }
    }
    teavm_local_3 = INT32_C(0);
    goto teavm_label_1;
teavm_label_2:;
    teavm_local_3 = INT32_C(1);
teavm_label_1:;
    return teavm_local_3;
}
void meth_otr_GC_updatePointersFromStaticRoots() {
    void* teavm_local_1;
    int32_t teavm_local_2;
    int32_t teavm_local_3;
    void* teavm_local_4;
    teavm_local_1 = teavm_gc_staticRoots;
    teavm_local_2 = (*(int32_t*) teavm_local_1);
    teavm_local_1 = TEAVM_ADDRESS_ADD(teavm_local_1, sizeof(void*));
    while (1) {
        teavm_local_3 = (teavm_local_2 + -INT32_C(1));
        if ((teavm_local_2 <= INT32_C(0))) {
            goto teavm_label_1;
        }
        teavm_local_4 = (*(void**) teavm_local_1);
        (*(void**) teavm_local_4 = meth_otr_GC_updatePointer((*(void**) teavm_local_4)));
        teavm_local_1 = TEAVM_ADDRESS_ADD(teavm_local_1, sizeof(void*));
        teavm_local_2 = teavm_local_3;
    }
teavm_label_1:;
}
void meth_otr_GC_updatePointersFromClasses() {
    void* teavm_local_1;
    void* teavm_local_2;
    teavm_local_1 = teavm_firstClass;
    while (1) {
        if (!(teavm_local_1 != NULL)) break;
        teavm_local_2 = TEAVM_FIELD(teavm_local_1, TeaVM_Class, classObject);
        if ((teavm_local_2 != NULL)) {
            TEAVM_FIELD(teavm_local_1, TeaVM_Class, classObject) = meth_otr_GC_updatePointer(teavm_local_2);
        }
        teavm_local_1 = TEAVM_FIELD(teavm_local_1, TeaVM_Class, next);
    }
}
void meth_otr_GC_updatePointersFromObjects() {
    if ((!sfld_otr_GC_isFullGC)) {
        meth_otr_GC_updatePointersFromObjectsYoung();
    } else {
        meth_otr_GC_updatePointersFromObjectsFull();
    }
    meth_otr_GC_updateReferenceToFirstBuffer();
}
void meth_otr_GC_updateReferenceToFirstBuffer() {
    void* teavm_local_1;
    teavm_local_1 = sfld_otr_GC_firstDirectBuffer;
    if ((teavm_local_1 != NULL)) {
        sfld_otr_GC_firstDirectBuffer = meth_otr_GC_updatePointer(teavm_local_1);
    }
}
void meth_otr_GC_updatePointersFromObjectsFull() {
    void* teavm_local_1;
    void* teavm_local_2;
    int32_t teavm_local_3;
    int32_t teavm_local_4;
    void* teavm_local_5;
    void* teavm_local_6;
    void* teavm_local_7;
    teavm_local_1 = TEAVM_ADDRESS_ADD(teavm_gc_heapAddress, teavm_gc_availableBytes);
    teavm_local_2 = teavm_gc_heapAddress;
    while (1) {
        if (!((uintptr_t) teavm_local_2 < (uintptr_t) teavm_local_1)) break;
        teavm_local_3 = TEAVM_FIELD(teavm_local_2, cls_otr_FreeChunk, fld_classReference);
        if ((!teavm_local_3)) {
            teavm_local_4 = TEAVM_FIELD(teavm_local_2, cls_otr_FreeChunk, fld_size);
        } else {
            teavm_local_5 = meth_otr_GC_getRelocation(teavm_local_2);
            if ((teavm_local_5 != NULL)) {
                teavm_local_3 = TEAVM_FIELD(teavm_local_5, cls_otr_Relocation, fld_classBackup);
            }
            teavm_local_6 = TEAVM_UNPACK_CLASS(teavm_local_3);
            teavm_local_7 = teavm_local_2;
            meth_otr_GC_updatePointers(teavm_local_6, teavm_local_7);
            teavm_local_4 = meth_otr_GC_objectSize_0(teavm_local_7, teavm_local_6);
        }
        teavm_local_2 = TEAVM_ADDRESS_ADD(teavm_local_2, teavm_local_4);
    }
}
void meth_otr_GC_updatePointersFromObjectsYoung() {
    int32_t teavm_local_1;
    int32_t teavm_local_2;
    void* teavm_local_3;
    void* teavm_local_4;
    int32_t teavm_local_5;
    int32_t teavm_local_6;
    int32_t teavm_local_7;
    int32_t teavm_local_8;
    int32_t teavm_local_9;
    teavm_local_1 = meth_otr_GC_getRegionCount();
    teavm_local_2 = teavm_gc_regionSize;
    teavm_local_3 = teavm_gc_cardTable;
    teavm_local_4 = teavm_gc_heapAddress;
    teavm_local_5 = INT32_C(0);
    teavm_local_6 = (teavm_local_1 - INT32_C(3));
    teavm_local_2 = (INT32_C(4) * teavm_local_2);
    while (1) {
        if (!(teavm_local_5 < teavm_local_6)) break;
        teavm_local_7 = (*(int32_t*) teavm_local_3);
        if ((!(((teavm_local_7 & INT32_C(16843009)) == INT32_C(16843009)) && (!(teavm_local_7 & INT32_C(33686018)))))) {
            teavm_local_8 = INT32_C(0);
            while (1) {
                if ((teavm_local_8 >= INT32_C(4))) {
                    goto teavm_label_2;
                }
                teavm_local_9 = ((int32_t) *(int8_t*) TEAVM_ADDRESS_ADD(teavm_local_3, teavm_local_8));
                if ((!((teavm_local_9 & INT32_C(1)) && (!(teavm_local_9 & INT32_C(2)))))) {
                    meth_otr_GC_updatePointersFromRegion((teavm_local_5 + teavm_local_8));
                }
                teavm_local_8 = (teavm_local_8 + INT32_C(1));
            }
        }
    teavm_label_2:;
        teavm_local_3 = TEAVM_ADDRESS_ADD(teavm_local_3, INT32_C(4));
        teavm_local_4 = TEAVM_ADDRESS_ADD(teavm_local_4, teavm_local_2);
        teavm_local_5 = (teavm_local_5 + INT32_C(4));
    }
    while (1) {
        if (!(teavm_local_5 < teavm_local_1)) break;
        teavm_local_7 = ((int32_t) *(int8_t*) teavm_local_3);
        if ((!((teavm_local_7 & INT32_C(1)) && (!(teavm_local_7 & INT32_C(2)))))) {
            meth_otr_GC_updatePointersFromRegion(teavm_local_5);
        }
        teavm_local_3 = TEAVM_ADDRESS_ADD(teavm_local_3, INT32_C(1));
        teavm_local_5 = (teavm_local_5 + INT32_C(1));
    }
}
void meth_otr_GC_updatePointersFromRegion(int32_t teavm_local_1) {
    int32_t teavm_local_2;
    int32_t teavm_local_3;
    void* teavm_local_4;
    void* teavm_local_5;
    void* teavm_local_6;
    void* teavm_local_7;
    int32_t teavm_local_8;
    int32_t teavm_local_9;
    void* teavm_local_10;
    void* teavm_local_11;
    teavm_local_2 = (TEAVM_FIELD(TEAVM_STRUCTURE_ADD(cls_otr_GC_Region, teavm_gc_regionsAddress, teavm_local_1), cls_otr_GC_Region, fld_start) - INT32_C(1));
    if ((teavm_local_2 >= INT32_C(0))) {
        teavm_local_3 = teavm_gc_regionSize;
        teavm_local_4 = TEAVM_ADDRESS_ADD(teavm_gc_heapAddress, (teavm_local_1 * teavm_local_3));
        teavm_local_5 = TEAVM_ADDRESS_ADD(teavm_local_4, teavm_local_3);
        teavm_local_6 = TEAVM_ADDRESS_ADD(teavm_local_4, teavm_local_2);
        teavm_local_7 = TEAVM_ADDRESS_ADD(teavm_gc_heapAddress, teavm_gc_availableBytes);
        if ((!((uintptr_t) teavm_local_7 < (uintptr_t) teavm_local_5))) {
            teavm_local_7 = teavm_local_5;
        }
        while (1) {
            if (!((uintptr_t) teavm_local_6 < (uintptr_t) teavm_local_7)) break;
            teavm_local_8 = TEAVM_FIELD(teavm_local_6, cls_otr_FreeChunk, fld_classReference);
            if ((!teavm_local_8)) {
                teavm_local_9 = TEAVM_FIELD(teavm_local_6, cls_otr_FreeChunk, fld_size);
            } else {
                teavm_local_10 = meth_otr_GC_getRelocation(teavm_local_6);
                if ((teavm_local_10 != NULL)) {
                    teavm_local_8 = TEAVM_FIELD(teavm_local_10, cls_otr_Relocation, fld_classBackup);
                }
                teavm_local_11 = TEAVM_UNPACK_CLASS(teavm_local_8);
                meth_otr_GC_updatePointers(teavm_local_11, teavm_local_6);
                teavm_local_9 = meth_otr_GC_objectSize_0(teavm_local_6, teavm_local_11);
            }
            teavm_local_6 = TEAVM_ADDRESS_ADD(teavm_local_6, teavm_local_9);
        }
        return;
    }
}
void meth_otr_GC_updatePointers(void* teavm_local_1, void* teavm_local_2) {
    if ((TEAVM_FIELD(teavm_local_1, TeaVM_Class, itemType) == NULL)) {
        meth_otr_GC_updatePointersInObject(teavm_local_1, teavm_local_2);
    } else {
        meth_otr_GC_updatePointersInArray(teavm_local_1, teavm_local_2);
    }
}
void meth_otr_GC_updatePointersInObject(void* teavm_local_1, void* teavm_local_2) {
    while (1) {
        if (!(teavm_local_1 != NULL)) break;
        switch (((TEAVM_FIELD(teavm_local_1, TeaVM_Class, flags) >> INT32_C(1)) & INT32_C(7))) {
            case 1:
                goto teavm_label_4;
            case 2:
                goto teavm_label_3;
        }
        meth_otr_GC_updatePointersInFields(teavm_local_1, teavm_local_2);
        goto teavm_label_2;
    teavm_label_4:;
        meth_otr_GC_updatePointersInWeakReference(teavm_local_2);
        goto teavm_label_2;
    teavm_label_3:;
        meth_otr_GC_updatePointersInReferenceQueue(teavm_local_2);
    teavm_label_2:;
        teavm_local_1 = TEAVM_FIELD(teavm_local_1, TeaVM_Class, superclass);
    }
}
void meth_otr_GC_updatePointersInWeakReference(void* teavm_local_1) {
    TEAVM_FIELD(teavm_local_1, TeaVM_Reference, queue) = meth_otr_GC_updatePointer(TEAVM_FIELD(teavm_local_1, TeaVM_Reference, queue));
    TEAVM_FIELD(teavm_local_1, TeaVM_Reference, next) = meth_otr_GC_updatePointer(TEAVM_FIELD(teavm_local_1, TeaVM_Reference, next));
    TEAVM_FIELD(teavm_local_1, TeaVM_Reference, object) = meth_otr_GC_updatePointer(TEAVM_FIELD(teavm_local_1, TeaVM_Reference, object));
}
void meth_otr_GC_updatePointersInReferenceQueue(void* teavm_local_1) {
    TEAVM_FIELD(teavm_local_1, TeaVM_ReferenceQueue, first) = meth_otr_GC_updatePointer(TEAVM_FIELD(teavm_local_1, TeaVM_ReferenceQueue, first));
    TEAVM_FIELD(teavm_local_1, TeaVM_ReferenceQueue, last) = meth_otr_GC_updatePointer(TEAVM_FIELD(teavm_local_1, TeaVM_ReferenceQueue, last));
}
void meth_otr_GC_updatePointersInFields(void* teavm_local_1, void* teavm_local_2) {
    void* teavm_local_3;
    int32_t teavm_local_4;
    void* teavm_local_5;
    int32_t teavm_local_6;
    int32_t teavm_local_7;
    int32_t teavm_local_8;
    void* teavm_local_9;
    void* teavm_local_10;
    int64_t teavm_local_11;
    void* teavm_local_12;
    teavm_local_3 = TEAVM_FIELD(teavm_local_1, TeaVM_Class, layout);
    teavm_local_4 = -INT32_C(1);
    teavm_local_5 = TEAVM_FIELD(teavm_local_1, TeaVM_Class, enumValues);
    if (((teavm_local_5 != NULL) && (!(TEAVM_FIELD(teavm_local_1, TeaVM_Class, modifiers) & INT32_C(65536))))) {
        teavm_local_4 = ((int32_t) (intptr_t) teavm_local_5);
    }
    if ((teavm_local_3 != NULL)) {
        teavm_local_6 = ((int32_t) *(int16_t*) teavm_local_3);
        while (1) {
            teavm_local_7 = TEAVM_TO_SHORT((teavm_local_6 - INT32_C(1)));
            if ((teavm_local_6 <= INT32_C(0))) {
                goto teavm_label_1;
            }
            teavm_local_3 = TEAVM_ADDRESS_ADD(teavm_local_3, INT32_C(2));
            teavm_local_8 = ((int32_t) *(int16_t*) teavm_local_3);
            teavm_local_5 = TEAVM_ADDRESS_ADD(teavm_local_2, teavm_local_8);
            teavm_local_9 = (*(void**) teavm_local_5);
            teavm_local_10 = meth_otr_GC_updatePointer(teavm_local_9);
            (*(void**) teavm_local_5 = teavm_local_10);
            if (((teavm_local_8 == teavm_local_4) && (teavm_local_9 != NULL))) {
                teavm_local_11 = meth_oti_Address_diff(teavm_local_10, teavm_local_9);
                teavm_local_1 = TEAVM_ADDRESS_ADD(teavm_local_5, sizeof(void*));
                (*(void**) teavm_local_1 = TEAVM_ADDRESS_ADD((*(void**) teavm_local_1), teavm_local_11));
            }
            teavm_local_6 = teavm_local_7;
        }
    }
teavm_label_1:;
    if ((teavm_local_4 >= INT32_C(0))) {
        teavm_local_12 = teavm_local_2;
        TEAVM_FIELD(teavm_local_12, cls_otr_RuntimeBuffer, fld_nextRef) = meth_otr_GC_updatePointer(TEAVM_FIELD(teavm_local_12, cls_otr_RuntimeBuffer, fld_nextRef));
    }
}
void meth_otr_GC_updatePointersInArray(void* teavm_local_1, void* teavm_local_2) {
    void* teavm_local_3;
    int32_t teavm_local_4;
    int32_t teavm_local_5;
    if ((!meth_otr_RuntimeClass_isPrimitive(TEAVM_FIELD(teavm_local_1, TeaVM_Class, itemType)))) {
        teavm_local_3 = TEAVM_ALIGN(TEAVM_ADDRESS_ADD(teavm_local_2, INT32_C(1) * sizeof(TeaVM_Array)), sizeof(void*));
        teavm_local_4 = TEAVM_FIELD(teavm_local_2, TeaVM_Array, size);
        teavm_local_5 = INT32_C(0);
        while (1) {
            if (!(teavm_local_5 < teavm_local_4)) break;
            (*(void**) teavm_local_3 = meth_otr_GC_updatePointer((*(void**) teavm_local_3)));
            teavm_local_3 = TEAVM_ADDRESS_ADD(teavm_local_3, sizeof(void*));
            teavm_local_5 = (teavm_local_5 + INT32_C(1));
        }
        return;
    }
}
void meth_otr_GC_updatePointersFromStringPool() {
    teavm_stringHashtableRewind();
    while (1) {
        if (!(teavm_stringHashtableCurrent() != NULL)) break;
        teavm_stringHashtableUpdateRef(meth_otr_GC_updatePointer(teavm_stringHashtableCurrent()));
        teavm_stringHashtableNext();
    }
}
void* meth_otr_GC_updatePointer(void* teavm_local_1) {
    void* teavm_local_2;
    if ((teavm_local_1 != NULL)) {
        teavm_local_2 = meth_otr_GC_getRelocation(teavm_local_1);
        if ((teavm_local_2 != NULL)) {
            teavm_local_1 = TEAVM_FIELD(teavm_local_2, cls_otr_Relocation, fld_newAddress);
        }
        return teavm_local_1;
    }
    return NULL;
}
void* meth_otr_GC_getRelocation(void* teavm_local_1) {
    void* teavm_local_2;
    int32_t teavm_local_3;
    if (((!((uintptr_t) teavm_local_1 < (uintptr_t) teavm_gc_heapAddress)) && ((uintptr_t) teavm_local_1 < (uintptr_t) TEAVM_ADDRESS_ADD(teavm_gc_heapAddress, teavm_gc_availableBytes)))) {
        teavm_local_2 = teavm_local_1;
        teavm_local_3 = TEAVM_FIELD(teavm_local_2, cls_otr_FreeChunk, fld_classReference);
        if ((teavm_local_3 & (int32_t) INT32_C(0x80000000))) {
            return ((void*) (intptr_t) (((((int64_t) teavm_local_3) & INT64_C(4294967295)) << INT32_C(33)) | ((((int64_t) TEAVM_FIELD(teavm_local_2, cls_otr_FreeChunk, fld_size)) & INT64_C(4294967295)) << INT32_C(1))));
        }
        return NULL;
    }
    return NULL;
}
void meth_otr_GC_restoreObjectHeaders() {
    int32_t teavm_local_1;
    void* teavm_local_2;
    void* teavm_local_3;
    int32_t teavm_local_4;
    int32_t teavm_local_5;
    int32_t teavm_local_6;
    teavm_local_1 = meth_otr_GC_getRegionCount();
    teavm_local_2 = teavm_gc_cardTable;
    teavm_local_3 = TEAVM_ADDRESS_ADD(teavm_gc_heapAddress, teavm_gc_availableBytes);
    teavm_local_4 = INT32_C(0);
    teavm_local_5 = (teavm_local_1 - INT32_C(3));
    while (1) {
        if (!(teavm_local_4 < teavm_local_5)) break;
        if (((*(int32_t*) teavm_local_2) & INT32_C(134744072))) {
            teavm_local_6 = INT32_C(0);
            while (1) {
                if ((teavm_local_6 >= INT32_C(4))) {
                    goto teavm_label_2;
                }
                if ((((int32_t) *(int8_t*) TEAVM_ADDRESS_ADD(teavm_local_2, teavm_local_6)) & INT32_C(8))) {
                    meth_otr_GC_restoreObjectHeadersInRegion((teavm_local_4 + teavm_local_6), teavm_local_3);
                }
                teavm_local_6 = (teavm_local_6 + INT32_C(1));
            }
        }
    teavm_label_2:;
        teavm_local_2 = TEAVM_ADDRESS_ADD(teavm_local_2, INT32_C(4));
        teavm_local_4 = (teavm_local_4 + INT32_C(4));
    }
    while (1) {
        if (!(teavm_local_4 < teavm_local_1)) break;
        if ((((int32_t) *(int8_t*) teavm_local_2) & INT32_C(8))) {
            meth_otr_GC_restoreObjectHeadersInRegion(teavm_local_4, teavm_local_3);
        }
        teavm_local_2 = TEAVM_ADDRESS_ADD(teavm_local_2, INT32_C(1));
        teavm_local_4 = (teavm_local_4 + INT32_C(1));
    }
}
void meth_otr_GC_restoreObjectHeadersInRegion(int32_t teavm_local_1, void* teavm_local_2) {
    int32_t teavm_local_3;
    int32_t teavm_local_4;
    void* teavm_local_5;
    void* teavm_local_6;
    void* teavm_local_7;
    teavm_local_3 = (TEAVM_FIELD(TEAVM_STRUCTURE_ADD(cls_otr_GC_Region, teavm_gc_regionsAddress, teavm_local_1), cls_otr_GC_Region, fld_start) - INT32_C(1));
    teavm_local_4 = teavm_gc_regionSize;
    teavm_local_5 = TEAVM_ADDRESS_ADD(teavm_gc_heapAddress, (teavm_local_1 * teavm_local_4));
    teavm_local_6 = TEAVM_ADDRESS_ADD(teavm_local_5, teavm_local_4);
    teavm_local_7 = TEAVM_ADDRESS_ADD(teavm_local_5, teavm_local_3);
    if ((!((uintptr_t) teavm_local_2 < (uintptr_t) teavm_local_6))) {
        teavm_local_2 = teavm_local_6;
    }
    meth_otr_GC_restoreObjectHeadersInRange(teavm_local_7, teavm_local_2);
}
void meth_otr_GC_restoreObjectHeadersInRange(void* teavm_local_1, void* teavm_local_2) {
    void* teavm_local_3;
    int32_t teavm_local_4;
    while (1) {
        if (!((uintptr_t) teavm_local_1 < (uintptr_t) teavm_local_2)) break;
        teavm_local_3 = meth_otr_GC_getRelocation(teavm_local_1);
        if ((teavm_local_3 != NULL)) {
            TEAVM_FIELD(teavm_local_1, cls_otr_FreeChunk, fld_classReference) = (TEAVM_FIELD(teavm_local_3, cls_otr_Relocation, fld_classBackup) | (int32_t) INT32_C(0x80000000));
            TEAVM_FIELD(teavm_local_1, cls_otr_FreeChunk, fld_size) = TEAVM_FIELD(teavm_local_3, cls_otr_Relocation, fld_sizeBackup);
        }
        teavm_local_4 = meth_otr_GC_objectSize(teavm_local_1);
        teavm_local_1 = TEAVM_ADDRESS_ADD(teavm_local_1, teavm_local_4);
    }
}
void meth_otr_GC_relocateObjects() {
    void* teavm_local_1;
    int32_t teavm_local_2;
    void* teavm_local_3;
    void* teavm_local_4;
    void* teavm_local_5;
    int32_t teavm_local_6;
    void* teavm_local_7;
    void* teavm_local_8;
    void* teavm_local_9;
    int32_t teavm_local_10;
    void* teavm_local_11;
    int32_t teavm_local_12;
    int32_t teavm_local_13;
    int32_t teavm_local_14;
    int32_t teavm_local_15;
    int32_t teavm_local_16;
    teavm_local_1 = TEAVM_ADDRESS_ADD(teavm_gc_heapAddress, teavm_gc_availableBytes);
    teavm_local_2 = sfld_otr_GC_freeChunks;
    teavm_local_3 = TEAVM_FIELD(sfld_otr_GC_currentChunkPointer, cls_otr_FreeChunkHolder, fld_value);
    teavm_local_4 = TEAVM_ADDRESS_ADD(teavm_local_3, TEAVM_FIELD(teavm_local_3, cls_otr_FreeChunk, fld_size));
    teavm_local_5 = TEAVM_STRUCTURE_ADD(cls_otr_FreeChunkHolder, sfld_otr_GC_currentChunkPointer, teavm_local_2);
    teavm_local_6 = TEAVM_FIELD(teavm_local_5, cls_otr_RelocationBlock, fld_count);
    teavm_local_7 = TEAVM_FIELD(teavm_local_5, cls_otr_RelocationBlock, fld_start);
    teavm_local_8 = NULL;
    teavm_local_9 = NULL;
    teavm_local_10 = INT32_C(0);
    teavm_local_11 = NULL;
    teavm_local_12 = meth_otr_GC_getRegionCount();
    while (1) {
        if (!((uintptr_t) teavm_local_4 < (uintptr_t) teavm_local_1)) break;
        teavm_local_13 = meth_otr_GC_objectSize(teavm_local_4);
        teavm_local_14 = TEAVM_FIELD(teavm_local_4, cls_otr_FreeChunk, fld_classReference);
        if ((teavm_local_14 & (int32_t) INT32_C(0x80000000))) {
            TEAVM_FIELD(teavm_local_4, cls_otr_FreeChunk, fld_classReference) = (teavm_local_14 & INT32_C(2147483647));
            while (1) {
                if (!(!teavm_local_6)) break;
                if (teavm_local_10) {
                    meth_otr_GC_moveMemoryBlock(teavm_local_9, teavm_local_8, teavm_local_10);
                    teavm_local_9 = NULL;
                    teavm_local_10 = INT32_C(0);
                }
                TEAVM_FIELD(teavm_local_5, cls_otr_RelocationBlock, fld_start) = teavm_local_7;
                teavm_local_5 = TEAVM_STRUCTURE_ADD(cls_otr_RelocationBlock, teavm_local_5, INT32_C(1));
                teavm_local_6 = TEAVM_FIELD(teavm_local_5, cls_otr_RelocationBlock, fld_count);
                teavm_local_7 = TEAVM_FIELD(teavm_local_5, cls_otr_RelocationBlock, fld_start);
            }
            if ((teavm_local_9 == NULL)) {
                teavm_local_9 = teavm_local_4;
                teavm_local_8 = teavm_local_7;
            }
            teavm_local_7 = TEAVM_ADDRESS_ADD(teavm_local_7, teavm_local_13);
            teavm_local_10 = (teavm_local_10 + teavm_local_13);
            teavm_local_6 = (teavm_local_6 + -INT32_C(1));
        } else {
            if ((teavm_local_9 != NULL)) {
                meth_otr_GC_moveMemoryBlock(teavm_local_9, teavm_local_8, teavm_local_10);
                teavm_local_9 = NULL;
                teavm_local_10 = INT32_C(0);
            }
            if ((TEAVM_FIELD(teavm_local_4, cls_otr_FreeChunk, fld_classReference) && (!((uintptr_t) teavm_local_4 < (uintptr_t) teavm_local_11)))) {
                teavm_local_15 = ((int32_t) ((((int64_t) (intptr_t) teavm_local_4) - ((int64_t) (intptr_t) teavm_gc_heapAddress)) / ((int64_t) teavm_gc_regionSize)));
                teavm_local_11 = TEAVM_ADDRESS_ADD(teavm_gc_heapAddress, (((int64_t) teavm_gc_regionSize) * ((int64_t) (teavm_local_15 + INT32_C(1)))));
                teavm_local_14 = ((int32_t) *(int8_t*) TEAVM_ADDRESS_ADD(teavm_gc_cardTable, teavm_local_15));
                if (((!(teavm_local_14 & INT32_C(8))) && (!(teavm_local_14 & INT32_C(4))))) {
                    while (1) {
                        teavm_local_15 = (teavm_local_15 + INT32_C(1));
                        if ((teavm_local_15 >= teavm_local_12)) {
                            goto teavm_label_3;
                        }
                        teavm_local_16 = ((int32_t) *(int8_t*) TEAVM_ADDRESS_ADD(teavm_gc_cardTable, teavm_local_15));
                        if ((teavm_local_16 & INT32_C(8))) {
                            goto teavm_label_3;
                        }
                        if ((teavm_local_16 & INT32_C(4))) {
                            goto teavm_label_4;
                        }
                        if ((!TEAVM_FIELD(TEAVM_STRUCTURE_ADD(cls_otr_GC_Region, teavm_gc_regionsAddress, teavm_local_15), cls_otr_GC_Region, fld_start))) {
                            goto teavm_label_5;
                        }
                    }
                teavm_label_5:;
                    goto teavm_label_3;
                teavm_label_4:;
                teavm_label_3:;
                    teavm_local_15 = (teavm_local_15 + -INT32_C(1));
                    teavm_local_11 = TEAVM_ADDRESS_ADD(teavm_gc_heapAddress, (((int64_t) teavm_gc_regionSize) * ((int64_t) (teavm_local_15 + INT32_C(1)))));
                    teavm_local_16 = (TEAVM_FIELD(TEAVM_STRUCTURE_ADD(cls_otr_GC_Region, teavm_gc_regionsAddress, teavm_local_15), cls_otr_GC_Region, fld_start) - INT32_C(1));
                    teavm_local_4 = TEAVM_ADDRESS_ADD(TEAVM_ADDRESS_ADD(teavm_gc_heapAddress, (((int64_t) teavm_gc_regionSize) * ((int64_t) teavm_local_15))), teavm_local_16);
                    teavm_local_13 = meth_otr_GC_objectSize(teavm_local_4);
                }
            }
        }
        teavm_local_4 = TEAVM_ADDRESS_ADD(teavm_local_4, teavm_local_13);
    }
    TEAVM_FIELD(teavm_local_5, cls_otr_RelocationBlock, fld_start) = teavm_local_7;
    if ((teavm_local_9 != NULL)) {
        meth_otr_GC_moveMemoryBlock(teavm_local_9, teavm_local_8, teavm_local_10);
    }
}
void meth_otr_GC_moveMemoryBlock(void* teavm_local_1, void* teavm_local_2, int32_t teavm_local_3) {
    int64_t teavm_local_4;
    int32_t teavm_local_5;
    void* teavm_local_6;
    int32_t teavm_local_7;
    void* teavm_local_8;
    int32_t teavm_local_9;
    void* teavm_local_10;
    void* teavm_local_11;
    void* teavm_local_12;
    void* teavm_local_13;
    void* teavm_local_14;
    int64_t teavm_local_15;
    int32_t teavm_local_16;
    void* teavm_local_17;
    int32_t teavm_local_18;
    int32_t teavm_local_19;
    teavm_local_4 = (((int64_t) (intptr_t) teavm_local_1) - ((int64_t) (intptr_t) teavm_gc_heapAddress));
    teavm_local_5 = ((int32_t) (teavm_local_4 / ((int64_t) teavm_gc_regionSize)));
    teavm_local_6 = TEAVM_STRUCTURE_ADD(cls_otr_GC_Region, teavm_gc_regionsAddress, teavm_local_5);
    teavm_local_7 = ((int32_t) ((teavm_local_4 + ((int64_t) teavm_local_3)) / ((int64_t) teavm_gc_regionSize)));
    teavm_local_8 = TEAVM_STRUCTURE_ADD(cls_otr_GC_Region, teavm_gc_regionsAddress, teavm_local_7);
    if (((teavm_local_6 != teavm_local_8) && (((teavm_local_4 % ((int64_t) teavm_gc_regionSize)) + INT64_C(1)) == ((int64_t) TEAVM_FIELD(teavm_local_6, cls_otr_GC_Region, fld_start))))) {
        TEAVM_FIELD(teavm_local_6, cls_otr_GC_Region, fld_start) = INT32_C(0);
    }
    teavm_local_9 = (teavm_local_5 + INT32_C(1));
    while (1) {
        if (!(teavm_local_9 < teavm_local_7)) break;
        TEAVM_FIELD(TEAVM_STRUCTURE_ADD(cls_otr_GC_Region, teavm_gc_regionsAddress, teavm_local_9), cls_otr_GC_Region, fld_start) = INT32_C(0);
        teavm_local_9 = (teavm_local_9 + INT32_C(1));
    }
    if ((!((teavm_local_6 == teavm_local_8) && (((teavm_local_4 % ((int64_t) teavm_gc_regionSize)) + INT64_C(1)) != ((int64_t) TEAVM_FIELD(teavm_local_6, cls_otr_GC_Region, fld_start)))))) {
        teavm_local_10 = TEAVM_ADDRESS_ADD(teavm_gc_heapAddress, teavm_gc_availableBytes);
        teavm_local_11 = TEAVM_ADDRESS_ADD(teavm_local_1, teavm_local_3);
        if ((!((uintptr_t) teavm_local_11 < (uintptr_t) teavm_local_10))) {
            TEAVM_FIELD(teavm_local_8, cls_otr_GC_Region, fld_start) = INT32_C(0);
        } else {
            if (TEAVM_FIELD(teavm_local_11, cls_otr_FreeChunk, fld_classReference)) {
                teavm_local_5 = teavm_local_7;
            } else {
                teavm_local_11 = TEAVM_ADDRESS_ADD(teavm_local_11, TEAVM_FIELD(teavm_local_11, cls_otr_FreeChunk, fld_size));
                teavm_local_5 = ((int32_t) ((((int64_t) (intptr_t) teavm_local_11) - ((int64_t) (intptr_t) teavm_gc_heapAddress)) / ((int64_t) teavm_gc_regionSize)));
            }
            if ((!((teavm_local_5 == teavm_local_7) && ((uintptr_t) teavm_local_11 < (uintptr_t) teavm_local_10)))) {
                TEAVM_FIELD(teavm_local_8, cls_otr_GC_Region, fld_start) = INT32_C(0);
            } else {
                TEAVM_FIELD(teavm_local_8, cls_otr_GC_Region, fld_start) = TEAVM_TO_SHORT(((int32_t) (((((int64_t) (intptr_t) teavm_local_11) - ((int64_t) (intptr_t) teavm_gc_heapAddress)) % ((int64_t) teavm_gc_regionSize)) + INT64_C(1))));
            }
        }
    }
    memmove(teavm_local_2, teavm_local_1, teavm_local_3);
    teavm_local_12 = teavm_local_2;
    teavm_local_13 = TEAVM_ADDRESS_ADD(teavm_local_2, teavm_local_3);
    teavm_local_14 = NULL;
    while (1) {
        if (!((uintptr_t) teavm_local_12 < (uintptr_t) teavm_local_13)) break;
        if ((!((uintptr_t) teavm_local_12 < (uintptr_t) teavm_local_14))) {
            teavm_local_15 = (((int64_t) (intptr_t) teavm_local_12) - ((int64_t) (intptr_t) teavm_gc_heapAddress));
            teavm_local_16 = ((int32_t) (teavm_local_15 / ((int64_t) teavm_gc_regionSize)));
            teavm_local_14 = TEAVM_ADDRESS_ADD(teavm_gc_heapAddress, (((int64_t) teavm_gc_regionSize) * ((int64_t) (teavm_local_16 + INT32_C(1)))));
            teavm_local_17 = TEAVM_STRUCTURE_ADD(cls_otr_GC_Region, teavm_gc_regionsAddress, teavm_local_16);
            teavm_local_18 = ((int32_t) (teavm_local_15 % ((int64_t) teavm_gc_regionSize)));
            teavm_local_5 = TEAVM_FIELD(teavm_local_17, cls_otr_GC_Region, fld_start);
            if ((!(teavm_local_5 && ((teavm_local_5 - INT32_C(1)) <= teavm_local_18)))) {
                TEAVM_FIELD(teavm_local_17, cls_otr_GC_Region, fld_start) = TEAVM_TO_SHORT((teavm_local_18 + INT32_C(1)));
            }
        }
        teavm_local_19 = meth_otr_GC_objectSize(teavm_local_12);
        teavm_local_12 = TEAVM_ADDRESS_ADD(teavm_local_12, teavm_local_19);
    }
    teavm_gc_move(teavm_local_1, teavm_local_2, teavm_local_3);
}
void meth_otr_GC_putNewFreeChunks() {
    void* teavm_local_1;
    void* teavm_local_2;
    void* teavm_local_3;
    teavm_local_1 = sfld_otr_GC_currentChunkPointer;
    teavm_local_2 = TEAVM_STRUCTURE_ADD(cls_otr_FreeChunkHolder, teavm_local_1, sfld_otr_GC_freeChunks);
    sfld_otr_GC_freeChunks = INT32_C(0);
    while (1) {
        if (!(!((uintptr_t) sfld_otr_GC_lastRelocationBlock < (uintptr_t) teavm_local_2))) break;
        if (((uintptr_t) TEAVM_FIELD(teavm_local_2, cls_otr_RelocationBlock, fld_start) < (uintptr_t) TEAVM_FIELD(teavm_local_2, cls_otr_RelocationBlock, fld_end))) {
            teavm_local_3 = TEAVM_FIELD(teavm_local_2, cls_otr_RelocationBlock, fld_start);
            if ((!((uintptr_t) teavm_local_3 < (uintptr_t) sfld_otr_GC_lastChunk))) {
                sfld_otr_GC_lastChunk = teavm_local_3;
            }
            TEAVM_FIELD(teavm_local_3, cls_otr_FreeChunk, fld_size) = ((int32_t) (((int64_t) (intptr_t) TEAVM_FIELD(teavm_local_2, cls_otr_RelocationBlock, fld_end)) - ((int64_t) (intptr_t) TEAVM_FIELD(teavm_local_2, cls_otr_RelocationBlock, fld_start))));
            TEAVM_FIELD(teavm_local_3, cls_otr_FreeChunk, fld_classReference) = INT32_C(0);
            teavm_gc_assertFree(teavm_local_3, TEAVM_FIELD(teavm_local_3, cls_otr_FreeChunk, fld_size));
            TEAVM_FIELD(teavm_local_1, cls_otr_FreeChunkHolder, fld_value) = teavm_local_3;
            teavm_local_1 = TEAVM_STRUCTURE_ADD(cls_otr_FreeChunkHolder, teavm_local_1, INT32_C(1));
            sfld_otr_GC_freeChunks = (sfld_otr_GC_freeChunks + INT32_C(1));
        }
        teavm_local_2 = TEAVM_STRUCTURE_ADD(cls_otr_RelocationBlock, teavm_local_2, INT32_C(1));
    }
    sfld_otr_GC_totalChunks = sfld_otr_GC_freeChunks;
}
void meth_otr_GC_updateFreeMemory() {
    void* teavm_local_1;
    int32_t teavm_local_2;
    sfld_otr_GC_freeMemory = INT32_C(0);
    teavm_local_1 = sfld_otr_GC_currentChunkPointer;
    teavm_local_2 = INT32_C(0);
    while (1) {
        if (!(teavm_local_2 < sfld_otr_GC_freeChunks)) break;
        sfld_otr_GC_freeMemory = (sfld_otr_GC_freeMemory + TEAVM_FIELD(TEAVM_FIELD(teavm_local_1, cls_otr_FreeChunkHolder, fld_value), cls_otr_FreeChunk, fld_size));
        teavm_local_1 = TEAVM_STRUCTURE_ADD(cls_otr_FreeChunkHolder, teavm_local_1, INT32_C(1));
        teavm_local_2 = (teavm_local_2 + INT32_C(1));
    }
}
void meth_otr_GC_resizeHeapConsistent(int64_t teavm_local_1) {
    int64_t teavm_local_2;
    int32_t teavm_local_3;
    int32_t teavm_local_4;
    void* teavm_local_5;
    int32_t teavm_local_6;
    int64_t teavm_local_7;
    teavm_local_2 = teavm_gc_availableBytes;
    teavm_local_3 = teavm_compare_i64(teavm_local_1, teavm_local_2);
    if (teavm_local_3) {
        if ((teavm_local_3 > INT32_C(0))) {
            teavm_local_3 = meth_otr_GC_getRegionCount();
            teavm_gc_resizeHeap(teavm_local_1);
            sfld_otr_GC_currentChunkPointer = teavm_gc_gcStorageAddress;
            teavm_local_4 = meth_otr_GC_getRegionCount();
            while (1) {
                if (!(teavm_local_3 < teavm_local_4)) break;
                TEAVM_FIELD(TEAVM_STRUCTURE_ADD(cls_otr_GC_Region, teavm_gc_regionsAddress, teavm_local_3), cls_otr_GC_Region, fld_start) = INT32_C(0);
                teavm_local_3 = (teavm_local_3 + INT32_C(1));
            }
            teavm_local_5 = sfld_otr_GC_lastChunk;
            if ((!TEAVM_FIELD(teavm_local_5, cls_otr_FreeChunk, fld_classReference))) {
                TEAVM_FIELD(teavm_local_5, cls_otr_FreeChunk, fld_size) = (TEAVM_FIELD(teavm_local_5, cls_otr_FreeChunk, fld_size) + ((int32_t) (teavm_local_1 - teavm_local_2)));
            } else {
                teavm_local_6 = meth_otr_GC_objectSize(teavm_local_5);
                teavm_local_5 = TEAVM_ADDRESS_ADD(sfld_otr_GC_lastChunk, teavm_local_6);
                sfld_otr_GC_lastChunk = teavm_local_5;
                TEAVM_FIELD(teavm_local_5, cls_otr_FreeChunk, fld_classReference) = INT32_C(0);
                TEAVM_FIELD(teavm_local_5, cls_otr_FreeChunk, fld_size) = ((int32_t) (teavm_local_1 - teavm_local_2));
                TEAVM_FIELD(TEAVM_STRUCTURE_ADD(cls_otr_FreeChunkHolder, sfld_otr_GC_currentChunkPointer, sfld_otr_GC_freeChunks), cls_otr_FreeChunkHolder, fld_value) = sfld_otr_GC_lastChunk;
                sfld_otr_GC_freeChunks = (sfld_otr_GC_freeChunks + INT32_C(1));
                sfld_otr_GC_totalChunks = (sfld_otr_GC_totalChunks + INT32_C(1));
            }
        } else if (1) {
            teavm_local_7 = (((int64_t) (intptr_t) sfld_otr_GC_lastChunk) - ((int64_t) (intptr_t) teavm_gc_heapAddress));
            teavm_local_5 = sfld_otr_GC_lastChunk;
            if (TEAVM_FIELD(teavm_local_5, cls_otr_FreeChunk, fld_classReference)) {
                teavm_local_7 = (teavm_local_7 + ((int64_t) meth_otr_GC_objectSize(teavm_local_5)));
            }
            if ((teavm_local_1 < teavm_local_7)) {
                if ((teavm_local_7 != teavm_local_2)) {
                    teavm_local_1 = teavm_local_7;
                } else {
                    return;
                }
            }
            if ((teavm_local_1 != teavm_local_7)) {
                teavm_local_5 = sfld_otr_GC_lastChunk;
                TEAVM_FIELD(teavm_local_5, cls_otr_FreeChunk, fld_size) = (TEAVM_FIELD(teavm_local_5, cls_otr_FreeChunk, fld_size) - ((int32_t) (teavm_local_2 - teavm_local_1)));
            } else {
                sfld_otr_GC_freeChunks = (sfld_otr_GC_freeChunks - INT32_C(1));
                sfld_otr_GC_totalChunks = (sfld_otr_GC_totalChunks - INT32_C(1));
            }
            teavm_gc_resizeHeap(teavm_local_1);
            sfld_otr_GC_currentChunkPointer = teavm_gc_gcStorageAddress;
        }
        return;
    }
}
void meth_otr_GC_resizeHeapIfNecessary(int64_t teavm_local_1) {
    int64_t teavm_local_2;
    int64_t teavm_local_3;
    teavm_local_2 = teavm_gc_availableBytes;
    teavm_local_3 = (teavm_local_2 - ((int64_t) sfld_otr_GC_freeMemory));
    if (meth_otr_GC_isAboutToExpand(teavm_local_1)) {
        teavm_local_1 = meth_otr_GC_min(meth_otr_GC_max(teavm_local_1, ((teavm_local_2 - ((int64_t) sfld_otr_GC_freeMemory)) * INT64_C(2))), teavm_gc_maxAvailableBytes);
        if ((teavm_local_1 != teavm_local_2)) {
            teavm_local_2 = (teavm_local_1 % INT64_C(8));
            if ((teavm_local_2 != INT64_C(0))) {
                teavm_local_1 = (teavm_local_1 + (INT64_C(8) - teavm_local_2));
            }
            meth_otr_GC_resizeHeapConsistent(teavm_local_1);
        }
    } else if ((teavm_local_3 < (teavm_local_2 / INT64_C(4)))) {
        teavm_local_1 = meth_otr_GC_max((teavm_local_3 * INT64_C(3)), teavm_gc_minAvailableBytes);
        teavm_local_2 = (teavm_local_1 % INT64_C(8));
        if ((teavm_local_2 != INT64_C(0))) {
            teavm_local_1 = (teavm_local_1 - teavm_local_2);
        }
        meth_otr_GC_resizeHeapConsistent(teavm_local_1);
    }
}
int32_t meth_otr_GC_isAboutToExpand(int64_t teavm_local_1) {
    int64_t teavm_local_2;
    int64_t teavm_local_3;
    teavm_local_2 = teavm_gc_availableBytes;
    teavm_local_3 = (teavm_local_2 - ((int64_t) sfld_otr_GC_freeMemory));
    return ((!((teavm_local_1 <= teavm_local_2) && (teavm_local_3 <= (teavm_local_2 / INT64_C(2))))) ? INT32_C(1) : INT32_C(0));
}
int64_t meth_otr_GC_min(int64_t teavm_local_1, int64_t teavm_local_2) {
    if ((teavm_local_1 < teavm_local_2)) {
        teavm_local_2 = teavm_local_1;
    }
    return teavm_local_2;
}
int64_t meth_otr_GC_max(int64_t teavm_local_1, int64_t teavm_local_2) {
    if ((teavm_local_1 > teavm_local_2)) {
        teavm_local_2 = teavm_local_1;
    }
    return teavm_local_2;
}
int32_t meth_otr_GC_objectSize(void* teavm_local_1) {
    void* teavm_local_2;
    if (TEAVM_FIELD(teavm_local_1, cls_otr_FreeChunk, fld_classReference)) {
        teavm_local_2 = teavm_local_1;
        return meth_otr_GC_objectSize_0(teavm_local_2, meth_otr_RuntimeClass_getClass(teavm_local_2));
    }
    return TEAVM_FIELD(teavm_local_1, cls_otr_FreeChunk, fld_size);
}
int32_t meth_otr_GC_objectSize_0(void* teavm_local_1, void* teavm_local_2) {
    void* teavm_local_3;
    int32_t teavm_local_4;
    teavm_local_3 = TEAVM_FIELD(teavm_local_2, TeaVM_Class, itemType);
    if ((teavm_local_3 != NULL)) {
        teavm_local_4 = ((!meth_otr_RuntimeClass_isPrimitive(teavm_local_3)) ? sizeof(void*) : TEAVM_FIELD(TEAVM_FIELD(teavm_local_2, TeaVM_Class, itemType), TeaVM_Class, size));
        teavm_local_3 = teavm_local_1;
        return ((int32_t) (intptr_t) TEAVM_ALIGN(TEAVM_ADDRESS_ADD(TEAVM_ALIGN(((void*) (intptr_t) sizeof(TeaVM_Array)), teavm_local_4), (teavm_local_4 * TEAVM_FIELD(teavm_local_3, TeaVM_Array, size))), sizeof(void*)));
    }
    return TEAVM_FIELD(teavm_local_2, TeaVM_Class, size);
}
int32_t meth_otr_GC_isMarked(void* teavm_local_1) {
    int32_t teavm_local_2;
    int32_t teavm_local_3;
    teavm_local_2 = TEAVM_FIELD(teavm_local_1, TeaVM_Object, header);
    if ((!(teavm_local_2 & (int32_t) INT32_C(0x80000000)))) {
        if (sfld_otr_GC_isFullGC) {
            goto teavm_label_2;
        }
        if ((!(teavm_local_2 & INT32_C(1073741824)))) {
            goto teavm_label_2;
        }
    }
    teavm_local_3 = INT32_C(1);
    goto teavm_label_1;
teavm_label_2:;
    teavm_local_3 = INT32_C(0);
teavm_label_1:;
    return teavm_local_3;
}
void meth_otr_GC_free(void* teavm_local_1) {
    free(teavm_local_1);
}
void meth_otr_GC__clinit_() {
    void* teavm_local_1;
    int32_t teavm_local_2;
    sfld_otr_GC_freeMemory = ((int32_t) teavm_gc_availableBytes);
    sfld_otr_GC_isFullGC = INT32_C(1);
    teavm_local_1 = teavm_gc_heapAddress;
    sfld_otr_GC_currentChunk = teavm_local_1;
    TEAVM_FIELD(teavm_local_1, cls_otr_FreeChunk, fld_classReference) = INT32_C(0);
    TEAVM_FIELD(teavm_local_1, cls_otr_FreeChunk, fld_size) = ((int32_t) teavm_gc_availableBytes);
    sfld_otr_GC_currentChunkLimit = TEAVM_ADDRESS_ADD(sfld_otr_GC_currentChunk, TEAVM_FIELD(sfld_otr_GC_currentChunk, cls_otr_FreeChunk, fld_size));
    teavm_local_1 = teavm_gc_gcStorageAddress;
    sfld_otr_GC_currentChunkPointer = teavm_local_1;
    TEAVM_FIELD(teavm_local_1, cls_otr_FreeChunkHolder, fld_value) = sfld_otr_GC_currentChunk;
    sfld_otr_GC_freeChunks = INT32_C(1);
    sfld_otr_GC_totalChunks = INT32_C(1);
    sfld_otr_GC_firstDirectBuffer = NULL;
    teavm_local_2 = meth_otr_GC_getRegionCount();
    memset(teavm_gc_cardTable, INT32_C(1), teavm_local_2);
}
int32_t supertypeof_otr_GC(TeaVM_Class* supercls, TeaVM_Class* cls) {
    int32_t tag = cls->tag;
    if (tag < 45 || tag >= 47) return INT32_C(0);
    return INT32_C(1);
}
alignas(8) otr_GC_VT otr_GC_Cls = {
    .parent = {
        .parent = {
            .size = (int32_t) (intptr_t) TEAVM_ALIGN(sizeof(cls_otr_GC), sizeof(void*)),
            .flags = 0,
            .tag = 45,
            .modifiers = 17,
            .name = NULL,
            .arrayType = NULL,
            .itemType = NULL,
            .isSupertypeOf = &supertypeof_otr_GC,
            .superclass = (TeaVM_Class*) &jl_Object_Cls,
            .layout = NULL,
            .enumValues = NULL
        },
        .virt_clone = &meth_jl_Object_clone
    }
};
void sysinitclass_otr_GC() {
    sfld_otr_GC_currentChunkLimit = NULL;
    sfld_otr_GC_currentChunk = NULL;
    sfld_otr_GC_currentChunkPointer = NULL;
    sfld_otr_GC_freeChunks = INT32_C(0);
    sfld_otr_GC_totalChunks = INT32_C(0);
    sfld_otr_GC_freeMemory = INT32_C(0);
    sfld_otr_GC_firstWeakReference = NULL;
    sfld_otr_GC_lastChunk = NULL;
    sfld_otr_GC_lastRelocationBlock = NULL;
    sfld_otr_GC_isFullGC = 0;
    sfld_otr_GC_youngGCCount = INT32_C(0);
    sfld_otr_GC_firstDirectBuffer = NULL;
}
