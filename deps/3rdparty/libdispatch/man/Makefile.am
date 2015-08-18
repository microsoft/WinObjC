#
#
#

man3_MANS=				\
	dispatch.3			\
	dispatch_after.3		\
	dispatch_api.3			\
	dispatch_apply.3		\
	dispatch_async.3		\
	dispatch_benchmark.3		\
	dispatch_group_create.3		\
	dispatch_object.3		\
	dispatch_once.3			\
	dispatch_queue_create.3		\
	dispatch_semaphore_create.3	\
	dispatch_source_create.3	\
	dispatch_time.3

#
# Install man page symlinks.  Is there a better way to do this in automake?
#
install-data-hook:
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_after.3 dispatch_after_f.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_apply.3 dispatch_apply_f.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_async.3 dispatch_sync.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_async.3 dispatch_async_f.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_async.3 dispatch_sync_f.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_benchmark.3 dispatch_benchmark_f.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_group_create.3 dispatch_group_enter.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_group_create.3 dispatch_group_leave.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_group_create.3 dispatch_group_wait.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_group_create.3 dispatch_group_notify.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_group_create.3 dispatch_group_notify_f.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_group_create.3 dispatch_group_async.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_group_create.3 dispatch_group_async_f.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_object.3 dispatch_retain.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_object.3 dispatch_release.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_object.3 dispatch_suspend.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_object.3 dispatch_resume.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_object.3 dispatch_get_context.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_object.3 dispatch_set_context.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_object.3 dispatch_set_finalizer_f.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_once.3 dispatch_once_f.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_queue_create.3 dispatch_queue_get_label.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_queue_create.3 dispatch_get_current_queue.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_queue_create.3 dispatch_get_global_queue.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_queue_create.3 dispatch_get_main_queue.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_queue_create.3 dispatch_main.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_queue_create.3 dispatch_set_target_queue.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_semaphore_create.3			\
		dispatch_semaphore_signal.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_semaphore_create.3			\
		dispatch_semaphore_wait.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_source_create.3			\
		dispatch_source_set_event_handler.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_source_create.3			\
		dispatch_source_set_event_handler_f.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_source_create.3			\
		dispatch_source_set_cancel_handler.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_source_create.3			\
		dispatch_source_set_cancel_handler_f.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_source_create.3			\
		dispatch_source_cancel.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_source_create.3			\
		dispatch_source_testcancel.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_source_create.3			\
		dispatch_source_get_handle.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_source_create.3 dispatch_source_get_mask.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_source_create.3			\
		dispatch_source_get_data.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_source_create.3			\
		dispatch_source_merge_data.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_source_create.3			\
		dispatch_source_set_timer.3
	cd $(DESTDIR)$(mandir)/man3 &&					\
		$(LN_S) -f dispatch_time.3 dispatch_walltime.3

