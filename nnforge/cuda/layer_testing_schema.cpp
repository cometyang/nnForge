/*
 *  Copyright 2011-2013 Maxim Milakov
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#include "layer_testing_schema.h"

#include "neural_network_cuda_exception.h"

namespace nnforge
{
	namespace cuda
	{
		layer_testing_schema::layer_testing_schema()
		{
		}

		layer_testing_schema::~layer_testing_schema()
		{
		}

		std::tr1::shared_ptr<layer_testing_schema> layer_testing_schema::create(
			const_layer_smart_ptr layer_schema,
			cuda_running_configuration_const_smart_ptr cuda_config) const
		{
			std::tr1::shared_ptr<layer_testing_schema> res = create_specific();

			res->layer_schema = layer_schema;
			res->cuda_config = cuda_config;

			return res;
		}

		layer_tester_cuda_smart_ptr layer_testing_schema::create_tester(
			const layer_configuration_specific& input_configuration_specific,
			const layer_configuration_specific& output_configuration_specific) const
		{
			layer_tester_cuda_smart_ptr res = create_tester_specific(
				input_configuration_specific,
				output_configuration_specific);

			res->configure(
				input_configuration_specific,
				output_configuration_specific,
				layer_schema,
				cuda_config);

			return res;
		}

		std::vector<const_cuda_linear_buffer_device_smart_ptr> layer_testing_schema::get_schema_buffers() const
		{
			return std::vector<const_cuda_linear_buffer_device_smart_ptr>();
		}
	}
}
