#define LIBINITMACRO	{ \
                        if (!al_init()) { \
                            printf ("The allegro5 library is missing."); \
                            return 1; \
                        } \
                        \
                        if (!al_init_primitives_addon()) { \
                            printf ("\nThe allegro_primitives library is missing."); \
                            return 1; \
                        } \
                        \
                        if (!al_init_image_addon()) { \
                            printf ("\nThe allegro_image library is missing."); \
                            return 1; \
                        } \
                        \
                        if (!al_init_acodec_addon()) { \
                            printf ("\nThe allegro_acodec library is missing."); \
                            return 1; \
                        } \
                        }

#define INSTALLMACRO    { \
                        if (!al_install_audio()) { \
                            printf ("Audio cannot be installed. Check your drivers."); \
                            return 1; \
                        } \
                        \
                        if (!al_install_keyboard()) { \
                            printf ("Keyboard cannot be installed. Check your drivers."); \
                            return 1; \
                        } \
                        \
                        if (!al_install_mouse()) { \
                            printf ("Mouse cannot be installed. Check your drivers."); \
                            return 1; \
                        } \
                        }

#define TERMINATE	{ \
                    al_destroy_display(display); \
                    \
                    al_uninstall_audio; \
                    al_uninstall_keyboard; \
                    al_uninstall_mouse; \
                    }
