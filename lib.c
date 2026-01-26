#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//#define DEBUG_IOREF(X) printf X
#define DEBUG_IOREF(X)

typedef struct {
    int refcount;   // refcount of ioref_t
    void* retained_ptr;
    void (*retain) (void*);
    void (*release) (void*);
} ioref_t;

// Prototype declarations
void _minilib_ioref_retain_ptr(ioref_t* ior);
void _minilib_ioref_release_ptr(ioref_t* ior);

// Initializes an IORef using a retained_ptr.
// If the retained_ptr is not NULL, it must be retained(+1) already.
ioref_t* minilib_ioref_init(void* retained_ptr, void (*retain) (void*), void (*release) (void*))
{
    ioref_t* ior = calloc(sizeof(ioref_t), 1);
    ior->refcount = 0;
    ior->retained_ptr = retained_ptr;
    ior->retain = retain;
    ior->release = release;
    DEBUG_IOREF(("minilib_ioref_init ior=%p retained_ptr=%p\n", ior, retained_ptr));
    return ior;
}

// Destroyes an IORef.
// If the retained_ptr is not NULL, it will be released(-1).
void minilib_ioref_destroy(ioref_t* ior)
{
    if (ior == NULL) return;

    DEBUG_IOREF(("minilib_ioref_destroy ior=%p retained_ptr=%p\n", ior, ior->retained_ptr));
    if (ior->retained_ptr != NULL && ior->release != NULL)
    {
        (*ior->release)(ior->retained_ptr);
    }
    ior->retained_ptr = NULL;
    ior->retain = NULL;
    ior->release = NULL;
    free(ior);
}

// Sets a retained_ptr.
// If the retained_ptr is not NULL, it must be retained(+1) already.
void minilib_ioref_set_retained_ptr(ioref_t* ior, void* retained_ptr)
{
    if (ior == NULL) return;

    DEBUG_IOREF(("minilib_ioref_set_retained_ptr ior=%p retained_ptr=%p\n", ior, retained_ptr));
    if (ior->retained_ptr != retained_ptr) {
        _minilib_ioref_release_ptr(ior);      // release(-1) if not NULL
        ior->retained_ptr = retained_ptr;
        //_minilib_ioref_retain_ptr(ior);     // we don't need retain (since already retained(+1) if not NULL)
    }
}

// Gets a retained_ptr.
// If the retained_ptr is not NULL, it will be retained(+1).
void* minilib_ioref_get_retained_ptr(ioref_t* ior)
{
    if (ior == NULL) return NULL;

    DEBUG_IOREF(("minilib_ioref_get_retained_ptr ior=%p retained_ptr=%p\n", ior, ior->retained_ptr));
    _minilib_ioref_retain_ptr(ior);           // retain(+1) if not NULL
    return ior->retained_ptr;
}

// Increments the refcount of ioref_t.
void minilib_ioref_ref(ioref_t* ior)
{
    if (ior == NULL) return;

    DEBUG_IOREF(("minilib_ioref_ref ior=%p refcount: %d -> %d\n", ior, ior->refcount, ior->refcount + 1));
    ior->refcount++;
}

// Decrements the refcount of ioref_t.
void minilib_ioref_unref(ioref_t* ior)
{
    if (ior == NULL) return;

    DEBUG_IOREF(("minilib_ioref_unref ior=%p refcount: %d -> %d\n", ior, ior->refcount, ior->refcount - 1));
    if (--ior->refcount <= 0) {
        minilib_ioref_destroy(ior);
    }
}

// Increments the refcount of the box referenced by `ior->retained_ptr`.
void _minilib_ioref_retain_ptr(ioref_t* ior)
{
    if (ior == NULL) return;

    DEBUG_IOREF(("_minilib_ioref_retain_ptr ior=%p retained_ptr=%p\n", ior, ior->retained_ptr));
    if (ior->retained_ptr != NULL && ior->retain != NULL)
    {
        (*ior->retain)(ior->retained_ptr);
    }
}

// Decrements the refcount of the box referenced by `ior->retained_ptr`.
void _minilib_ioref_release_ptr(ioref_t* ior)
{
    if (ior == NULL) return;

    DEBUG_IOREF(("_minilib_ioref_release_ptr ior=%p retained_ptr=%p\n", ior, ior->retained_ptr));
    if (ior->retained_ptr != NULL && ior->retain != NULL)
    {
        (*ior->release)(ior->retained_ptr);
    }
}

