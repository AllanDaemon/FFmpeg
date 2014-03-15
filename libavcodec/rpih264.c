/*
 * H.264 encoding using the Raspberry Pi hardware
 * Copyright (C) 2005  Mans Rullgard <mans@mansr.com>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

typedef struct OMXContext {
} OMXContext;

atic int OMX_frame(AVCodecContext *ctx, AVPacket *pkt,
        const AVFrame *frame, int *got_packet)
{
    // TODO...
}

static av_cold int OMX_close(AVCodecContext *avctx)
{
    // TODO...
}


static av_cold int OMX_init(AVCodecContext *avctx)
{
    // TODO...
}

static av_cold void OMX_init_static(AVCodec *codec)
{
    codec->pix_fmts = pix_fmts_8bit;
}

static const AVOption options[] = {
    {"bitrate", "Set the bitrate for constant bitrate", OFFSET(bitrate), AV_OPT_TYPE_INT, {0}, 0, 0, VE},
};

static const AVClass omx_class = {
    .class_name = "rpih264",
    .item_name = av_default_item_name,
    .option = options,
    .version = LIBAVUTIL_VERSION_INT,
};

AVCodec ff_rpih264_encoder = {
    .name = "rpih264",
    .long_name = NULL_IF_CONFIG_SMALL("Raspberry Pi OpenMAX hardware accelerated H.264 / AVC encoder"),
    .type = AVMEDIA_TYPE_VIDEO,
    .id = AV_CODEC_ID_H264,
    .priv_data_size = sizeof(OMXContext),
    .init             = OMX_init,
    .encode2          = OMX_frame,
    .close            = OMX_close,
    .capabilities = 0, // TODO...
    .priv_class = &omx_class,
    .defaults = 0, // TODO...
    .init_static_data = OMX_init_static,
};
