
#ifndef ASYNQRO_EXPORT_H
#define ASYNQRO_EXPORT_H

#ifdef ASYNQRO_STATIC_DEFINE
#  define ASYNQRO_EXPORT
#  define ASYNQRO_NO_EXPORT
#else
#  ifndef ASYNQRO_EXPORT
#    ifdef asynqro_EXPORTS
        /* We are building this library */
#      define ASYNQRO_EXPORT 
#    else
        /* We are using this library */
#      define ASYNQRO_EXPORT 
#    endif
#  endif

#  ifndef ASYNQRO_NO_EXPORT
#    define ASYNQRO_NO_EXPORT 
#  endif
#endif

#ifndef ASYNQRO_DEPRECATED
#  define ASYNQRO_DEPRECATED __declspec(deprecated)
#endif

#ifndef ASYNQRO_DEPRECATED_EXPORT
#  define ASYNQRO_DEPRECATED_EXPORT ASYNQRO_EXPORT ASYNQRO_DEPRECATED
#endif

#ifndef ASYNQRO_DEPRECATED_NO_EXPORT
#  define ASYNQRO_DEPRECATED_NO_EXPORT ASYNQRO_NO_EXPORT ASYNQRO_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ASYNQRO_NO_DEPRECATED
#    define ASYNQRO_NO_DEPRECATED
#  endif
#endif

#endif /* ASYNQRO_EXPORT_H */
