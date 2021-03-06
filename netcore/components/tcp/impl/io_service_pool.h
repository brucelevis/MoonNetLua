/****************************************************************************

Git <https://github.com/sniper00/MoonNetLua>
E-Mail <hanyongtao@live.com>
Copyright (c) 2015-2016 moon
Licensed under the MIT License <http://opensource.org/licenses/MIT>.

****************************************************************************/
#pragma once
#include "asio.hpp"
#include "asio/steady_timer.hpp"
#include "components/tcp/network.h"

namespace moon
{
	DECLARE_SHARED_PTR(io_worker)

	class io_service_pool
	{
	public:
		using io_worker_container_t = std::vector<io_worker_ptr_t>;
		using thread_pool = std::vector<std::thread>;

		io_service_pool(uint8_t pool_size);

		void run();

		void stop();

		io_worker_ptr_t find(uint32_t sessionid);

		io_worker_ptr_t& get_io_worker();

		asio::io_service& io_service();

		void	set_network_handle(const network_handle_t& handle);

		int get_session_num();
	private:
		std::vector<io_worker_ptr_t> workers_;
		typename io_worker_container_t::iterator next_worker_;
		thread_pool thread_pool_;
	};
}
