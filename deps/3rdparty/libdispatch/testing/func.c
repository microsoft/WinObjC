extern "C" {
void
func(void)
{
}
#ifdef __BLOCKS__
void (^block)(void) = ^{ };
#endif
};
