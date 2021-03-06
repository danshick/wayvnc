/*
 * Copyright (c) 2019 - 2020 Andri Yngvason
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
 * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#pragma once

#include <time.h>
#include <stdint.h>

static inline uint64_t timespec_to_us(const struct timespec* ts)
{
	return (uint64_t)ts->tv_sec * UINT64_C(1000000) +
	       (uint64_t)ts->tv_nsec / UINT64_C(1000);
}

static inline uint64_t timespec_to_ms(const struct timespec* ts)
{
	return (uint64_t)ts->tv_sec * UINT64_C(1000) +
	       (uint64_t)ts->tv_nsec / UINT64_C(1000000);
}

static inline uint64_t gettime_us(void)
{
	struct timespec ts = { 0 };
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return timespec_to_us(&ts);
}

static inline uint64_t gettime_ms(void)
{
	struct timespec ts = { 0 };
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return timespec_to_ms(&ts);
}
